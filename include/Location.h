//
// Created by junaid on 02/02/21.
//

#ifndef LOCATE_ROUTE_LOCATION_H
#define LOCATE_ROUTE_LOCATION_H

#include <string>
#include <vector>

namespace Location {
	// return the geographic location of the ip addresses passed
	std::vector<std::string> get_location(const std::vector<std::string>& ip_addresses);

	// will return the ip addresses present in the line
	std::vector<std::string> parse(const std::string& traceroute_line);
}


#endif //LOCATE_ROUTE_LOCATION_H
