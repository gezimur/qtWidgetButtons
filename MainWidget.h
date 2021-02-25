#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "Button.h"
#include <QWidget>
#include <QListWidget>
#include <QGridLayout>
#include <QPushButton>
#include <vector>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public slots:
    void addLogRow(QString LogRow);
    void showOrHideLogs();

private:
    Button *Washer;
    Button *Wiper;
    QPushButton *ShowOrHideLogsButton;
    QPushButton *DeleteLogsButton;
    QGridLayout *LayoutWithButtons;

    QListWidget *ListOfLogs;
    QGridLayout *LayoutWithListOfLogs;

    QGridLayout *MainLayout;
};
#endif // MAINWIDGET_H
