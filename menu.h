#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QLabel>
#include <QStringListModel>
//#include <QModelIndex>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

signals:
    void download_product(QString value);
    void refresh_statistic();

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();


private:
    Ui::Menu *ui;
    QStringListModel *model;
    QStringListModel *model_2;
    bool find_sub(QString, QString);

public slots:
    void open_product();
    void open_basket();
    void open_order();
    void open_analytics();


private slots:
    void search();
};

#endif // MENU_H
