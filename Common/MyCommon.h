#ifndef MYCOMMON_H
#define MYCOMMON_H
#include <mutex>
#include <QSharedPointer>
#include <QObject>
#include <QJsonDocument>
#include <QMetaObject>
#include <QMetaProperty>
#include <QVariant>
#include <QString>
using namespace std;
//单例使用双检查锁机制，防止多线程调度时多次对象生成
//使用智能指针防止程序结束时发生内存泄漏
#define SINGLETON(x) \
public:\
    static x* getInstance()\
    {\
    static QSharedPointer<x> ptr;\
    static mutex m;\
    if(!ptr.get())\
    {\
    unique_lock<mutex> lock(m);\
    if(!ptr.get())\
    {\
    ptr = QSharedPointer<x>(new x);\
    }\
    }\
    return ptr.get();\
    }\





#define Q_META_PROPERTY(type,name) \
protected:\
    Q_PROPERTY(type name READ get_##name WRITE set_##name NOTIFY name##Changed)\
    type m_##name; \
    public:\
    type get_##name() const {\
       return m_##name; \
}\
    public Q_SLOTS: \
    bool set_##name(type name){\
        bool ret = true;\
     {  \
         m_##name = name;      \
         emit name##Changed(m_##name); \
     }\
      return ret; \
}\
    Q_SIGNALS:\
    void name##Changed(type name);\



#define GET_META_OBJECT_JSON(object,json)\
{\
    const QMetaObject* metaObject = object.metaObject();\
    int count = metaObject->propertyCount();\
    QVariantMap mapdata; \
    for(int i=0;i<count;i++)\
    {\
      QMetaProperty metaProperty = metaObject->property(i);\
      QString name = metaProperty.name();\
      QVariant var = object.property(name.toStdString().c_str());\
      mapdata[name] = var;\
    }\
    QJsonDocument doc = QJsonDocument::fromVariant(mapdata);\
    json = doc.toJson();\
}\

#define GET_META_OBJECT_VARIANTMAP(object,mapdata)\
{\
    const QMetaObject* metaObject = object.metaObject();\
    int count = metaObject->propertyCount();\
    for(int i=0;i<count;i++)\
    {\
      QMetaProperty metaProperty = metaObject->property(i);\
      QString name = metaProperty.name();\
      QVariant var = object.property(name.toStdString().c_str());\
      mapdata[name] = var;\
    }\
}\



#define RECVHANDLE_FUNC_SUFFIX "RecvHandle"
#define DEF_RECV_RESPONSE_FUNC_NAME(x) x RECVHANDLE_FUNC_SUFFIX
#define CMAINWIN_WIDTH  1680
#define CMAINWIN_HEIGHT 1080
#define FHR_YAXIS_OFFSET 50
#define TOCO_YAXIS_OFFSET 0





#endif // MYCOMMON_H
