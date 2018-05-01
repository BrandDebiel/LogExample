#include "trythelogger.h"
#include <QDebug>

TryTheLogger::TryTheLogger()
{
    qInfo() << Q_FUNC_INFO << "Tried with succes";
}
