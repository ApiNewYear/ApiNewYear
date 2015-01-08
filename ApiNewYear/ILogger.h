/*
 * ILogger.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_ILOGGER_H_
#define APINEWYEAR_ILOGGER_H_

#include <string>

namespace ApiNewYear {
	/**
	 * @brief Base class representing access to the server Logger.
	 * @details Establishes the base architecture for all interactions with logging of
	 * either server-wide events, or module-specific events.
	 *
	 */
	class ILogger {
	public:
		virtual ~ILogger() {
		}
		/**
		 * @brief Output information to stream.
		 * @details ILogger appends information to a stream.
		 *
		 * @param message a string representing the information.
		 */
		virtual void info(const std::string& message)=0;
		/**
		 * @brief Output warning to stream.
		 * @details ILogger appends a warning to a stream.
		 *
		 * @param message a string representing the information.
		 */
		virtual void warn(const std::string& message)=0;
		/**
		 * @brief Output error to stream.
		 * @details ILogger appends an error to a stream.
		 *
		 * @param message a string representing the information.
		 */
		virtual void error(const std::string& message)=0;
		/**
		 * @brief Output fatal error to stream.
		 * @details ILogger appends a fatal error to a stream.
		 *
		 * @param message a string representing the information.
		 */
		virtual void fatal(const std::string& message)=0;

	protected:

	private:

	};
}

#endif
