/*
 * IConnection.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_ICONNECTION_H
#define APINEWYEAR_ICONNECTION_H

namespace ApiNewYear {

	class IConnection {
		virtual ~IConnection() {
		}
		/**
		 * @brief Getter for corresponding modules name.
		 * @details IConnection get name of creating module.
		 * @return constant string reference containing the modules name.
		 */
		virtual const std::string& getName(void) const=0;
		/**
		 * @brief Getter for corresponding modules priority.
		 * @details IConnection get the priority of the creating module.
		 * @return int containing the creating modules priority.
		 */
		virtual int getPriority(void) const=0;
		/**
		 * @brief Executes the function passed to the interfaces constructor.
		 * @details IObserver executes the modules main function through a function pointer.
		 *
		 * @param socket server's listening socket.
		 * @param client pointer to the clients information (to be filled!).
		 * @return int containing the success or error code of the modules main function.
		 */
		virtual int update(SOCKET socket, IHttpClient* client)=0;
	};
}