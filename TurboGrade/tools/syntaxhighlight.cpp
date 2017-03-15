#include "syntaxhighlight.h"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkCyan);
    QStringList keywordPatterns;
    keywordPatterns << "\\bclass\\b" << "\\bconst\\b"
                    << "\\bexplicit\\b" << "\\bthis\\b"
                    << "\\bfriend\\b" << "\\binline\\b"
                    << "\\bnamespace\\b" << "\\boperator\\b"
                    << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                    << "\\bsignals\\b" << "\\bsigned\\b"
                    << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                    << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                    << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                    << "\\bvolatile\\b" << "\\bimport\\b" << "\\bnull\\b";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    typeFormat.setForeground(QColor("orange"));
    QStringList typePatterns;
    typePatterns << "\\bchar\\b" << "\\bdouble\\b" << "\\bint\\b"
                 << "\\blong\\b" << "\\bshort\\b" << "\\bboolean\\b"
                 << "\\bbool\\b" << "\\bunsigned\\b" << "\\bString\\b"
                 << "\\bstring\\b" << "\\barray\\b" << "\\bchar\\b"
                 << "\\bbyte\\b"  << "\\bfloat\\b"  << "\\bvoid\\b";
    foreach (const QString &pattern, typePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = typeFormat;
        highlightingRules.append(rule);
    }

    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    controlflowFormat.setForeground(QColor(114, 161, 20));
    QStringList controlflowPatterns;
    typePatterns << "\\bswitch\\b" << "\\bcase\\b" << "\\bif\\b"
                 << "\\bbreak\\b" << "\\belse\\b" << "\\belif\\b"
                 << "\\bwhile\\b" << "\\bfor\\b" << "\\bdo\\b"
                 << "\\bthen\\b" << "\\bcontinue\\b" << "\\breturn\\b";
    foreach (const QString &pattern, controlflowPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = controlflowFormat;
        highlightingRules.append(rule);
    }

    singleLineCommentFormat.setForeground(Qt::darkGray);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::darkGray);

    quotationFormat.setForeground(QColor(125, 70, 150));
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    //    functionFormat.setFontItalic(true);
    functionFormat.setForeground(QColor(0, 100, 150));
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

void SyntaxHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}
