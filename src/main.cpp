#include <QDebug>

#include "tabulators.h"
#include "dialog.h"

int main(int argc, char *argv[])
{
    Tabulators app(argc, argv);

    Dialog dialog;
    dialog.show();

    return app.exec();
}

