#include "Button.h"

Button::Button(QWidget *parent)
    : QPushButton(parent)
{
    Status = 0;
    Name = "unnamed button";
}

Button::Button(const QString & text, QWidget *parent)
    : QPushButton(text, parent)
{
    Status = 0;
    Name = text;
}

Button::~Button()
{
}

bool Button::createLogsRowAndChangeStatus(bool st)
{
    QString LogRow(Name);
    if (Status != 2){//frized
        Status = (st)? 1 : 0;
    }else{
        LogRow += " frized";
    }
    if (Status == 0){
        LogRow += " off";
    }else if (Status == 1){
        LogRow += " on";
    }
    emit logsRowCreated(LogRow);
    return true;
}
