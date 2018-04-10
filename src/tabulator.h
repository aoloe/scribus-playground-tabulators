#ifndef TABULATOR_H
#define TABULATOR_H

#include <QWidget>

namespace Ui {
    class Tabulator;
}

class Tabulator : public QWidget
{
  Q_OBJECT

public:
  explicit Tabulator(QWidget *parent = 0);
  ~Tabulator();

  int getValue();

private:
  Ui::Tabulator *ui;
};

#endif // TABULATOR_H
