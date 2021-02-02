//
// Created by junaid on 02/02/21.
//

#ifndef LOCATE_ROUTE_TRACEROUTERUNNER_H
#define LOCATE_ROUTE_TRACEROUTERUNNER_H

#include <string>
#include <vector>
#include <mutex>

class TracerouteRunner {
private:
	std::vector<std::string> results;
	std::mutex mutex_results;
	std::string network_address;

	int output_position = 0;
	bool read_complete = false;
	void process_output(const std::string& traceroute_line) const;

public:
	TracerouteRunner(const std::string& net_addr);
	void fetch_results();
	void print_output();
	std::string get_output_line();
};


#endif //LOCATE_ROUTE_TRACEROUTERUNNER_H
