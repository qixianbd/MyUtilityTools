/*
 * Logger.cc
 *
 *  Created on: 2014年11月20日
 *      Author: keyming
 */
#include "Logger.h"
#include <iostream>
#include <string>

Logger Logger::debug = Logger(Logger::DEBUG, std::cout);
Logger Logger::info = Logger(Logger::INFO, std::cout);
Logger Logger::error = Logger(Logger::ERROR, std::cerr);

Logger::Logger(LOGLEVEL level, std::ostream& os): logLevel(level), logStream(os) {
}



void Logger::log(const std::string& msg) const {
	log(msg.c_str());
}


void Logger::log(const char* msg) const {
	this->logStream << msg << "\n" << std::flush;
}

//#define LOGGER_CC
#ifdef LOGGER_CC

int main()
{
	Logger::error.log("error put");
	Logger::debug.log("debug put");
	Logger::info.log("info output.");
	return 0;
}
#endif
