#include "MainWidget.h"
#include "Button.h"
#include <QPushButton>
#include <QGridLayout>


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{

    ListOfLogs = new QListWidget(this);
    ListOfLogs->hide();

    LayoutWithListOfLogs = new QGridLayout();
    LayoutWithListOfLogs->addWidget(ListOfLogs);

    Washer = new Button("washer", this);
    Washer->setCheckable(true);
    connect(Washer, SIGNAL(toggled(bool)), Washer, SLOT(createLogsRowAndChangeStatus(bool)));
    connect(Washer, SIGNAL(logsRowCreated(QString)), this, SLOT(addLogRow(QString)));

    Wiper = new Button("wiper", this);
    Wiper->setCheckable(true);
    connect(Wiper, SIGNAL(toggled(bool)), Wiper, SLOT(createLogsRowAndChangeStatus(bool)));
    connect(Wiper, SIGNAL(logsRowCreated(QString)), this, SLOT(addLogRow(QString)));

    DeleteLogsButton = new QPushButton("delete logs", this);
    connect(DeleteLogsButton, SIGNAL(clicked()), ListOfLogs, SLOT(clear()));

    ShowOrHideLogsButton = new QPushButton("logs", this);
    connect(ShowOrHideLogsButton, SIGNAL(clicked()), this, SLOT(showOrHideLogs()));

    LayoutWithButtons = new QGridLayout();
    LayoutWithButtons->addWidget(Washer, 0, 0);
    LayoutWithButtons->addWidget(Wiper, 0, 1);
    LayoutWithButtons->addWidget(ShowOrHideLogsButton, 1, 0);
    LayoutWithButtons->addWidget(DeleteLogsButton, 1, 1);

    MainLayout = new QGridLayout();
    MainLayout->addLayout(LayoutWithButtons, 0, 0);
    MainLayout->addLayout(LayoutWithListOfLogs, 0, 1);

    setLayout(MainLayout);
}

MainWidget::~MainWidget()
{
    delete Washer;
    delete Wiper;
    delete LayoutWithButtons;

    delete ListOfLogs;
    delete LayoutWithListOfLogs;

    delete MainLayout;
}

void MainWidget::addLogRow(QString LogRow)
{
    ListOfLogs->addItem(LogRow);
}

void MainWidget::showOrHideLogs()
{
    if (ListOfLogs->isHidden()){
        ListOfLogs->show();
    }else{
        ListOfLogs->hide();
    }
}
