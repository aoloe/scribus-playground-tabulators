#include "dialog.h"
#include "ui_dialog.h"

#include "tabulator.h"

#include <QDebug>

class ListTabulatorItem : public QListWidgetItem
{
    public:
        ListTabulatorItem(QListWidget* listWidget) :
            QListWidgetItem(listWidget) {}
        bool operator < (const ListTabulatorItem & rhs) const
        {
            // QListWidget *QListWidgetItem::listWidget() const
            // LblNames widget = <dynamic_cast>(LblNames*)( listWidget->itemWidget(item) );
            auto lhsTabulator  = this->data(Qt::DisplayRole);
            qDebug() << "type" << lhsTabulator.type();
            // auto lhsTabulator = dynamic_cast<const Tabulator*>(listWidget()->itemWidget(this));
            // auto rhsTabulator = dynamic_cast<const Tabulator*>(listWidget()->itemWidget(&rhs));
            // qDebug() << lhsTabulator->getValue();
        }
};

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
	ui->setupUi(this);
    // qDebug() << ui->verticalLayout;
    {
        auto tabulator = new Tabulator(this);
        // ui->verticalLayout->insertWidget(0, tabulator);
        // auto it = new QListWidgetItem(ui->listWidget);
        auto it = new ListTabulatorItem(ui->listWidget);
        it->setSizeHint(tabulator->sizeHint());
        ui->listWidget->setItemWidget(it, tabulator);
    }
    {
        auto tabulator = new Tabulator(this);
        // ui->verticalLayout->insertWidget(0, tabulator);
        // auto it = new QListWidgetItem(ui->listWidget);
        auto it = new ListTabulatorItem(ui->listWidget);
        it->setSizeHint(tabulator->sizeHint());
        ui->listWidget->setItemWidget(it, tabulator);
    }
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::apply()
{
    ui->listWidget->sortItems();
}
