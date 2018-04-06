#include "dialog.h"
#include "ui_dialog.h"

#include "tabulator.h"

#include <QDebug>
#include <QLabel>

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
	ui->setupUi(this);
    qDebug() << ui->verticalLayout;
    auto tabulator = new Tabulator(this);
    ui->verticalLayout->insertWidget(0, tabulator);
}

Dialog::~Dialog()
{
  delete ui;
}
