#include "tabulators.h"

#include <QDebug>

Tabulators::Tabulators(int &argc, char *argv[]) :
    QApplication(argc, argv)
{
    setApplicationName("Tabulators");
    setApplicationVersion("1.0");
}
