#include <iostream>
#include <assert.h>
#include <fstream>
#include "Logger2.h"

void Logger2::logMsg(const std::string& msg) {
	return logMsg(msg.c_str());
}

void Logger2::logMsg(const char* msg) {
	if(consoleOutput){
		std::cout << __FUNCTION__ << msg << "\n" << std::flush;
	}
	logStream << __FUNCTION__ <<  msg << "\n" << std::flush;
}

void Logger2::setLogLevel(LOGLEVEL level) {
	logLevel = level;
}



Logger2::Logger2(const std::string& filename, LOGLEVEL level): logLevel(level), consoleOutput(true), logStream(filename){
	if(!logStream){
		assert(0);
	}
}

void Logger2::debug(const std::string& msg) {
	if(logLevel <= DEBUG){
		logMsg(msg);
	}
	return ;
}

void Logger2::info(const std::string& msg) {
	if(logLevel <=  INFO){
		logMsg(msg);
	}
	return ;
}

void Logger2::error(const std::string& msg) {
	if(logLevel <=  ERROR){
		logMsg(msg);
	}
	return ;
}
/*
 * Logger2.cc
 *
 *  Created on: 2014年11月20日
 *      Author: keyming
 */
#define LOGGER2_CC
#ifdef LOGGER2_CC

int main()
{
	Logger2 log("logFile.txt");
	//log.setLogLevel(Logger2::ERROR);
	log.debug("okok");
	return 0;
}

#endif
