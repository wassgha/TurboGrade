#ifndef RUBRICVIEW_H
#define RUBRICVIEW_H

#include "../engine/controller.h"
#include "../engine/controller.h"

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>

namespace Ui {
class RubricView;
}

class RubricView : public QWidget
{
    Q_OBJECT

public:
    explicit RubricView(QWidget *parent = 0, Assignment *assignment = nullptr);
    ~RubricView();

private:
    Ui::RubricView *ui;
};

#endif // RUBRICVIEW_H
