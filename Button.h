#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <vector>

class Button : public QPushButton
{
    Q_OBJECT

public:
    Button(QWidget *parent = nullptr);
    Button(const QString & text, QWidget *parent = 0);
    ~Button();

public slots:
    bool createLogsRowAndChangeStatus(bool);

signals:
    void logsRowCreated(QString LogsRow);

private:
    QString Name;
    int Status;
};

#endif // BUTTON_H
