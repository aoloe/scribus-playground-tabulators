#include "dialog.h"
#include "ui_dialog.h"

#include "tabulator.h"

#include <QDebug>

class ListTabulatorItem : public QListWidgetItem
{
    public:
        ListTabulatorItem() :
            QListWidgetItem() {}
        ListTabulatorItem(QListWidget* listWidget) :
            QListWidgetItem(listWidget) {}

        const Tabulator* getWidget() const
        {
            const auto widget = listWidget()->itemWidget(const_cast<QListWidgetItem*>(dynamic_cast<const QListWidgetItem*>(this)));
            return dynamic_cast<const Tabulator*>(widget);
        }

        bool operator< (const QListWidgetItem & rhs) const override
        {
            const auto lhsTabulator = getWidget();
            const auto rhsTabulator = dynamic_cast<const ListTabulatorItem*>(&rhs)->getWidget();
            return lhsTabulator->getValue() < rhsTabulator->getValue();
        }
};

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
	ui->setupUi(this);
    {
        auto tabulator = new Tabulator(this);
        auto it = new ListTabulatorItem();
        it->setSizeHint(tabulator->sizeHint());
        ui->listWidget->addItem(it);
        ui->listWidget->setItemWidget(it, tabulator);
    }
    {
        auto tabulator = new Tabulator(this);
        auto it = new ListTabulatorItem();
        it->setSizeHint(tabulator->sizeHint());
        ui->listWidget->addItem(it);
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
