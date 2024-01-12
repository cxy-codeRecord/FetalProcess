#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <QObject>

class IController : public QObject
{
    Q_OBJECT
public:
    explicit IController(QObject *parent = nullptr);
    virtual void initModule() = 0;
signals:

public slots:
};

#endif // ICONTROLLER_H
