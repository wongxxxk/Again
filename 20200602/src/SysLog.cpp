#include <iostream>
#include "SysLog.h"

void SysLog::SetLevel(Level level)
{
	m_LogLevel = level;
}

void SysLog::Error(const char* message)
{
	if (m_LogLevel >= LogLevelError)
		std::cout << "[Error]: " << message << std::endl;
}

void SysLog::Warn(const char* message)
{
	if (m_LogLevel >= LogLevelWarning)
		std::cout << "[Warning]: " << message << std::endl;
}

void SysLog::Info(const char* message)
{
	if (m_LogLevel >= LogLevelInfo)
		std::cout << "[Info]: " << message << std::endl;
}
