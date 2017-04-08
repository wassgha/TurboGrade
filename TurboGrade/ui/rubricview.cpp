#include "rubricview.h"
#include "ui_rubricview.h"
#include "criterionitem.h"
#include "ui_criterionitem.h"

RubricView::RubricView(QWidget *parent, Assignment *assignment) :
    QWidget(parent),
    ui(new Ui::RubricView)
{

    _assignment = assignment;

    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground, true);

    ui->title->setText("Rubric : " + _assignment->_name);

    ui->add_btn->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->criterion_grade->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->criterion_name->setAttribute(Qt::WA_MacShowFocusRect, false);

//    ui->dummy->hide();
//    ui->last->hide();

    layout()->setAlignment(Qt::AlignTop);

    connect(ui->add_btn, SIGNAL(clicked()), this, SLOT(add_criterion()));
}

RubricView::~RubricView()
{
    delete ui;
}

void RubricView::add_criterion()
{
    if (_assignment->_rubric->add_criterion(-1, ui->criterion_name->text(), nullptr, ui->criterion_grade->value()))
    {
        ui->mainLayout->insertWidget(2, new CriterionItem(this, ui->criterion_name->text(), ui->criterion_grade->value()));
        ui->criterion_name->clear();
        ui->criterion_grade->setValue(0);
    }
}
