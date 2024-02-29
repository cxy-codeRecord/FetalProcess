#include <QApplication>
#include "ControlProcess.h"
#include <QProcess>
#include "ControlProcessView.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlProcessView view;
    view.show();
    return a.exec();
}
