/*
 * TestObserver.hh
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef TEST_OBSERVER
# define TEST_OBSERVER

#include <IObserver.h>
#include <string>

namespace ApiNewYear {
	class IHttpClient;
}

typedef int (*fnptr)(ApiNewYear::IHttpClient*);

class TestObserver: public ApiNewYear::IObserver {
public:
	TestObserver(const std::string& name, int priority, fnptr main);
	~TestObserver();
	int update(ApiNewYear::IHttpClient* c);

	const std::string& getName(void) const;
	int getPriority(void) const;

protected:

private:
	std::string _name;
	int _priority;
	fnptr _update;
};

#endif
