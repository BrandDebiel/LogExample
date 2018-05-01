#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QPlainTextEdit>

class Logger
{
    private:

        static Logger* instance;
        Logger();
        QPlainTextEdit *m_textEditor;
        bool m_textEditorEnabled;

    public:
        static Logger* getInstance();
        void logMessage();
        void messageHandler(QtMsgType type, const QString & str);
        void setTextEdit(QPlainTextEdit *textEditor);

};

#endif // LOGGER_H
