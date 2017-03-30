#include "htmltopdf.h"

HTMLToPDF::HTMLToPDF(QWidget *parent) : QWidget(parent)
{

    QFont font;
    font.setFamily(font.defaultFamily());

    document = new QTextDocument();
    document->setHtml(""
                      "<head>"
                      "<link rel=\"stylesheet\" type=\"text/css\" href=\"../../TurboGrade/tools/example.css\">"
                      "</head>"
                      "<h1>Student's Name</h1><br>"
                      "<p> Course Name - Professor's name</p>"
                      "<span>Final Grade:</span>"
                      "<h3>80%</h3>"
                      "<ul>"
                      " <li>Rubric Category"
                      "     <ul>"
                      "         <li>Sub-category</li>"
                      "         <li>Sub-category 2</li>"
                      "     </ul>"
                      " </li>"
                      " <li>Rubric Category 2</li>"
                      "</ul>");
    document->setDefaultFont(font);

    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("output2.pdf");
    QPrintPreviewDialog preview(&printer, this);
    preview.setWindowFlags ( Qt::Window );
    document->print(&printer);
    connect(&preview, SIGNAL(paintRequested(QPrinter *)), SLOT(printPreview(QPrinter *)));
    preview.exec();
}

void HTMLToPDF::printPreview(QPrinter *printer) {
    document->print(printer);
}
