/*
 * IModule.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_IModule_H_
#define APINEWYEAR_IModule_H_

#include <string>

namespace ApiNewYear {
	class IExecutionLine;
	class ILogger;
	class IServer;
}

namespace ApiNewYear {
	/**
	 * @brief Base class representing the minimum requirements for a module.
	 * @details Establishes the base architecture for a module to fulfill one or several tasks
	 * for the server.
	 *
	 */
	class IModule {
	public:

		virtual ~IModule() {
		}

		/**
		 * @brief initializes the module.
		 * @details IModule allows for module initizalization on load of module.
		 * @return an int representing success or error code.
		 */
		virtual int init(void) = 0;
		/**
		 * @brief hooks the module to the ExecutionLine
		 * @details IModule Hooks the module to the ExecutionLine through IExecutionLine::attach,
		 * allowing the module to add itself to the ExecutionLine.
		 *
		 * @param executionLine Reference to IExecutionLine
		 * @return an int representing success or error code.
		 */
		virtual int hook(IExecutionLine& executionLine)= 0;
		/**
		 * @brief hooks the module to the Server
		 * @details IModule Hooks the module to the Server through IServer::attach, allowing the
		 * module to add itself as a connection module.
		 * 
		 * @param server Reference to IServer
		 * @return an int representing success or error code.
		 */
		virtual int hook(IServer& server) = 0;
		/**
		 * @brief unhooks the module from the ExecutionLine
		 * @details IModule Unhooks the module from the ExecutionLine through IExecutionLine::detach,
		 * allowing the module to remove itself from the ExecutionLine.
		 * 
		 * @param executionLine executionLine Reference to IExecutionLine
		 * @return int representing success or error code
		 */
		virtual int unhook(IExecutionLine& executionLine)= 0;
		/**
		 * @brief destroys the module.
		 * @details IModule allows for the module to clean anything it needs prior to it's destruction.
		 * @return an int representing success or error code.
		 */
		virtual int destroy(void) = 0;

		/**
		 * @brief Getter for name of the module.
		 * @details Get's the name of the module.
		 * @return constant string reference containing the name of the module.
		 */
		virtual const std::string& getName() const = 0;

		/**
		 * @brief Getter for priority of the module.
		 * @details Get's the priority of the module.
		 * @return int representing the priority of the module.
		 */
		virtual int getPriority() const = 0;

		/**
		 * @brief Getter for version of the module.
		 * @details Get's the version of the module.
		 * @return float representing the version of the module.
		 */
		virtual float getVersion() const = 0;

		/**
		 * @brief Getter for location of the module.
		 * @details Get's the location of the module on the disk.
		 * @return constant string reference containing the location.
		 */
		virtual const std::string& getLocation() const = 0;

		/**
		 * @brief Getter for logger.
		 * @details Get's the logger used by the module for logging runtime information.
		 * @return reference to the logger.
		 */
		virtual ILogger& getLogger() const = 0;

	protected:
	private:

	};
}

#endif
