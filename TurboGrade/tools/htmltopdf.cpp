#include "htmltopdf.h"

HTMLToPDF::HTMLToPDF(QWidget *parent, QString html) : QWebEngineView(parent){
    setHtml(html);
    connect(page(), SIGNAL(loadFinished(bool)), this,   SLOT(saveToPdf(bool)));

}

void HTMLToPDF::saveToPdf(bool loaded) {
    page()->printToPdf(QString("output3.pdf"), QPageLayout(QPageSize(QPageSize::A4), QPageLayout::Portrait, QMarginsF()));
}
