/*
 * Logger.h
 *
 *  Created on: 2014年11月20日
 *      Author: keyming
 */

#ifndef LOGGER_H_
#define LOGGER_H_


#include <fstream>
class Logger{
private:
	enum LOGLEVEL{DEBUG = 0, INFO = 1, ERROR = 2};
	LOGLEVEL logLevel;
	std::ostream& logStream;
	Logger(LOGLEVEL level, std::ostream& os);
public:
	static Logger debug, info, error;
	void log(const std::string& msg)const;
	void log(const char* msg)const;
};



#endif /* LOGGER_H_ */
