
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>

#include "CommandSender.h"

#include "MainWidget.h"

MainWidget::MainWidget(CommandSender* pCommandSender, QWidget *parent)
    : QWidget(parent),
      m_pListOfLogs(new QTextEdit(this)),
      m_pWasherButton(new QPushButton("washer", this)),
      m_pWiperButton(new QPushButton("wiper", this)),
      m_pDeleteLogsButton(new QPushButton("delete log")),

      m_pLogsLayout(new QGridLayout()),
      m_pButtonLayout(new QGridLayout()),
      m_pMainLayout(new QGridLayout()),

      m_pCommandSender(pCommandSender)
{
    m_pLogsLayout->addWidget(m_pListOfLogs);

    m_pWasherButton->setCheckable(true);
    m_pWiperButton->setCheckable(true);

    m_pButtonLayout->addWidget(m_pWasherButton, 0, 0);
    m_pButtonLayout->addWidget(m_pWiperButton, 0, 1);
    m_pButtonLayout->addWidget(m_pDeleteLogsButton, 1, 1);
    m_pButtonLayout->setColumnStretch(2, 1);

    m_pMainLayout->addLayout(m_pButtonLayout, 0, 0);
    m_pMainLayout->addLayout(m_pLogsLayout, 1, 0);
    m_pMainLayout->setRowStretch(1, 1);

    setLayout(m_pMainLayout);

    createConnection();
}

void MainWidget::createConnection()
{
    connect(m_pWasherButton, SIGNAL(toggled(bool)), this, SLOT(addLog(bool)));
    connect(m_pWiperButton, SIGNAL(toggled(bool)), this, SLOT(addLog(bool)));

    connect(m_pWasherButton, SIGNAL(toggled(bool)), this, SLOT(sendCommand(bool)));
    connect(m_pWiperButton, SIGNAL(toggled(bool)), this, SLOT(sendCommand(bool)));

    connect(m_pDeleteLogsButton, SIGNAL(clicked()), m_pListOfLogs, SLOT(clear()));

}

void MainWidget::addLog(bool bButtonStatus)
{
    QPushButton* pSender = (QPushButton*)sender();
    if (pSender == m_pWasherButton)
        m_pListOfLogs->setTextColor(QColor(0,255,0));
    else if (pSender == m_pWiperButton)
        m_pListOfLogs->setTextColor(QColor(0,0,255));

    m_pListOfLogs->append(pSender->text() + ((bButtonStatus)? " on" : " off") );
}

void MainWidget::sendCommand(bool bButtonStatus)
{
    QPushButton* pSender = (QPushButton*)sender();
    if (pSender == m_pWasherButton)
    {
        if (bButtonStatus)
            m_pCommandSender->addCommand(CommandSender::e_first_relay_open);
        else
            m_pCommandSender->addCommand(CommandSender::e_first_relay_close);
    }
    else if (pSender == m_pWiperButton)
    {
        if (bButtonStatus)
            m_pCommandSender->addCommand(CommandSender::e_second_relay_open);
        else
            m_pCommandSender->addCommand(CommandSender::e_second_relay_close);
    }
}
