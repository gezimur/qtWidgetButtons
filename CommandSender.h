#pragma once

#include <queue>

class CommandSender
{

public:
    enum enu_command
    {
        e_first_relay_open,
        e_first_relay_close,
        e_second_relay_open,
        e_second_relay_close
    };

public:
    void addCommand(enu_command eCommand);
    void sendCommand();

private:
    std::queue<int> m_qCommandQueue;

};
