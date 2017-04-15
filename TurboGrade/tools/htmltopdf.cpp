#include "htmltopdf.h"

HTMLToPDF::HTMLToPDF(QString html, QString output):
    QWebEngineView(nullptr),
    _output(output)
{


    setHtml(html);
    connect(page(), SIGNAL(loadFinished(bool)), this,   SLOT(saveToPdf(bool)));

}

void HTMLToPDF::saveToPdf(bool loaded) {
    page()->printToPdf(_output, QPageLayout(QPageSize(QPageSize::A4), QPageLayout::Portrait, QMarginsF()));
}
