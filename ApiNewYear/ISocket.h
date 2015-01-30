/*
 * ISocket.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_ISOCKET_H_
#define APINEWYEAR_ISOCKET_H_

#include <string>

#ifdef _WIN32
#include <winsock2.h>
#elif defined (__linux__)
#include <sys/types.h>
 #include <sys/socket.h>
typedef int SOCKET;
#else
#error undefined for this platform
#endif

namespace ApiNewYear {
	/**
	 * @brief Base class representing minimum information needed for sockets.
	 * @details Establishes the base architecture for Sockets used by the server.
	 *
	 */
	class ISocket {
	public:
		virtual ~ISocket() {
		}
		/**
		 * @brief Base class representing minimum information needed for sockets.
		 * @details Establishes the base architecture for Sockets used by the server.
		 *
		 */
		virtual SOCKET getSocket(void) const=0;
		/**
		 * @brief Setter for socket
		 * @details ISocket sets the socket/
		 * 
		 * @param sd the socket
		 */
		virtual void setSocket(SOCKET sd)=0;
		/**
		 * @brief Getter for IP address.
		 * @details ISocket get IP address of client using socket.
		 * @return a constant string reference containing the IP address.
		 */
		virtual const std::string& getIp(void) const=0;
		/**
		 * @brief Getter for Hostname.
		 * @details ISocket get Hostname of the corresponding client.
		 * @return cosntant string reference containing the Hostname.
		 */
		virtual const std::string& getHost(void) const=0;
		/**
		 * @brief Getter for Port number.
		 * @details ISocket get Port number used by socket.
		 * @return int representing the port number.
		 */
		virtual int getPort(void) const=0;
		/**
		 * @brief Getter for sockaddr used by the socket.
		 * @details ISocket get the sockaddr used by the socket
		 * @return const pointer to the sockaddr
		 */
		virtual const struct sockaddr* getSockInfo() const=0;
		/**
		 * @brief Setter for sockaddr used by the socket.
		 * @details ISocket set the sockaddr used by the socket.
		 * 
		 * @param sockaddr pointer to the sockaddr
		 */
		virtual void setSockInfo(struct sockaddr*) = 0;
	protected:

	private:

	};
}

#endif
