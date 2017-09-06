#ifndef DISPLAY_H
#define DISPLAY_H

#include <QFrame>

class Display : public QFrame
{
    Q_OBJECT
private:
    QPoint *originPoint;
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
public:
    explicit Display(QWidget *parent = 0);
    ~Display(void);
signals:

public slots:
};

#endif // DISPLAY_H
