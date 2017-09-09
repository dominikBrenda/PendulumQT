#include "display.h"

#include <QPainter>

#define WIDTH_MULTIPLIER 0.5f
#define HEIGHT_MULTIPLIER 0.15f

Display::Display(QWidget *parent) : QFrame(parent)
{
    this->setBackgroundRole(QPalette::Background);
    this->setFrameShadow(QFrame::Sunken);
    this->setFrameShape(QFrame::StyledPanel);
    QPalette p = this->palette();
    p.setColor(QPalette::Background, Qt::white);
    this->setPalette(p);
    this->setAutoFillBackground(true);
    originPoint = new QPoint;
    originPoint->setX(this->width() * WIDTH_MULTIPLIER);
    originPoint->setY(this->height() * HEIGHT_MULTIPLIER);
}

Display::~Display(void)
{
    delete originPoint;
}

void Display::paintEvent(QPaintEvent *event)
{
     QPainter p(this);
     p.setBrush(Qt::black);
     QFrame::paintEvent(event);
}

void Display::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    originPoint->setX(this->width() * WIDTH_MULTIPLIER);
    originPoint->setY(this->height() * HEIGHT_MULTIPLIER);
}
