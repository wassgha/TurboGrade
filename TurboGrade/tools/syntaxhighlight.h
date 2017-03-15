#ifndef SYNTAXHIGHLIGHT_H
#define SYNTAXHIGHLIGHT_H

/**
 * @brief SyntaxHighlighter is used to format
 * code blocks used in the code editor.
 *
 * Original source obtained from Qt Examples,
 * modified as needed.
 */

#include <QSyntaxHighlighter>
#include <QTextCharFormat>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    SyntaxHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
    QTextCharFormat typeFormat;
    QTextCharFormat controlflowFormat;
};

#endif // SYNTAXHIGHLIGHT_H
