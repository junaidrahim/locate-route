//
// Created by junaid on 02/02/21.
//

#include "../include/TracerouteRunner.h"
#include "../include/Location.h"

#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <iostream>


TracerouteRunner::TracerouteRunner(const std::string &net_addr) {
	this->network_address = net_addr;
}

// Run the traceroute command, fetch the results and push it in this->results
// Lock and Unlock the mutex while writing
void TracerouteRunner::fetch_results() {
	std::array<char, 1024> buffer {};
	const std::string cmd = "traceroute " + this->network_address;

	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}

	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		this->mutex_results.lock();
		this->results.emplace_back(buffer.data());
		this->mutex_results.unlock();
	}

	this->read_complete = true;
}

// Parallely process items as they come in from this->results until reads are complete,
// Once reads are done, process all the remaining results
void TracerouteRunner::print_output() {
	while(!this->read_complete) {
		if(this->output_position < this->results.size()) {
			this->process_output(this->get_output_line());
		}
	}

	while(this->output_position < this->results.size()) {
		this->process_output(this->get_output_line());
	}
}

// Lock, Get a line of results from this->results, Unlock
std::string TracerouteRunner::get_output_line() {
	try {
		std::lock_guard<std::mutex> lock(this->mutex_results);
		return this->results.at(this->output_position++);
	} catch (const std::out_of_range& err) {
		std::cerr << "Out of Range Error: " << err.what() << std::endl;
		exit(1);
	}
}

// Process a line of traceroute output by fetching the location
void TracerouteRunner::process_output(const std::string &traceroute_line) const {
	if (this->output_position<=2) {
		std::cout << traceroute_line << std::endl;
	} else {
		const std::string ip = Location::parse(traceroute_line);

		if(!ip.empty()) {
			std::cout << traceroute_line;
			const std::string location = Location::get_location(ip);
			std::cout << location << std::endl;
		} else {
			std::cout << traceroute_line;
		}
	}
}
