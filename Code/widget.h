#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton01_clicked();

    void on_pushButton02_clicked();

    void on_pushButton03_clicked();

    void on_pushButton04_clicked();

    void on_pushButton05_clicked();

private:
    Ui::Widget *ui;
    QList<QString> m_ListNo;
    QList<QString> m_ListUrl;
    void StocksKDChart();
    int m_intIndex=0;

};

#endif // WIDGET_H
