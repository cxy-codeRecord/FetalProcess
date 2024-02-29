#ifndef CONTROLPROCESSVIEW_H
#define CONTROLPROCESSVIEW_H

#include <QMainWindow>
#include "ControlProcess.h"
namespace Ui {
class ControlProcessView;
}

class ControlProcessView : public QMainWindow
{
    Q_OBJECT
public:
    explicit ControlProcessView(QWidget *parent = nullptr);
    ~ControlProcessView();
    QTimer m_timer;
private:
    Ui::ControlProcessView *ui;
    ControlProcess m_controlProcess;
};

#endif // CONTROLPROCESSVIEW_H
