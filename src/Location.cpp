//
// Created by junaid on 02/02/21.
//

#include <string>
#include "../include/Location.h"
#include "../include/httplib.h"
#include "../include/json.hpp"

#include <regex>
#include <iostream>

#define CPPHTTPLIB_OPENSSL_SUPPORT

// Make a request to the API and get the location data
std::string Location::get_location(const std::string &ip_addr) {
	httplib::Client client("http://api.ipstack.com");
	std::string address = "/" + ip_addr + "?access_key=" + Location::ipStackAccessKey;

	if (auto res = client.Get(address.c_str())) {
		if (res->status == 200) {
			std::string rs = res->body;
			auto response = nlohmann::json::parse(rs);

			std::string continent, country, region_name, city, zip;
			float latitude, longitude;

			try {
				continent = response.at("continent_name");
				country = response.at("country_name");
				region_name = response.at("region_name");
				city = response.at("city");
				zip = response.at("zip");
				latitude = response.at("latitude");
				longitude = response.at("longitude");
			} catch (...) {
				// do nothing, let the particular string be empty
			}

			std::string result;
			result += "Location: ";
			result += city + ", ";
			result += region_name + ", ";
			result += country + ", ";
			result += continent + "\n";
			result += "Zip: " + zip;
			result += ", Coordinates: " + std::to_string(latitude) + "," + std::to_string(longitude) + "\n";

			return result;

		} else {
			std::cout << "Error Fetching IP, Status Code " << res->status << std::endl;
		}
	}

	return "Cannot Determine Location";
}

// Return the IP addresses from a line of traceroute output
std::string Location::parse(const std::string &traceroute_line) {
	// Sample : 3  1-144-31-103.dnainfotel.com (103.31.144.1)  10.949 ms  13.858 ms  13.010 ms

	std::regex ip_regex("((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)");

	std::smatch m;
	std::regex_search(traceroute_line, m, ip_regex);

	return m[0];
}
