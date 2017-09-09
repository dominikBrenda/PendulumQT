#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "display.h"
#include "controlpanel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

signals:
private:
    Ui::MainWindow *ui;
    Display *display;
    ControlPanel *controlPanel;
protected:
    virtual void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
