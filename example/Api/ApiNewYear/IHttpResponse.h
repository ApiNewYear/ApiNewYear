/*
 * IHttpResponse.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_IHTTPRESPONSE_H_
#define APINEWYEAR_IHTTPRESPONSE_H_

#include <IHttpQuery.h>
#include <string>

namespace ApiNewYear {
	/**
	 * @brief Base class representing the minimum information needed for each HTTP Response.
	 * @details Establishes the base architecture for all HTTP Responses used by the server.
	 *
	 */
	class IHttpResponse: public IHttpQuery {
	public:
		virtual IHttpResponse() {
		}
		/**
		 * @brief Getter for status code.
		 * @details IHttpResponse get http status code.
		 * @return an integer representing the http status code.
		 */
		virtual int getCode(void) const=0;
		/**
		 * @brief Setter for status code.
		 * @details IHttpResponse set status code
		 *
		 * @param code integer representing the http status code.
		 */
		virtual void setCode(int code)=0;
		/**
		 * @brief Getter for http reason phrase.
		 * @details IHttpResponse get string containing http reason phrase representing the
		 * status code for HTTP Response.
		 * @return a constant string reference containing the reason phrase.
		 */
		virtual const std::string& getMessage(void) const=0;
		/**
		 * @brief Setter for http reason phrase.
		 * @details IHttpResponse set reason phrase representing the status code for HTTP Response.
		 *
		 * @param message a constant string reference containing the reason phrase.
		 */
		virtual void setMessage(const std::string& message)=0;

	protected:

	private:

	};
}

#endif
