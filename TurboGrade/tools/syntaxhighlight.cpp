/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "syntaxhighlight.h"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{

    /* Processing Theme
     * keyword : Qt::darkCyan
     * function : QColor(0, 100, 150)
     * comment : QtDarkGray
     * control flow : QColor(114, 161, 20)
     * quotation: QColor(125, 70, 150)
     *
     *
     *
     *
     * Dark Theme :
     * keyword : #bf5d69
     * function : #eccd88
     * comment : QtLightGray
     * control flow : QColor("#8fa0b4")
     * quotation: QColor("#53d86f")
     *
     *
     *
     */
    HighlightingRule rule;

    keywordFormat.setForeground(QColor("#c57bdb"));
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
    classFormat.setForeground(QColor("#ce6770"));
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    controlflowFormat.setForeground(QColor("#c57bdb"));
    QStringList controlflowPatterns;
    controlflowPatterns << "\\bswitch\\b" << "\\bcase\\b" << "\\bif\\b"
                         << "\\bbreak\\b" << "\\belse\\b" << "\\belif\\b"
                         << "\\bwhile\\b" << "\\bfor\\b" << "\\bdo\\b"
                         << "\\bthen\\b" << "\\bcontinue\\b" << "\\breturn\\b"
                         << "\\btry\\b" << "\\bcatch\\b";
    foreach (const QString &pattern, controlflowPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = controlflowFormat;
        highlightingRules.append(rule);
    }

    singleLineCommentFormat.setForeground(QColor("#5c636f"));
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(QColor("#5c636f"));

    quotationFormat.setForeground(QColor("#99c27c"));
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    //    functionFormat.setFontItalic(true);
    functionFormat.setForeground(QColor("#65b0ed"));
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
