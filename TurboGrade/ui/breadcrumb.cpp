#include "breadcrumb.h"

Breadcrumb::Breadcrumb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Breadcrumb)
{
    ui->setupUi(this);
    add_home();
}

void Breadcrumb::add_home() {
    ClickableLabel* new_item = new ClickableLabel();
    new_item->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    new_item->setCursor(Qt::PointingHandCursor);
    new_item->setPixmap(QPixmap(":/misc/res/home.png"));
    new_item->setObjectName("home");
    new_item->setScaledContents(true);
    items.push_back(new_item);
    QLabel* separator = new QLabel("/");
    separator->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    items.push_back(separator);
    ui->horizontalLayout->addWidget(new_item);
    ui->horizontalLayout->addWidget(separator);
    connect (new_item, SIGNAL(clicked()), parentWidget(), SLOT(show_courses())) ;
}

void Breadcrumb::add_item(const QString text, const char* slot, QObject* arg) {
    ClickableLabel* new_item = new ClickableLabel();
    new_item->setText(text);
    new_item->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    new_item->setCursor(Qt::PointingHandCursor);
    items.push_back(new_item);
    QLabel* separator = new QLabel("/");
    separator->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    items.push_back(separator);
    ui->horizontalLayout->addWidget(new_item);
    ui->horizontalLayout->addWidget(separator);
    connect (new_item, SIGNAL(clicked()), parentWidget(), slot) ;
}

Breadcrumb::~Breadcrumb()
{

    for(QLabel* item: items) {
        delete item;
    }
    delete ui;
}
