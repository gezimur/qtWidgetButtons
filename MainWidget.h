#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);

public slots:
    void addLog(bool bButtonStatus);

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
};
