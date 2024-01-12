#ifndef CBUTTON_H
#define CBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QToolButton>
class CButton : public QToolButton
{
public:
    CButton(QWidget* parent = nullptr);
};

#endif // CBUTTON_H
