#include "CButton.h"
CButton::CButton(QWidget* parent):QToolButton(parent)
{
    resize(100,50);
    setStyleSheet( "QToolButton {\
                   background-color: white;\
                   border-style: outset;\
                   border-width: 2px;\
                   border-radius: 10px;\
                   border-color: grey;\
                   font: 25px;\
                   min-width: 10em;\
                   padding: 6px;\
               }\
               //QPushButton:pressed { \
                   //background-color: grey;\
                   //border-style: inset;\
               }");
}
