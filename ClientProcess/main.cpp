#include <QApplication>
#include "form.h"
#include "CService/CServiceGenerate/CServiceGenerate.h"
#include "../Interface/Controller/CController.h"
#include <QMetaType>
#include "../Common/CDataStructs.h"
#include <QSharedPointer>
#include <QProcess>
#include <QThread>
#include <QFontDatabase>
#include "../Common/Log/CLogging.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CLogging::getInstance()->initModule(CLogLevel::CLOG_DEBUG,"D:/FetalProcessCode/Output/log.txt");
    QProcess process;
    QString program = "D:/FetalProcessCode/Output/ControlProcess/debug/ControlProcess.exe";
    process.start(program,QStringList());
    process.waitForStarted();
    qRegisterMetaType<QSharedPointer<CDataStreamBase>>("QSharedPointer<CDataStreamBase>");
    CController::getInstance()->initModule();
    int retCode = a.exec();
    process.close();
    process.waitForFinished();
    return retCode;
}
