/*
 * ModuleTest.cpp
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#include <eModuleType.h>
#include <IExecutionLine.h>
#include <IHttpClient.h>
#include <ModuleTest.hh>
#include <TestLogger.hh>
#include <TestObserver.hh>
#include <iostream>

ModuleTest::ModuleTest(const std::string &modName, int modPriority,
        float modVersion, const std::string &modLocation) :
		_name(modName), _priority(modPriority), _version(modVersion),
		        _location(modLocation), _logger(new TestLogger()) {
}

ModuleTest::~ModuleTest() {
}

int ModuleTest::init() {
	//initialize anything that is needed for the module to function here
	//this function will only be called ONCE durring the entire durration
	//of the module
	return (0);
}

int ModuleTest::hook(ApiNewYear::IExecutionLine& executionLine) {
	return executionLine.attach(new TestObserver(_name, _priority, &runModule),
	        ApiNewYear::REQUEST);
}

int ModuleTest::unhook(ApiNewYear::IExecutionLine& executionLine) {
	return executionLine.detach(_name, ApiNewYear::REQUEST);
}

int ModuleTest::destroy() {
	//anything needed to clean up what this module initialized. This function will
	//only be called ONCE; prior to deletion.
	return (0);
}

int ModuleTest::runModule(ApiNewYear::IHttpClient* client) {
	(void) client;
	std::cout
	        << "Hello World. This is the most basic module you can make, that will start with a high priority"
	        << std::endl;
	std::cout
	        << "This module will start after connection, durring the Request phase, and thus be the first module loaded in the ExecutionLine, due to it's priority"
	        << std::endl;
	std::cout
	        << "Through IHttpClient you may access and modify the Socket, HTTP Request and/or HTTP Response"
	        << std::endl;
	return 0;
}

/**
 * @brief Allows the server to create the module.
 * @details returns an IModule for the server to use
 * 
 * @param location [description]
 * @return [description]
 */
extern "C" ApiNewYear::IModule* create(const std::string &modName,
        int modPriority, float modVersion, const std::string &modLocation) {
	return new ModuleTest(modName, modPriority, modVersion, modLocation);
}

/**
 * @brief Deletes Shared Library module
 * @details This is required because new and delete can be overloaded which can cause
 * problems during execution on the server.
 * 
 * @param module The instance of the module returned by create
 */
extern "C" void remove(ApiNewYear::IModule* module) {
	delete module;
}

const std::string& ModuleTest::getName() const {
	return _name;
}

int ModuleTest::getPriority() const {
	return _priority;
}

float ModuleTest::getVersion() const {
	return _version;
}

const std::string& ModuleTest::getLocation() const {
	return _location;
}

ApiNewYear::ILogger& ModuleTest::getLogger() const {
	return *_logger;
}
