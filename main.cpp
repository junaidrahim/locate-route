#include <iostream>
#include <thread>
#include "include/TracerouteRunner.h"
#include "include/Location.h"

int main() {
	auto *t = new TracerouteRunner("nullgitea.ga");

	std::thread t1(&TracerouteRunner::fetch_results, t);
	std::thread t2(&TracerouteRunner::print_output, t);

	t1.join();
	t2.join();

	return 0;
}
