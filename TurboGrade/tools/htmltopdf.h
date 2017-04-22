#ifndef HTMLTOPDF_H
#define HTMLTOPDF_H

#include <QWebEngineView>

class HTMLToPDF : public QWebEngineView
{
    Q_OBJECT

public:
    explicit HTMLToPDF(QString html = "",
                       QString output = "output.pdf");

private slots:
    void saveToPdf(bool loaded);
private:
    QString _output;

};

#endif // HTMLTOPDF_H
