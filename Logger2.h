/*
 * Logger2.h
 *
 *  Created on: 2014年11月20日
 *      Author: keyming
 */

#ifndef LOGGER2_H_
#define LOGGER2_H_
#include <iostream>
#include <fstream>

class Logger2{
public:
	enum LOGLEVEL{DEBUG = 0, INFO = 1, ERROR = 2};
private:

	LOGLEVEL logLevel;
	bool consoleOutput;
	std::ofstream  logStream;

	void logMsg(LOGLEVEL theLevel, const std::string& msg) ;
	void logMsg(LOGLEVEL theLevel,const char* msg);
	void logPrefix(LOGLEVEL level, const char* prefix, const char* fileName, int lineNumber, const char* funcName);
public:
	Logger2(const Logger2 &) = delete;
	Logger2 operator= (const Logger2 &) = delete;
	explicit Logger2(const std::string& filename, LOGLEVEL level = DEBUG);
	void setLogLevel(LOGLEVEL level);
	void debug(const std::string& msg, const char* filename, int lineNumber, const char* funcName);
	void info(const std::string& msg, const char* filename, int lineNumber, const char* funcName);
	void error(const std::string& msg, const char* filename, int lineNumber, const char* funcName);
};

#ifndef LOGGER_IMPLEMENT_CC

#define  debug(msg)   debug(msg, __FILE__,__LINE__,  __FUNCTION__)
#define  info(msg)   info(msg, __FILE__,__LINE__,  __FUNCTION__)
#define  error(msg)   error(msg, __FILE__,__LINE__,  __FUNCTION__)

#endif

#endif /* LOGGER2_H_ */
