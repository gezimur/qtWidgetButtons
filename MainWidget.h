#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>

#include "CommandSender.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(CommandSender* pCommandSender, QWidget *parent = nullptr);

public slots:
    void addLog(bool bButtonStatus);

    void sendCommand(bool bButtonStatus);

private:
    void createConnection();

private:
    QTextEdit* m_pListOfLogs;
    QPushButton* m_pWasherButton;
    QPushButton* m_pWiperButton;
    QPushButton* m_pDeleteLogsButton;

    QGridLayout* m_pLogsLayout;
    QGridLayout* m_pButtonLayout;
    QGridLayout* m_pMainLayout;

    CommandSender* m_pCommandSender;
};
