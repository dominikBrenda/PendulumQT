#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QPushButton>
#include <QDoubleSpinBox>
#include <QLabel>


class ControlPanel : public QFrame
{
public:
    ControlPanel(QWidget *parent = 0);
    ~ControlPanel(void);

    bool isSimulationRunning;
private:
    QPushButton controlButton;
    QPushButton resetButton;
    QDoubleSpinBox pendulumLenghtSpinBox;
    QDoubleSpinBox pendulumMassSpinBox;
    QDoubleSpinBox pendulumAngleSpinBox;
    QLabel pendulumLenghtLabel;
    QLabel pendulumMassLabel;
    QLabel pendulumAngleLabel;

    void adjust(void);

private slots:
    void controlButtonPressed(void);
    void resetButtonPressed(void);

protected:
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // CONTROLPANEL_H
