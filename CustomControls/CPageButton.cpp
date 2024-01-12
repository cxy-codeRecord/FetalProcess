#include "CPageButton.h"
CPageButton::CPageButton(QWidget* parent):QToolButton(parent)
{

}

void CPageButton::initPageButton()
{
    this->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->setStyleSheet("QToolButton\
    {\
    background-color:transparent;\
    }\
    QToolButton:pressed\
    {\
    background-color:#515151;\
    }\
    QToolButton:released\
    {\
    background-color:transparent;\
                        }");
}
