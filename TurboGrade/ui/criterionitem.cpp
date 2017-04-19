#include "criterionitem.h"
#include "ui_criterionitem.h"

CriterionItem::CriterionItem(QWidget *parent, Criterion *criterion) :
    QWidget(parent),
    _criterion(criterion),
    ui(new Ui::CriterionItem)
{
    ui->setupUi(this);

    if (criterion->_parent != nullptr) {
        ui->verticalLayout_2->setContentsMargins(26, 0, 0, 0);
        ui->add_child->hide();
        ui->add_guide->hide();
    }

    if (!criterion->has_children() || criterion->_parent != nullptr) {
        ui->sub_criteria->setContentsMargins(0, 0, 0, 0);
    }

    ui->name->setText(criterion->_name);
    ui->grade->setText(" (out of " + QString::number(criterion->_out_of) + ")");

    connect(ui->add_child, SIGNAL(clicked()), this, SLOT(add_child()));
    connect(ui->add_guide, SIGNAL(clicked()), this, SLOT(add_guide()));
}

CriterionItem::~CriterionItem()
{
    delete ui;
}

void CriterionItem::add_child() {
    emit added_child(_criterion);
}


void CriterionItem::add_guide() {
    emit added_guide(_criterion);
}

bool CriterionItem::isChild() {
    return _criterion->_parent != nullptr;
}
