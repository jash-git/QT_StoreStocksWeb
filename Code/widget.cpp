#include "widget.h"
#include "ui_widget.h"
#include <stdio.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QUrl URL("https://www.google.com/");
    ui->webView01->setUrl(URL);
    ui->webView02->setUrl(URL);
    ui->webView03->setUrl(URL);
    FILE *pf01='\0';
    FILE *pf02='\0';
    int j=0;
    char buf0[10];
    char buf1[512];
    pf01=fopen("List.txt","r");
    while(fgets(buf0,10,pf01) != NULL)
    {
        for(j=0;j<10;j++)
        {
            if(buf0[j]=='\n')
            {
                buf0[j]='\0';
                break;
            }
        }
        QString StrBuf=buf0;
        m_ListNo.append(StrBuf);
    }
    fclose(pf01);
    pf01='\0';
    pf01=fopen("Url.txt","r");
    while(fgets(buf1,513,pf01) != NULL)
    {
        for(j=0;j<513;j++)
        {
            if(buf1[j]=='\n')
            {
                buf1[j]='\0';
                break;
            }
        }
        QString StrBuf=buf1;
        m_ListUrl.append(StrBuf);
    }
    fclose(pf01);
    if(m_ListNo.size()>0)
    {
        m_intIndex=0;
        ui->lineEdit->setText(m_ListNo[m_intIndex]);
        QString StrBuf;
        StrBuf.sprintf("%d/%d",m_intIndex+1,m_ListNo.size());
        ui->label02->setText(StrBuf);
    }
    else
    {
        pf02=fopen("QT_StoreStocksWeb.txt","w");
        fclose(pf02);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton01_clicked()
{
    if(m_ListNo.size()>0)
    {
        m_intIndex--;
        if(m_intIndex>=0)
        {
            ui->lineEdit->setText(m_ListNo[m_intIndex]);
        }
        else
        {
            m_intIndex=0;
            ui->lineEdit->setText(m_ListNo[m_intIndex]);
        }
        QString StrBuf;
        StrBuf.sprintf("%d/%d",m_intIndex+1,m_ListNo.size());
        ui->label02->setText(StrBuf);
    }
}

void Widget::on_pushButton02_clicked()
{
    if(m_ListNo.size()>0)
    {
        m_intIndex++;
        if(m_intIndex<m_ListNo.size())
        {
            ui->lineEdit->setText(m_ListNo[m_intIndex]);
        }
        else
        {
            m_intIndex=m_ListNo.size()-1;
            ui->lineEdit->setText(m_ListNo[m_intIndex]);
        }
        QString StrBuf;
        StrBuf.sprintf("%d/%d",m_intIndex+1,m_ListNo.size());
        ui->label02->setText(StrBuf);
    }
}

void Widget::on_pushButton03_clicked()
{
    /*
    QString StrURL="https://goodinfo.tw/StockInfo/ShowK_Chart.asp?STOCK_ID=";
    StrURL+=ui->lineEdit->text();
    StrURL+="&CHT_CAT2=DATE";
    */
    QString StrURL;
    StrURL=StrURL.sprintf("https://goodinfo.tw/StockInfo/ShowK_Chart.asp?STOCK_ID=%s&CHT_CAT2=DATE",ui->lineEdit->text().toStdString().c_str());
    if(m_ListUrl.size()>=3)
    {
      StrURL=StrURL.sprintf(m_ListUrl[0].toStdString().c_str(),ui->lineEdit->text().toStdString().c_str());
    }
    QUrl URL(StrURL);

    ui->webView01->setUrl(URL);
    StrURL="QT_StoreStocksWeb ~ "+StrURL;
    this->setWindowTitle(StrURL);
    ui->tabWidget->setCurrentWidget(ui->tab01);

}

void Widget::on_pushButton04_clicked()
{
    /*
    QString StrURL="https://goodinfo.tw/StockInfo/StockDividendPolicy.asp?STOCK_ID=";
    StrURL+=ui->lineEdit->text();
    */
    QString StrURL;
    StrURL=StrURL.sprintf("https://goodinfo.tw/StockInfo/StockDividendPolicy.asp?STOCK_ID=%s",ui->lineEdit->text().toStdString().c_str());
    if(m_ListUrl.size()>=3)
    {
      StrURL=StrURL.sprintf(m_ListUrl[1].toStdString().c_str(),ui->lineEdit->text().toStdString().c_str());
    }
    QUrl URL(StrURL);

    ui->webView02->setUrl(URL);
    StrURL="QT_StoreStocksWeb ~ "+StrURL;
    this->setWindowTitle(StrURL);
    ui->tabWidget->setCurrentWidget(ui->tab02);
}

void Widget::on_pushButton05_clicked()
{
    /*
    QString StrURL="https://goodinfo.tw/StockInfo/StockDividendSchedule.asp?STOCK_ID=";
    StrURL+=ui->lineEdit->text();
    */
    QString StrURL;
    StrURL=StrURL.sprintf("https://goodinfo.tw/StockInfo/StockDividendSchedule.asp?STOCK_ID=%s",ui->lineEdit->text().toStdString().c_str());
    if(m_ListUrl.size()>=3)
    {
      StrURL=StrURL.sprintf(m_ListUrl[2].toStdString().c_str(),ui->lineEdit->text().toStdString().c_str());
    }
    QUrl URL(StrURL);

    ui->webView03->setUrl(URL);
    StrURL="QT_StoreStocksWeb ~ "+StrURL;
    this->setWindowTitle(StrURL);
    ui->tabWidget->setCurrentWidget(ui->tab03);
}
