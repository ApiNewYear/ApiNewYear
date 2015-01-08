/*
 * IObserver.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_IOBSERVER_H_
#define APINEWYEAR_IOBSERVER_H_

#include <string>

namespace ApiNewYear {
	class IHttpClient;
}

namespace ApiNewYear {
	/**
	 * @brief Base class used to execute modules in the ExecutionLine.
	 * @details Establishes the base architecture to allow modules to be executed by
	 * defining how they are executed by the ExecutionLine, and what information the
	 * ExecutionLine has for each module.
	 *
	 */
	class IObserver {
	public:
		virtual ~IObserver() {
		}
		/**
		 * @brief Getter for corresponding modules name.
		 * @details IObserver get name of creating module.
		 * @return constant string reference containing the modules name.
		 */
		virtual const std::string& getName(void) const=0;
		/**
		 * @brief Getter for corresponding modules priority.
		 * @details IObserver get the priority of the creating module.
		 * @return int containing the creating modules priority.
		 */
		virtual int getPriority(void) const=0;
		/**
		 * @brief Executes the function passed to the interfaces constructor.
		 * @details IObserver executes the modules main function through a function pointer.
		 *
		 * @param client the clients information.
		 * @return int containing the success or error code of the modules main function.
		 */
		virtual int update(IHttpClient* client)=0;

	protected:

	private:

	};
}

#endif
