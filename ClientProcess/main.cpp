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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qDebug()<<"main:"<<QThread::currentThreadId();
//    QFontDatabase fontDataBase;
//    int fontId = fontDataBase.addApplicationFont(":/font/SourceHanSansCN-Heavy.otf");
//    QStringList fontStringList = fontDataBase.applicationFontFamilies(fontId);
//    if(fontStringList.length()>0)
//    {
//        QString fontName = fontDataBase.applicationFontFamilies(fontId).at(0);
//        QStringList fontList = fontDataBase.families();
//        QFont font;
//        font.setFamily(fontName);
//        font.setWeight(QFont::Weight::Medium);
//        a.setFont(font);
//    }
    QProcess process;
    QString program = "C:/Users/14866/Desktop/git_fetalProcess2/Output/ControlProcess/debug/ControlProcess.exe";
    process.start(program,QStringList());
    process.waitForStarted();
    qRegisterMetaType<QSharedPointer<CDataStreamBase>>("QSharedPointer<CDataStreamBase>");
    CController::getInstance()->initModule();
    int retCode = a.exec();
    process.close();
    process.waitForFinished();
    return retCode;
}
