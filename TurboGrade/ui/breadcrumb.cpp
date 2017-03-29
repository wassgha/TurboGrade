#include "breadcrumb.h"

Breadcrumb::Breadcrumb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Breadcrumb)
{
    ui->setupUi(this);
}

void Breadcrumb::add_item(const QString text, const QObject *context, const char* slot) {
    ClickableLabel* new_item = new ClickableLabel();
    new_item->setText(text);
    new_item->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    new_item->setCursor(Qt::PointingHandCursor);
    QLabel* separator = new QLabel("/");
    separator->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->horizontalLayout->addWidget(new_item);
    ui->horizontalLayout->addWidget(separator);
    connect(new_item, SIGNAL(clicked()), context, slot);
}

Breadcrumb::~Breadcrumb()
{
    delete ui;
}
