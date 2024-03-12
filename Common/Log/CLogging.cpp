#include "CLogging.h"
#include <QDateTime>
void CLogging::initModule(const CLogLevel& minLevel, const QString& path)
{
    m_minLevel = minLevel;
    m_loggingPath = path;
    m_loggingFile.setFileName(m_loggingPath);
    m_loggingFile.open(QIODevice::ReadWrite|QIODevice::Append);
    m_Running = true;
    start();
}

CLogging::CLogging(QObject *parent):QThread(parent),m_Running(false)
{

}

void CLogging::debug(const QString& log)
{
    logging(CLogLevel::CLOG_DEBUG,log);
}

void CLogging::info(const QString& log)
{
    logging(CLogLevel::CLOG_INFO,log);
}

void CLogging::warning(const QString& log)
{
    logging(CLogLevel::CLOG_WARNING,log);
}

void CLogging::error(const QString& log)
{
    logging(CLogLevel::CLOG_ERROR,log);
}

void CLogging::critical(const QString& log)
{
    logging(CLogLevel::CLOG_CRITICAL,log);
}

CLogging::~CLogging()
{
    m_Running = false;
    m_condition.notify_all();
    wait();
    m_loggingFile.close();
}

void CLogging::logging(const CLogLevel &level, const QString &log)
{
    unique_lock<std::mutex> lock(m_mutex);
    CLoggingData data;
    data.log = log;
    data.level = level;
    m_QueueLoggingData.push_back(data);
    m_condition.notify_all();
}

void CLogging::run()
{
    while(m_Running)
    {
        unique_lock<mutex> lock(m_mutex);
        m_condition.wait(lock,[this]{
            return ((m_QueueLoggingData.length()>0)||(!m_Running));
        });
        if(m_QueueLoggingData.length()>0)
        {
            CLoggingData data = m_QueueLoggingData.head();
            m_QueueLoggingData.pop_front();
            lock.unlock();
            if(data.level>=m_minLevel)
            {
                QString prefix = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss.z")+QString(" | ");
                switch (data.level)
                {
                case CLogLevel::CLOG_DEBUG:
                {
                    prefix += "DEBUG:";
                    break;
                }
                case CLogLevel::CLOG_INFO:
                {
                    prefix += "INFO:";
                    break;
                }
                case CLogLevel::CLOG_WARNING:
                {
                    prefix += "WARNING:";
                    break;
                }
                case CLogLevel::CLOG_ERROR:
                {
                    prefix += "ERROR:";
                    break;
                }
                case CLogLevel::CLOG_CRITICAL:
                {
                    prefix += "CRITICAL:";
                    break;
                }
                }
                QString log = prefix + data.log + "\n";
                m_loggingFile.write(log.toStdString().data());
                m_loggingFile.flush();
            }
        }
    }
}
