#include <iostream>
#include <assert.h>
#include <fstream>

#define LOGGER_IMPLEMENT_CC
#include "Logger2.h"


void Logger2::logMsg(LOGLEVEL theLevel, const std::string& msg) {
	return logMsg(theLevel, msg.c_str());
}

void Logger2::logMsg(LOGLEVEL theLevel, const char* msg) {
	if(logLevel <= theLevel){
		if(consoleOutput){
			if(theLevel == ERROR){
				std::cerr << msg << "\n" << std::flush;
			}
			else{
				std::cout <<  msg << "\n" << std::flush;
			}
		}
		logStream <<  msg << "\n" << std::flush;
	}
}

void Logger2::setLogLevel(LOGLEVEL level) {
	logLevel = level;
}

Logger2::Logger2(const std::string& filename, LOGLEVEL level): logLevel(level), consoleOutput(true), logStream(filename){
	if(!logStream){
		assert(0);
	}
}

void Logger2::debug(const std::string& msg, const char* fileName, int  lineNumber, const char* funcName){
		this->logPrefix(DEBUG, "debug", fileName, lineNumber, funcName);
		logMsg(DEBUG, msg);
		return ;
}

void Logger2::info(const std::string& msg, const char* fileName, int  lineNumber, const char* funcName){
		this->logPrefix(INFO, "info", fileName, lineNumber, funcName);
		logMsg(INFO, msg);
		return ;
}

void Logger2::error(const std::string& msg, const char* fileName, int  lineNumber, const char* funcName){
		this->logPrefix(ERROR, "error", fileName, lineNumber, funcName);
		logMsg(ERROR, msg);
		return ;
}

void Logger2::logPrefix(LOGLEVEL level, const char* prefix, const char* fileName, int lineNumber, const char* funcName) {
	if(logLevel <= level ){
		if(consoleOutput == true){
			if(level == ERROR){
				std::cerr << prefix << ":" << "In file (" << fileName << ") line (" << lineNumber << ") function (" << funcName << ") :" << std::flush;
			}
			else{
				std::cout << prefix << ":" << "In file (" << fileName << ") line (" << lineNumber << ") function (" << funcName << ") :" << std::flush;
			}
		}
		logStream << prefix << ":" << "In file (" << fileName << ") line (" << lineNumber << ") function (" << funcName << ") :" << std::flush;
	}
}

