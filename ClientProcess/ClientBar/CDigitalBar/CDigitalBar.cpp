#include "CDigitalBar.h"
#include "ui_CDigitalBar.h"
#include "../Common/View/ViewCommon.h"
#include "../Common/Service/ServiceCommon.h"
CDigitalBar::CDigitalBar(QWidget *parent) :
    CWidgetView (CDIGITALBAR_NAME,parent),
    ui(new Ui::CDigitalBar)
{
    ui->setupUi(this);
}

void CDigitalBar::initModule()
{
    registerRecvResponseHandle(DEF_RECV_RESPONSE_FUNC_NAME(SERVICE_FUNC_GET_FETAL_HEART_DATA),bind(&CDigitalBar::getFetalHeartDataRecvHandle,this,std::placeholders::_1));
}

CDigitalBar::~CDigitalBar()
{
    delete ui;
}

void CDigitalBar::getFetalHeartDataRecvHandle(QSharedPointer<CDataStreamBase> data)
{
    CDataStream<CFetalHeartData>* ptr = data->toDataStream<CDataStream<CFetalHeartData>>();
    if(ptr)
    {
        int heartOne = ptr->data.fetalHeartOne + FHR_YAXIS_OFFSET;
        int heartTwo = ptr->data.fetalHeartTwo + FHR_YAXIS_OFFSET;
        int heartThree = ptr->data.fetalHeartThree + FHR_YAXIS_OFFSET;
        ui->fetalDataOneLabel->setText(QString().setNum(heartOne));
        ui->fetalDataTwoLabel->setText(QString().setNum(heartTwo));
        ui->fetalDataThreeLabel->setText(QString().setNum(heartThree));
    }
}
