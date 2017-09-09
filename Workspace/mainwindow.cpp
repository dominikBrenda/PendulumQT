#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<math.h>
#include<time.h>

#include<QPainter>
#include<QDebug>

#define WINDOW_ASPECT_RATIO 1.77777778f

#define DISPLAY_X_COORD_RATIO 0.02f
#define DISPLAY_Y_COORD_RATIO 0.03f
#define DISPLAY_WIDTH_RATIO 0.82f
#define DISPLAY_HEIGHT_RATIO 0.94f

#define CONTROL_PANEL_X_COORD_RATIO 0.86f
#define CONTROL_PANEL_Y_COORD_RATIO 0.03f
#define CONTROL_PANEL_WIDTH_RATIO 0.12f
#define CONTROL_PANEL_HEIGHT_RATIO 0.94f

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(50, 50, 640, 480);
    display = new Display(this);
    display->setGeometry(this->width() * DISPLAY_X_COORD_RATIO, this->height() * DISPLAY_Y_COORD_RATIO, this->width() * DISPLAY_WIDTH_RATIO, this->height() * DISPLAY_HEIGHT_RATIO);
    display->show();
    controlPanel = new ControlPanel(this);
    controlPanel->setGeometry(this->width() * CONTROL_PANEL_X_COORD_RATIO, this->height() * CONTROL_PANEL_Y_COORD_RATIO, this->width() * CONTROL_PANEL_WIDTH_RATIO, this->height() * CONTROL_PANEL_HEIGHT_RATIO);
    controlPanel->show();
}

MainWindow::~MainWindow()
{
    delete display;
    delete controlPanel;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    this->resize(this->height() * WINDOW_ASPECT_RATIO, this->height());
    display->setGeometry(this->width() * DISPLAY_X_COORD_RATIO, this->height() * DISPLAY_Y_COORD_RATIO, this->width() * DISPLAY_WIDTH_RATIO, this->height() * DISPLAY_HEIGHT_RATIO);
    controlPanel->setGeometry(this->width() * CONTROL_PANEL_X_COORD_RATIO, this->height() * CONTROL_PANEL_Y_COORD_RATIO, this->width() * CONTROL_PANEL_WIDTH_RATIO, this->height() * CONTROL_PANEL_HEIGHT_RATIO);
}
