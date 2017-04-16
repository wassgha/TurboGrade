#include "criterionitem.h"
#include "ui_criterionitem.h"

CriterionItem::CriterionItem(QWidget *parent, Criterion *criterion, bool child) :
    QWidget(parent),
    _child(child),
    _criterion(criterion),
    ui(new Ui::CriterionItem)
{
    ui->setupUi(this);

    if (child) {
        ui->verticalLayout_2->setContentsMargins(26, 0, 0, 0);
        ui->add_child->hide();
        ui->add_guide->hide();
    }

    if (!criterion->has_children() || child) {
        ui->sub_criteria->setContentsMargins(0, 0, 0, 0);
    }

    ui->name->setText(criterion->_name);
    ui->grade->setText(" (out of " + QString::number(criterion->_out_of) + ")");

    connect(ui->add_child, SIGNAL(clicked()), this, SLOT(add_child()));
}

CriterionItem::~CriterionItem()
{
    delete ui;
}

void CriterionItem::add_child() {
    emit added_child(_criterion);
}

bool CriterionItem::isChild() {
    return _child;
}
