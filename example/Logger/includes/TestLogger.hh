/*
 * TestLogger.hh
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef TEST_LOGGER_H_
#define TEST_LOGGER_H_

#include <ILogger.h>
#include <string>

class TestLogger: public ApiNewYear::ILogger {
public:
	TestLogger();
	~TestLogger();

	void info(const std::string& message);
	void warn(const std::string& message);
	void error(const std::string& message);
	void fatal(const std::string& message);
};

#endif
