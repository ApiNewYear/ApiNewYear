/*
 * IExecutionLine.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_IEXECUTIONLINE_H_
#define APINEWYEAR_IEXECUTIONLINE_H_

#include <eModuleType.h>
#include <IObserver.h>
#include <IHttpClient.h>
#include <list>
#include <map>
#include <string>

namespace ApiNewYear {
	class IObserver;
	class IHttpClient;
}

namespace ApiNewYear {
	/**
	 * @brief Base class representing the minimum requirements for an HTTP ExecutionLine.
	 * @details Establishes the base architecture and requirements for launching modules
	 * based on module priority, and HTTP protocol requirements.
	 *
	 */
	class IExecutionLine {
	public:
		virtual ~IExecutionLine() {
		}
		/**
		 * @brief Runs all the modules in the ExecutionLine
		 * @details IExecutionLine run's the ExecutionLine iterating over each List in the map,
		 * by connection order, launching the modules through the IObserver's update function.
		 * @return An int representing the success or error value of the modules main function.
		 */
		virtual int run(void) = 0;
		/**
		 * @brief Adds module to the ExecutionLine.
		 * @details IExecutionLine Allows the module to add itself to the chain of execution.
		 * This function will add the modules IObserver to the appropriate List in the map of
		 * modules using the eModuleType. It will then order the List based on IObserver's priority.
		 *
		 * @param observer Event containing information for the module to run.
		 * @param type enum representing where in the execution line the module wishes to attach.
		 *
		 * @return an int representing success or error code.
		 */
		virtual int attach(IObserver* observer, eModuleType type) = 0;
		/**
		 * @brief Remove module from the ExecutionLine.
		 * @details IExecutionLine Removes the module by name and module type from the correct list.
		 *
		 * @param module string containing the name of the module to look for.
		 * @param type enum representing where in the execution line the module is located.
		 *
		 * @return an int representing success or error code.
		 */
		virtual int detach(const std::string& module, eModuleType type) = 0;
		/**
		 * @brief Stops the ExecutionLine if it is running.
		 * @details IExecutionLine Stops the running ExecutionLine, if not running, does nothing.
		 * @return an int representing success or error code.
		 */
		virtual int stop(void) = 0;
		/**
		 * @brief Getter for IHttpClient.
		 * @details IExecutionLine gets the IHttpClient being used by the ExecutionLine.
		 * @return pointer to the IHttpClient used.
		 */
		virtual IHttpClient* getHttpClient()=0;

		/**
		 * @brief Setter for IHttpClient.
		 * @details IExeuctionLine sets the IHttpClient to be used by the ExecutionLine.
		 * 
		 * @param client pointer to an allocated IHttpClient.
		 */
		virtual void setHttpClient(IHttpClient* client)=0;

	protected:

	private:

	};
}

#endif
