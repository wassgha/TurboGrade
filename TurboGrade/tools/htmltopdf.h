#ifndef HTMLTOPDF_H
#define HTMLTOPDF_H

#include <QWidget>
#include <QTextDocument>
#include <QPrinter>
#include <QFont>
#include <QPrintPreviewDialog>
#include <QHBoxLayout>

class HTMLToPDF : public QWidget
{
    Q_OBJECT
public:
    explicit HTMLToPDF(QWidget *parent = 0, int x = 0);
    explicit HTMLToPDF(QWidget *parent = 0, QString html = "");
    QTextDocument *document;

signals:

public slots:
    void printPreview(QPrinter *printer);
};

#endif // HTMLTOPDF_H
