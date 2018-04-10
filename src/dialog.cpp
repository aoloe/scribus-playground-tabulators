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
        const QListWidget* getWidget(const ListTabulatorItem& item)
        {
            const auto lhsWidget = listWidget()->itemWidget(const_cast<QListWidgetItem*>(dynamic_cast<const QListWidgetItem*>(&item)));
        }
        bool operator< (const QListWidgetItem & rhs) const override
        {
            const auto lhsWidget = listWidget()->itemWidget(const_cast<QListWidgetItem*>(dynamic_cast<const QListWidgetItem*>(this)));
            auto lhsTabulator = dynamic_cast<const Tabulator*>(lhsWidget);
            // auto lhsTabulator = dynamic_cast<const Tabulator*>(getWidget(this));
            // qDebug() << lhsTabulator->getValue();
            const auto rhsWidget = listWidget()->itemWidget(const_cast<QListWidgetItem*>(dynamic_cast<const QListWidgetItem*>(&rhs)));
            auto rhsTabulator = dynamic_cast<const Tabulator*>(rhsWidget);
            return lhsTabulator->getValue() < rhsTabulator->getValue();
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
        // auto it = new ListTabulatorItem(ui->listWidget);
        auto it = new ListTabulatorItem();
        it->setSizeHint(tabulator->sizeHint());
        ui->listWidget->addItem(it);
        ui->listWidget->setItemWidget(it, tabulator);
    }
    {
        auto tabulator = new Tabulator(this);
        // ui->verticalLayout->insertWidget(0, tabulator);
        // auto it = new QListWidgetItem(ui->listWidget);
        // auto it = new ListTabulatorItem(ui->listWidget);
        auto it = new ListTabulatorItem();
        it->setSizeHint(tabulator->sizeHint());
        ui->listWidget->addItem(it);
        ui->listWidget->setItemWidget(it, tabulator);
    }
    if (false) {
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
