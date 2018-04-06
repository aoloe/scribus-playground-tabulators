#include "tabulator.h"
#include "ui_tabulator.h"

Tabulator::Tabulator(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Tabulator)
{
  ui->setupUi(this);
}

Tabulator::~Tabulator()
{
  delete ui;
}
