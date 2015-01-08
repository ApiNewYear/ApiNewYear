/*
 * ModuleTest.hh
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef MODULE_EXAMPLE
# define MODULE_EXAMPLE

#include <IModule.h>
#include <string>

namespace ApiNewYear {
	class IExecutionLine;
	class IHttpClient;
	class ILogger;
}

class ModuleTest: public ApiNewYear::IModule {
public:
	ModuleTest(const std::string &modName, int modPriority, float modVersion,
	        const std::string &modLocation);
	~ModuleTest();

	int init();
	int hook(ApiNewYear::IExecutionLine& executionLine);
	int unhook(ApiNewYear::IExecutionLine& executionLine);
	int destroy();
	static int runModule(ApiNewYear::IHttpClient* client);

	const std::string& getName() const;
	int getPriority() const;
	float getVersion() const;
	const std::string& getLocation() const;
	ApiNewYear::ILogger& getLogger() const;

protected:

private:
	std::string _name;
	int _priority;
	float _version;
	std::string _location;
	ApiNewYear::ILogger* _logger;
};

#endif
