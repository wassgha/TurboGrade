#include "rubricview.h"
#include "ui_rubricview.h"
#include "criterionitem.h"
#include "ui_criterionitem.h"

RubricView::RubricView(QWidget *parent, Assignment *assignment) :
    QWidget(parent, Qt::Sheet),
    ui(new Ui::RubricView)
{

    _assignment = assignment;

    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground, true);

    ui->title->setText("Rubric : " + _assignment->_name);

    ui->add_btn->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->criterion_grade->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->criterion_name->setAttribute(Qt::WA_MacShowFocusRect, false);

    layout()->setAlignment(Qt::AlignTop);

    connect(ui->add_btn, SIGNAL(clicked()), this, SLOT(add_criterion()));
}

RubricView::~RubricView()
{
    delete ui;
}

void RubricView::add_criterion()
{

    // Capitalize criterion name
    QString criterion_name = ui->criterion_name->text();
    criterion_name = criterion_name.left(1).toUpper()+criterion_name.mid(1);

    // Add the criterion
    _assignment->_rubric->add_criterion(criterion_name, nullptr, ui->criterion_grade->value());
    refresh_criteria();
}

void RubricView::add_criterion(Criterion* parent) {
    qDebug()<<"Adding child criterion";

    if (_add_dialog != nullptr)
        delete _add_dialog;

    _add_dialog = new CriterionDialog(this, parent);
    _add_dialog->show();

    connect(_add_dialog, SIGNAL(submit()), SLOT(add_child()));
}

CriterionItem* RubricView::add_item(Criterion * criterion, CriterionItem* parent) {
    if (criterion != nullptr)
    {
        CriterionItem *item = new CriterionItem(this, criterion, parent != nullptr);
        if (parent == nullptr)
            ui->criteria->addWidget(item);
        else
            parent->ui->sub_criteria->addWidget(item);
        ui->criterion_name->clear();
        ui->criterion_grade->setValue(0);
        items.push_back(item);
        connect(item, SIGNAL(added_child(Criterion*)), this, SLOT(add_criterion(Criterion*)));
        return item;
    }
    return nullptr;
}

void RubricView::remove_criteria() {
    QVBoxLayout *verticalLayout =  (QVBoxLayout*) ui->criteria;
    for (CriterionItem* item: items) {
        if (!item->isChild()) {
            verticalLayout->removeWidget(item);
            delete item;
        }
    }
    items.clear();
}


void RubricView::refresh_criteria() {
    remove_criteria();
    for(Criterion* criterion: *_assignment->_rubric->_criteria) {
        CriterionItem* criterion_item = add_item(criterion);
        if (criterion->has_children()) {
            for (Criterion* child : criterion->children()) {
                add_item(child, criterion_item);
            }
        }
    }

}

void RubricView::add_child() {
    Criterion* parent = _add_dialog->_parent_criterion;

    // Capitalize criterion name
    QString criterion_name = _add_dialog->ui->name->text();
    criterion_name = criterion_name.left(1).toUpper()+criterion_name.mid(1);

    // Add the criterion
    parent->_rubric->add_criterion(criterion_name,
                                   parent,
                                   _add_dialog->ui->grade->value());
    refresh_criteria();
}
