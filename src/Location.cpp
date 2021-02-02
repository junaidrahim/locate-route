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

std::string Location::get_location(const std::string &ip_addr) {
	httplib::Client client("http://api.ipstack.com");
	std::string address = "/" + ip_addr + "?access_key=" + Location::ipStackAccessKey;

	if (auto res = client.Get(address.c_str())) {
		if (res->status == 200) {
			std::string rs = res->body;
			auto response = nlohmann::json::parse(rs);

			std::string continent = response.at("continent_name");
			std::string country = response.at("country_name");
			std::string region_name = response.at("region_name");
			std::string city = response.at("city");
			std::string zip = response.at("zip");
			float latitude = response.at("latitude");
			float longitude = response.at("longitude");

			std::string result;
			result += "Location: ";
			result += city + ", ";
			result += country + ", ";
			result += region_name + ", ";
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

std::string Location::parse(const std::string &traceroute_line) {
	// Sample : 3  1-144-31-103.dnainfotel.com (103.31.144.1)  10.949 ms  13.858 ms  13.010 ms

	std::regex ip_regex("((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)");

	std::smatch m;
	std::regex_search(traceroute_line, m, ip_regex);

	return m[0];
}
