#ifndef HTMLTOPDF_H
#define HTMLTOPDF_H

#include <QWebEngineView>

class HTMLToPDF : public QWebEngineView
{
    Q_OBJECT

public:
    explicit HTMLToPDF(QWidget *parent = 0, QString html = "");

private slots:
    void saveToPdf(bool loaded);

};

#endif // HTMLTOPDF_H
