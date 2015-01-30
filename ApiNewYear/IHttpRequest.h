/*
 * IHttpRequest.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_IHTTPREQUEST_H_
#define APINEWYEAR_IHTTPREQUEST_H_

#include <IHttpQuery.h>
#include <string>

namespace ApiNewYear {
	/**
	 * @brief Base class representing the minimum information needed for each HTTP Request.
	 * @details Establishes the base architecture for all HTTP Requests used by the server.
	 *
	 */
	class IHttpRequest: public virtual IHttpQuery {
	public:
		virtual ~IHttpRequest() {
		}
		/**
		 * @brief Getter for URI.
		 * @details IHttpRequest get string containing URI for HTTP Requests.
		 * @return a constant string reference of the URI.
		 */
		virtual const std::string& getUri(void) const=0;
		/**
		 * @brief Setter for URI.
		 * @details IHttpRequest set string URI for HTTP Requests.
		 * @param a constant string reference of the URI.
		 */
		virtual void setUri(const std::string& uri)=0;
		/**
		 * @brief Getter for Method.
		 * @details IHttpRequest get string Method used for Http Requests.
		 * @return a constant string refernce containing the http method.
		 */
		virtual const std::string& getMethod(void) const=0;
		/**
		 * @brief Setter for Method.
		 * @details IHttpRequest set string Method used for Http Requests.
		 *
		 * @param method a constant string refernce of the http method used.
		 */
		virtual void setMethod(const std::string& method)=0;

	protected:

	private:

	};
}

#endif
