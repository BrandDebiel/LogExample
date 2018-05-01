#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QApplication>

#include "logger.h"
#include "trythelogger.h"



void msgHandler(QtMsgType type, const QMessageLogContext &, const QString & str)
{
    Logger::getInstance()->messageHandler(type, str);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    Logger* dataLogger = Logger::getInstance();
    dataLogger->setTextEdit(ui->plainTextEdit);

    qInstallMessageHandler(msgHandler);

    TryTheLogger loggerTry;

    for(int i = 0; i < 5; i++)
    {
        qInfo() << i;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


