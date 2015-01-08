/*
 * TestLogger.cpp
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#include <TestLogger.hh>
#include <iostream>

TestLogger::TestLogger() {
}

TestLogger::~TestLogger() {
}

void TestLogger::info(const std::string& message) {
	std::cout << "INFO: " << message << std::endl;
}

void TestLogger::warn(const std::string& message) {
	std::cout << "WARNING: " << message << std::endl;
}

void TestLogger::error(const std::string& message) {
	std::cerr << "ERROR: " << message << std::endl;
}

void TestLogger::fatal(const std::string& message) {
	std::cerr << "FATAL: " << message << std::endl;
}
