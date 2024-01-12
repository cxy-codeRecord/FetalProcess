#ifndef CPAGEBUTTON_H
#define CPAGEBUTTON_H
#include <QWidget>
#include <QPushButton>
#include <QToolButton>
class CPageButton : public QToolButton
{
    Q_OBJECT
public:
    CPageButton(QWidget* parent=nullptr);
    void initPageButton();

};

#endif // CPAGEBUTTON_H
