/*
 * eModuleType.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_EMODULETYPE_H_
#define APINEWYEAR_EMODULETYPE_H_

namespace ApiNewYear {
	/**
	 * @brief Enum containing the types of modules that can be created
	 * @details A type is necessary to identify the category of which a module belongs to
	 */
	enum eModuleType {
		CONNECTION, REQUEST, CGI, RESPONSE
	};
}

#endif
