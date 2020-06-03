#pragma once
class SysLog
{
public:
	enum Level:char 
	{
		 LogLevelError = 0,
		 LogLevelWarning = 1,
		 LogLevelInfo = 2,
	};//Ã¶¾ÙÌå
/*
	static int LogLevelError = 0,
	static int LogLevelWarning = 1,
	static intLogLevelInfo = 2,
*/
private:
	Level m_LogLevel = LogLevelInfo;

public:
	void SetLevel(Level level);
	void Error(const char* message);
	void Warn(const char* message);
	void Info(const char* message);
};
