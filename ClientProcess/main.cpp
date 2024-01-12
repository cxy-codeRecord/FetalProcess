#include <QApplication>

#include "CTGView/CTGView.h"
#include "form.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Form form;
    //form.initModule();
//    form.show();
//    CTGView w;
//    w.resize(800,800);
//    w.show();
    Form form;
    form.initModule();
    form.show();
    return a.exec();
}
