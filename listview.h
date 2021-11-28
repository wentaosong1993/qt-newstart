#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QWidget>
#include "mymodel.h"

namespace Ui {
class listview;
}

class listview : public QWidget
{
    Q_OBJECT

public:
    explicit listview(QWidget *parent = nullptr);
    ~listview();

private:
    Ui::listview *ui;
    MyModel m_myModel;
};

#endif // LISTVIEW_H
