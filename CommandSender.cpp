#include "CommandSender.h"

void CommandSender::addCommand(enu_command eCommand)
{
    m_qCommandQueue.push(eCommand);
}

void CommandSender::sendCommand()
{
    if (!m_qCommandQueue.empty())
    {
        m_qCommandQueue.back();
        m_qCommandQueue.pop();
    }
}
