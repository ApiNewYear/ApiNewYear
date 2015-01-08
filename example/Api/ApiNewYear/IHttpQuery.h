/*
 * IHttpQuery.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_IHTTPQUERY_H_
#define APINEWYEAR_IHTTPQUERY_H_

#include <map>
#include <string>

namespace ApiNewYear {
	/**
	 * @brief Base class representing the minimum information needed for each HTTP Query (Request or Response)
	 * @details Establishes the base architecture for all HTTP Queries used by the server, to be used for
	 * Requests and Responses.
	 *
	 */
	class IHttpQuery {
	public:
		virtual ~IHttpQuery() {
		}
		/**
		 * @brief Setter for Data.
		 * @details IHttpQuery set data used for the http protocol.
		 *
		 * @param data a constant string reference of the data for the http protocol.
		 */
		virtual void setData(const std::string& data)=0;
		/**
		 * @brief Getter for Data.
		 * @details IHttpQuery get data used for the http protocol.
		 * @return a const string reference of the data.
		 */
		virtual const std::string& getData(void) const=0;
		/**
		 * @brief Getter for map of headers.
		 * @details IHttpQuery get a map of headers used for Http Queries.
		 * @return a constant map reference containing all the headers currently set for the http protocol.
		 */
		virtual const std::map<std::string, std::string>& getHeaders(
		        void) const=0;
		/**
		 * @brief Add header to map of headers.
		 * @details IHttpQuery adds a header to the map of headers for use by the http protocol.
		 *
		 * @param key string representing header name, used as map key.
		 * @param value string representing header value, used as map value.
		 */
		virtual void addHeader(const std::string& key,
		        const std::string& value)=0;
		/**
		 * @brief Remove header from map of headers.
		 * @details IHttpQuery removes the specified header from the map of headers if found.
		 *
		 * @param key string representing header name, used as map key.
		 */
		virtual void removeHeader(const std::string& key)=0;

	protected:

	private:

	};
}

#endif
