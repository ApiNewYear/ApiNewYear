/*
 * TestObserver.cpp
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#include <TestObserver.hh>

TestObserver::TestObserver(const std::string& name, int priority, fnptr main) :
		_name(name), _priority(priority), _update(main) {
}

TestObserver::~TestObserver() {
}

int TestObserver::update(ApiNewYear::IHttpClient* client) {
	return _update(client);
}

const std::string& TestObserver::getName(void) const {
	return _name;
}

int TestObserver::getPriority(void) const {
	return _priority;
}
