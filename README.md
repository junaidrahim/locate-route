# locate_route

A command line tool to grab the geographical location of the hops from `traceroute`. It's like `traceroute`, but also returns the actual location of the IP address. 

## Installation

Make sure you have `g++`, `curl` `cmake`, `make` and `traceroute` installed and setup on your machine.

Run the following to install the binary:

```bash
curl -o- https://raw.githubusercontent.com/junaidrahim/locate-route/main/install.sh | sudo bash
```

You can run `locate_route` in your shell now.

## Build from Source

1. `git clone https://github.com/junaidrahim/locate-route`
2. `mkdir build && cd build`
3. `cmake ..`
4. `make`

The binary `locate_route` will compile in the `build/` directory. You can run it from there,
or copy it into `$PATH` to access it from anywhere in your terminal.


## Usage

```sh-session
$ locate_route --help
locateroute - Get location information of the traceroute hops

USAGE:
	 locateroute [ip or domain name]
FLAGS:
	 -h, --help  Display Help
```

```sh-session
$ locate_route github.com
traceroute to github.com (13.234.176.102), 30 hops max, 60 byte packets

 1  _gateway (192.168.0.1)  1.539 ms  3.299 ms  3.249 ms

 2  4-144-31-103.dnainfotel.com (103.31.144.4)  3.206 ms  3.164 ms  3.121 ms
Location: Virār, Maharashtra, India, Asia
Zip: 401303, Coordinates: 19.466700,72.800003

 3  1-144-31-103.dnainfotel.com (103.31.144.1)  4.287 ms  4.063 ms  4.166 ms
Location: Virār, Maharashtra, India, Asia
Zip: 401303, Coordinates: 19.466700,72.800003

 4  26-69-245-103.dnainfotel.com (103.245.69.26)  6.168 ms  7.008 ms  6.620 ms
Location: Saint Thomas Mount, Tamil Nadu, India, Asia
Zip: 600001, Coordinates: 13.052400,80.250801

 5  52.46.166.32 (52.46.166.32)  4.609 ms  4.869 ms  4.809 ms
Location: Ashburn, Virginia, United States, North America
Zip: 20147, Coordinates: 39.043701,-77.474197

 6  52.95.67.22 (52.95.67.22)  12.384 ms 52.95.67.66 (52.95.67.66)  4.752 ms 52.95.67.22 (52.95.67.22)  14.081 ms
Location: Powai, Maharashtra, India, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

 7  52.95.64.196 (52.95.64.196)  9.312 ms 52.95.64.248 (52.95.64.248)  9.294 ms 52.95.64.252 (52.95.64.252)  9.275 ms
Location: Powai, Maharashtra, India, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

 8  52.95.64.195 (52.95.64.195)  12.942 ms 52.95.64.211 (52.95.64.211)  12.917 ms 52.95.64.253 (52.95.64.253)  8.346 ms
Location: Powai, Maharashtra, India, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

 9  52.95.67.127 (52.95.67.127)  12.874 ms 52.95.67.39 (52.95.67.39)  12.853 ms 52.95.67.17 (52.95.67.17)  12.831 ms
Location: Powai, Maharashtra, India, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

10  52.95.67.178 (52.95.67.178)  9.119 ms 52.95.67.182 (52.95.67.182)  8.238 ms 52.95.65.135 (52.95.65.135)  10.045 ms
Location: Powai, Maharashtra, India, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

11  * * *
12  * * *
13  * * *
14  * * *
15  * * *
```

## How does it work ?

`locate_route` parses the output from traceroute to find all the ip addresses and then
uses the API provided by https://ipstack.com/ to determine the location.

## Dependencies

C++17 and CMake 3.15

* [argh](https://github.com/adishavit/argh) for setting up the CLI
* [cpp-httplib](https://github.com/yhirose/cpp-httplib) for http requests
* [nlohmann/json](https://github.com/nlohmann/json) for parsing JSON

## LICENSE
Copyright (c) **Junaid Rahim**. All rights reserved.

Licensed under the [MIT](LICENSE) License

<br>

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)
 
