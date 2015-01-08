/*
 * IServer.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

 #ifndef APINEWYEAR_ISERVER_H
 #define APINEWYEAR_ISERVER_H

#include <IExecutionLine.h>
#include <IConnection.h>
 
namespace ApiNewYear {

	class IServer {
		virtual ~IServer() {}

		/**
		 * @brief Initializes IServer.
		 * @details IServer initializes IServer by giving access to IExecutionLine,
		 * for future run, and initializing the servers socket.
		 * 
		 * @param executionLine executionLine containing attached modules.
		 * @return int representing success or error code.
		 */
		virtual int init(IExecutionLine& executionLine)=0;

		/**
		 * @brief Adds connection module.
		 * @details IServer adds modules to container of connection modules to be executed after
		 * server is initialized, after fork, and while a client is trying to connect.
		 * 
		 * @param connection Event containing information for the module to run.
		 * @return an int representing success or error code.
		 */
		virtual int attach(IConnection* connection)=0;

		/**
		 * @brief Remvoes connection module.
		 * @details IServer Removes the module by name from container of connection modules to be
		 * executed.
		 * 
		 * @param name string containing the name of the module to look for.
		 * @return an int representing success or error code.
		 */
		virtual int detach(const std::string& name)=0;

		/**
		 * @brief Runs the main loop for the ZIA modules.
		 * @details IServer Awaits for a client to try and connect, creates a child process,
		 * allocates an IHttpClient to be used by the ExecutionLine, executes connection modules,
		 * and then loops the ExectuionLine. When ExecutionLine has finished (client has disconnected, or timed out),
		 * deletes IHttpClient.
		 * 
		 * 
		 * @return an int representing success or error code.
		 */
		virtual int run(void)=0;

		/**
		 * @brief Getter for ExecutionLine.
		 * @details IServer gets the ExectuionLine.
		 * @return a reference to the ExecutionLine.
		 */
		virtual IExecutionLine& getExecutionLine() = 0;
	};

}

 #endif