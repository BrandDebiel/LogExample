#include "logger.h"

Logger* Logger::instance = 0;

Logger::Logger()
{

}

Logger* Logger::getInstance()
{
    if (instance == 0)
    {
        instance = new Logger();
    }

    return instance;
}

void Logger::logMessage()
{
    qDebug() << "Message OK";
}

void Logger::messageHandler(QtMsgType type,const QString & str)
{
    const char * msg = str.toStdString().c_str();

    QString messageString;

    QDateTime dateTime;
    dateTime = QDateTime::currentDateTime();

    messageString.append(dateTime.toString("yyyy-MM-dd hh:mm:ss:zzz"));
    messageString.append("  ");

    switch (type) {
    case QtDebugMsg:
        messageString.append(QString("DEBUG : %1").arg(msg));
        break;
    case QtWarningMsg:
        messageString.append(QString("WARNING : %1").arg(msg));
        break;
    case QtCriticalMsg:
        messageString.append(QString("CRITICAL : %1").arg(msg));
        break;
    case QtInfoMsg:
        messageString.append(QString("INFO : %1").arg(msg));
        break;
    case QtFatalMsg:
        messageString.append(QString("FATAL : %1").arg(msg));
        abort();
    }
    QFile outFile("log");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << messageString << endl;

    if(m_textEditorEnabled)
    {
        m_textEditor->appendPlainText(messageString);
    }
}

void Logger::setTextEdit(QPlainTextEdit *textEditor)
{
    m_textEditor = textEditor;
    m_textEditorEnabled = true;
}
