/*
 * Logger2_Test.cc
 *
 *  Created on: 2014年11月20日
 *      Author: qmwx
 */

#include "Logger2.h"


#define LOGGER2_TEST__CC
#ifdef LOGGER2_TEST__CC


void func( Logger2& log){
	log.info("this is in func");
}
int main()
{
	Logger2 log("logFile.txt");
	//log.setLogLevel(Logger2::ERROR);
	log.debug("okok");

	log.error("This is Error msg");

	func(log);

	return 0;
}

#endif




