#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Analytics; }
QT_END_NAMESPACE

class Analytics : public QWidget
{
    Q_OBJECT
public slots:
    void come_back();
    void refresh();

public:
    explicit Analytics(QWidget *parent = nullptr);
    ~Analytics();

private:
    Ui::Analytics *ui;
};

#endif // ANALYTICS_H
