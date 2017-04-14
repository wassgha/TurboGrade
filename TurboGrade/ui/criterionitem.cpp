#include "criterionitem.h"
#include "ui_criterionitem.h"

CriterionItem::CriterionItem(QWidget *parent, QString name, int out_of) :
    QWidget(parent),
    ui(new Ui::CriterionItem)
{
    ui->setupUi(this);

    ui->name->setText(name);
    ui->grade->setText(" (out of " + QString::number(out_of) + ")");

    connect(ui->add_child, SIGNAL(clicked()), this, SLOT(add_child()));
}

CriterionItem::~CriterionItem()
{
    delete ui;
}

void CriterionItem::add_child() {
//    emit add_child();
}
