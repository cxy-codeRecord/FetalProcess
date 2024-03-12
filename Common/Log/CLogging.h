#ifndef CLOGGING_H
#define CLOGGING_H
#include <QObject>
#include <QThread>
#include <mutex>
#include <QQueue>
#include "../Common/MyCommon.h"
#include "../Common/CDataStructs.h"
#include <condition_variable>
#include <atomic>
#include <QFile>
class CLogging : public QThread
{
    Q_OBJECT
    SINGLETON(CLogging)
protected:
    struct CLoggingData
    {
       CLogLevel level;
       QString log;
    };
protected:
    condition_variable m_condition;
    mutex m_mutex;
    QQueue<CLoggingData> m_QueueLoggingData;
    std::atomic<bool> m_Running;
    CLogLevel m_minLevel = CLogLevel::CLOG_DEBUG;
    QString m_loggingPath;
    QFile m_loggingFile;
public:
    explicit CLogging(QObject *parent = nullptr);
    void initModule(const CLogLevel& minLevel,const QString& path);
    void debug(const QString& log);
    void info(const QString& log);
    void warning(const QString& log);
    void error(const QString& log);
    void critical(const QString& log);
    ~CLogging();
protected:
    void logging(const CLogLevel& level,const QString& log);
    void run();
};

#define DEBUG(x) CLogging::getInstance()->debug(x);
#define INFO(x) CLogging::getInstance()->info(x);
#define WARNING(x) CLogging::getInstance()->warning(x);
#define ERROR(x) CLogging::getInstance()->error(x);
#define CRITICAL(x) CLogging::getInstance()->critical(x);



#endif // CLOGGING_H
