#include "MainWidget.h"
#include "CommandSender.h"

#include <QApplication>
#include <thread>

int doAppProccess(int argc, char *argv[], CommandSender* pCommandSender)
{
    QApplication a(argc, argv);
    MainWidget w(pCommandSender);
    w.show();
    return a.exec();
}

int main(int argc, char *argv[])
{
    CommandSender* pCommandSender(new CommandSender);

    std::thread SendCommandThread([pCommandSender]
    {
        while (true)
        {
            pCommandSender->sendCommand();
        }
    });

    std::thread AppThread(doAppProccess, argc, argv, pCommandSender);

    SendCommandThread.join();
    AppThread.join();
    return 0;
}
