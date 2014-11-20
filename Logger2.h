/*
 * Logger2.h
 *
 *  Created on: 2014年11月20日
 *      Author: keyming
 */

#ifndef LOGGER2_H_
#define LOGGER2_H_
#include <iostream>

class Logger2{
public:
	enum LOGLEVEL{DEBUG = 0, INFO = 1, ERROR = 2};
private:

	LOGLEVEL logLevel;
	bool consoleOutput;
	std::ofstream  logStream;

	void logMsg(const std::string& msg);
	void logMsg(const char* msg);
public:
	Logger2(const Logger2 &) = delete;
	Logger2 operator= (const Logger2 &) = delete;
	explicit Logger2(const std::string& filename, LOGLEVEL level = DEBUG);
	void setLogLevel(LOGLEVEL level);
	void debug(const std::string& msg);
	void info(const std::string& msg);
	void error(const std::string& msg);
};




#endif /* LOGGER2_H_ */
