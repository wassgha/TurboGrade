#include "rubricview.h"
#include "ui_rubricview.h"

RubricView::RubricView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RubricView)
{

    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground, true);

    ui->add_btn->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->spinBox->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->lineEdit->setAttribute(Qt::WA_MacShowFocusRect, false);

    layout()->setAlignment(Qt::AlignTop);
}

RubricView::~RubricView()
{
    delete ui;
}
