#include "ControlProcessView.h"
#include "ui_ControlProcessView.h"

ControlProcessView::ControlProcessView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlProcessView)
{
    ui->setupUi(this);
    setWindowTitle("ControlProcessView");
    m_controlProcess.initModule();
    connect(&m_controlProcess,&ControlProcess::signalReadData,this,[=](int type,QByteArray data,int dataIndex){
            QString strType = QString("type:")+ QString().setNum(type);
            QString strData;
            QString strIndex;
            strData.append("data:");
            for(int i=0;i<data.length();i++)
            {
                unsigned char c = (unsigned char)data[i];
                strData.append("0x");
                strData.append(QString().setNum(c,16));
                strData.append(" ");
            }
            strIndex = QString("dataIndex:") + QString().setNum(dataIndex);
            ui->plainTextEdit->appendPlainText(strType);
            ui->plainTextEdit->appendPlainText(strData);
            ui->plainTextEdit->appendPlainText(strIndex);
    });
    connect(&m_controlProcess,&ControlProcess::signalStartRecord,this,[=]{
        m_timer.start(50);
    });
    connect(&m_controlProcess,&ControlProcess::signalPauseRecord,this,[=]{
        m_timer.stop();
    });
    connect(&m_controlProcess,&ControlProcess::signalEndRecord,this,[=]{
        m_timer.stop();
        m_controlProcess.resetCTGData();
    });
    connect(&m_timer,&QTimer::timeout,&m_controlProcess,&ControlProcess::onUpLoadCTGData,Qt::QueuedConnection);

}

ControlProcessView::~ControlProcessView()
{
    delete ui;
}
