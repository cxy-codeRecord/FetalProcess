#ifndef FORM_H
#define FORM_H

#include <QMainWindow>

namespace Ui {
class Form;
}

class Form : public QMainWindow
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void initModule();
private:
    Ui::Form *ui;
};

#endif // FORM_H
