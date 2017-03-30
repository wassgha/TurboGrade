#ifndef SWITCHER_H
#define SWITCHER_H

#include <QWidget>
#include <QTimer>
#include <QColor>
#include <QBrush>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>

/**
 * @brief Switcher widget (on/off toggle)
 * Source: https://gist.github.com/IMAN4K/23d7af03936c3dc8deb3c528126c1610
 * (No license provided)
 */

class Switcher : public QWidget
{
    Q_OBJECT

public:
    explicit Switcher(bool const_color = true, QWidget *parent = 0);
    explicit Switcher(const QColor &color, bool const_color = true, QWidget *parent = 0);
    bool isToggled() const;
    void setToggle(bool set);
    void setDisable(bool set);
    bool isDisable() const;

private:
    bool _const_color;
    bool _disabled;
    bool _switch;
    QColor _brush;
    qreal _opacity;
    qreal _radius;
    qint16 _x;
    qint16 _y;
    QTimer _timer;
    qint16 _height;
    qint16 _margin;
    QBrush _thumb;
    QBrush _track;

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void enterEvent(QEvent *) Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;

signals:
    void toggled();

    public slots:
    void timercall();
};

#endif // SWITCHER_H
