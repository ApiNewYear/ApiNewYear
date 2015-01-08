/*
 * IHttpClient.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_IHTTPCLIENT_H_
#define APINEWYEAR_IHTTPCLIENT_H_

namespace ApiNewYear {
	class IHttpRequest;
	class IHttpResponse;
	class ISocket;
}

namespace ApiNewYear {
	/**
	 * @brief Base class representing the minimum information needed for each connecting client.
	 * @details Establishes the base architecture for a connecting client, along with the minimum
	 * information needed.
	 *
	 */
	class IHttpClient {
	public:
		virtual ~IHttpClient() {
		}
		/**
		 * @brief Getter for client request.
		 * @details IHttpClient get IHttpRequest representing the request of the client.
		 * @return A reference to an object of type IHttpRequest.
		 */
		virtual IHttpRequest& getRequest(void) const=0;
		/**
		 * @brief Getter for client response.
		 * @details IHttpClient get IHttpResposne representing the response for the client.
		 * @return A reference to an object of type IHttpResponse.
		 */
		virtual IHttpResponse& getResponse(void) const=0;
		/**
		 * @brief Getter for client socket.
		 * @details IHttpClient get ISocket containing client connection information and socket.
		 * @return A reference to an object of type ISocket.
		 */
		virtual ISocket& getSocket(void) const=0;

	protected:

	private:

	};
}

#endif
