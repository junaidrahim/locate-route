#include <iostream>
#include <thread>
#include <string>
#include "include/argh.h"

#include "include/TracerouteRunner.h"

int main(int argc, char** argv) {

	argh::parser locate_route(argc, argv);

	if(locate_route[{"-h", "--help"}]) {
		std::cout << "locateroute - Get location information of the traceroute hops\n\n";
		std::cout << "USAGE: \n\t locateroute [ip or domain name]\n";
		std::cout << "FLAGS: \n\t -h, --help  Display Help\n";
	} else {
		if(locate_route(1)) {
			std::string url = locate_route[1];
			auto *t = new TracerouteRunner(url);

			std::thread t1(&TracerouteRunner::fetch_results, t);
			std::thread t2(&TracerouteRunner::print_output, t);

			t1.join();
			t2.join();
		} else {
			std::cout << "Enter ip address or domain name" << std::endl;
		}
	}

	return 0;
}
