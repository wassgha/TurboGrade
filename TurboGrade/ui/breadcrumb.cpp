#include "breadcrumb.h"

Breadcrumb::Breadcrumb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Breadcrumb)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground, true);

    _parent = parent;
    add_home();
}

void Breadcrumb::add_home() {

    // Create the home icon
    ClickableLabel* home_icon = new ClickableLabel();
    home_icon->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    home_icon->setCursor(Qt::PointingHandCursor);
    home_icon->setPixmap(QPixmap(":/misc/res/home-gray.png"));
    home_icon->setObjectName("home");
    home_icon->setScaledContents(true);

    // Add the home icon
    items.push_back(home_icon);
    ui->horizontalLayout->addWidget(home_icon);

    // Add the separator
    QLabel* separator = new QLabel("/");
    separator->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    items.push_back(separator);
    ui->horizontalLayout->addWidget(separator);

    // Make home icon clickable
    connect (home_icon, SIGNAL(clicked()), _parent, SLOT(show_courses())) ;
}

void Breadcrumb::add_item(const QString text, const char* slot, QObject* arg) {

    // Highlight last node in the breadcrumb and make others gray
    if (items.size()>2)
        items.at(items.size() - 2)->setObjectName("breadcrumb_text_" + QString::number(items.size()));

    // Create new text
    ClickableLabel* new_item = new ClickableLabel();
    new_item->setText(text);
    new_item->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    new_item->setCursor(Qt::PointingHandCursor);
    new_item->setObjectName("last");

    // Add text to the breadcrumb
    items.push_back(new_item);
    ui->horizontalLayout->addWidget(new_item);

    // Create a separator and add it
    QLabel* separator = new QLabel("/");
    separator->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    items.push_back(separator);
    ui->horizontalLayout->addWidget(separator);

    // Make the text clickable (used SignalMapper because clicked() does not
    // does not pass data by itself)
    QSignalMapper* signalMapper = new QSignalMapper();
    connect(new_item, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(new_item, arg);
    connect(signalMapper, SIGNAL(mapped(QObject*)), _parent, slot);
}

Breadcrumb::~Breadcrumb()
{

    for(QLabel* item: items) {
        delete item;
    }
    delete ui;
}