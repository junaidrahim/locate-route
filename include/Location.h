//
// Created by junaid on 02/02/21.
//

#ifndef LOCATE_ROUTE_LOCATION_H
#define LOCATE_ROUTE_LOCATION_H

#include <string>
#include <vector>

namespace Location {
	const std::string ipStackAccessKey = "c060c1df429878748bc52eb88ef2f484";

	// return the geographic location of the ip addresses passed
	std::string get_location(const std::string& ip_addr);

	// will return the ip addresses present in the line
	std::string parse(const std::string& traceroute_line);
}


#endif //LOCATE_ROUTE_LOCATION_H
