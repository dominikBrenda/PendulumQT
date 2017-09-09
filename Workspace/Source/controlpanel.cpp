#include "controlpanel.h"

#define CONTROL_BUTTON_X_COORD_RATIO 0.1
#define CONTROL_BUTTON_Y_COORD_RATIO 0.5
#define RESET_BUTTON_X_COORD_RATIO 0.1
#define RESET_BUTTON_Y_COORD_RATIO 0.88
#define BUTTON_WIDTH_RATIO 0.8
#define BUTTON_HEIGHT_RATIO 0.1
#define LABEL_X_COORD_RATIO 0.2
#define LABEL_LENGTH_Y_COORD_RATIO 0.02
#define LABEL_MASS_Y_COORD_RATIO 0.17
#define LABEL_ANGLE_Y_COORD_RATIO 0.32
#define SPIN_BOX_PRECISION 1
#define SPIN_BOX_STEP 0.1
#define SPIN_BOX_X_COORD_RATIO 0.2
#define SPIN_BOX_LENGTH_Y_COORD_RATIO 0.08
#define SPIN_BOX_MASS_Y_COORD_RATIO 0.23
#define SPIN_BOX_ANGLE_Y_COORD_RATIO 0.38
#define ANGLE_MAX 179.9
#define ANGLE_MIN -179.9

static const char controlButtonStartText[] = "Start";
static const char controlButtonPauseText[] = "Pause";
static const char resetButtonText[] = "Reset";
static const char pendulumLengthLabelText[] = "Length [m]:";
static const char pendulumMassLabelText[] = "Mass [kg]:";
static const char pendulumAngleLabelText[] = "Angle [deg]:";

ControlPanel::ControlPanel(QWidget *parent) : QFrame(parent)
{
    this->setFrameShadow(QFrame::Sunken);
    this->setFrameShape(QFrame::StyledPanel);

    isSimulationRunning = false;

    controlButton.setParent(this);
    controlButton.setGeometry(CONTROL_BUTTON_X_COORD_RATIO * this->width(),
                              CONTROL_BUTTON_Y_COORD_RATIO * this->height(),
                              BUTTON_WIDTH_RATIO * this->width(),
                              BUTTON_HEIGHT_RATIO * this->height());
    controlButton.setText(controlButtonStartText);
    resetButton.setParent(this);
    resetButton.setGeometry(RESET_BUTTON_X_COORD_RATIO * this->width(),
                            RESET_BUTTON_Y_COORD_RATIO * this->height(),
                            BUTTON_WIDTH_RATIO * this->width(),
                            BUTTON_HEIGHT_RATIO * this->height());
    resetButton.setText(resetButtonText);
    pendulumLenghtLabel.setParent(this);
    pendulumLenghtLabel.setText(pendulumLengthLabelText);
    pendulumLenghtLabel.move(LABEL_X_COORD_RATIO * this->width(),
                             LABEL_LENGTH_Y_COORD_RATIO * this->height());
    pendulumMassLabel.setParent(this);
    pendulumMassLabel.setText(pendulumMassLabelText);
    pendulumMassLabel.move(LABEL_X_COORD_RATIO * this->width(),
                           LABEL_MASS_Y_COORD_RATIO * this->height());
    pendulumAngleLabel.setParent(this);
    pendulumAngleLabel.setText(pendulumAngleLabelText);
    pendulumAngleLabel.move(LABEL_X_COORD_RATIO * this->width(),
                            LABEL_ANGLE_Y_COORD_RATIO * this->height());
    pendulumLenghtSpinBox.setParent(this);
    pendulumLenghtSpinBox.setDecimals(SPIN_BOX_PRECISION);
    pendulumLenghtSpinBox.setMinimum(0.0);
    pendulumLenghtSpinBox.setSingleStep(SPIN_BOX_STEP);
    pendulumLenghtSpinBox.move(SPIN_BOX_X_COORD_RATIO * this->width(),
                               SPIN_BOX_LENGTH_Y_COORD_RATIO * this->height());
    pendulumMassSpinBox.setParent(this);
    pendulumMassSpinBox.setDecimals(SPIN_BOX_PRECISION);
    pendulumMassSpinBox.setMinimum(0.0);
    pendulumMassSpinBox.setSingleStep(SPIN_BOX_STEP);
    pendulumMassSpinBox.move(SPIN_BOX_X_COORD_RATIO * this->width(),
                             SPIN_BOX_MASS_Y_COORD_RATIO * this->height());
    pendulumAngleSpinBox.setParent(this);
    pendulumAngleSpinBox.setDecimals(SPIN_BOX_PRECISION);
    pendulumAngleSpinBox.setMinimum(ANGLE_MIN);
    pendulumAngleSpinBox.setMaximum(ANGLE_MAX);
    pendulumAngleSpinBox.setValue(0.0);
    pendulumAngleSpinBox.setSingleStep(SPIN_BOX_STEP);
    pendulumAngleSpinBox.move(SPIN_BOX_X_COORD_RATIO * this->width(),
                              SPIN_BOX_ANGLE_Y_COORD_RATIO * this->height());

    QObject::connect(&controlButton, controlButton.clicked, this, this->controlButtonPressed);
    QObject::connect(&resetButton, resetButton.clicked, this, this->resetButtonPressed);
}

ControlPanel::~ControlPanel(void)
{

}

void ControlPanel::adjust(void)
{
    controlButton.setGeometry(CONTROL_BUTTON_X_COORD_RATIO * this->width(),
                              CONTROL_BUTTON_Y_COORD_RATIO * this->height(),
                              BUTTON_WIDTH_RATIO * this->width(),
                              BUTTON_HEIGHT_RATIO * this->height());
    resetButton.setGeometry(RESET_BUTTON_X_COORD_RATIO * this->width(),
                            RESET_BUTTON_Y_COORD_RATIO * this->height(),
                            BUTTON_WIDTH_RATIO * this->width(),
                            BUTTON_HEIGHT_RATIO * this->height());
    pendulumLenghtLabel.move(LABEL_X_COORD_RATIO * this->width(),
                             LABEL_LENGTH_Y_COORD_RATIO * this->height());
    pendulumMassLabel.move(LABEL_X_COORD_RATIO * this->width(),
                           LABEL_MASS_Y_COORD_RATIO * this->height());
    pendulumAngleLabel.move(LABEL_X_COORD_RATIO * this->width(),
                            LABEL_ANGLE_Y_COORD_RATIO * this->height());
    pendulumLenghtSpinBox.move(SPIN_BOX_X_COORD_RATIO * this->width(),
                               SPIN_BOX_LENGTH_Y_COORD_RATIO * this->height());
    pendulumMassSpinBox.move(SPIN_BOX_X_COORD_RATIO * this->width(),
                             SPIN_BOX_MASS_Y_COORD_RATIO * this->height());
    pendulumAngleSpinBox.move(SPIN_BOX_X_COORD_RATIO * this->width(),
                              SPIN_BOX_ANGLE_Y_COORD_RATIO * this->height());
}

void ControlPanel::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    adjust();
}

void ControlPanel::controlButtonPressed()
{
    if(isSimulationRunning)
    {
        isSimulationRunning = false;
        controlButton.setText(controlButtonStartText);
        //TODO pause simulation
    }
    else
    {
        isSimulationRunning = true;
        controlButton.setText(controlButtonPauseText);
        //TODO start simulation
    }
}

void ControlPanel::resetButtonPressed()
{
    isSimulationRunning = false;
    controlButton.setText(controlButtonStartText);
    //TODO stop simulation
}
