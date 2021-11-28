#include "listview.h"
#include "ui_listview.h"
#include <QListView>

listview::listview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listview)
{
    ui->setupUi(this);
    ui->listView->setModel(&m_myModel);
}

listview::~listview()
{
    delete ui;
}
