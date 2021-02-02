# locate_route

A command line tool to get location information for the `traceroute` hops.

## Usage

NOTE: Make sure you have `traceroute` already installed

```bash
$ locate_route github.com
traceroute to github.com (13.234.176.102), 30 hops max, 60 byte packets

 1  _gateway (192.168.0.1)  0.956 ms  3.018 ms  3.002 ms

 2  4-144-31-103.dnainfotel.com (103.31.144.4)  2.986 ms  2.971 ms  2.956 ms
Location: Virār, Maharashtra, India, Asia
Zip: 401303, Coordinates: 19.466700,72.800003

 3  1-144-31-103.dnainfotel.com (103.31.144.1)  5.119 ms  5.493 ms  5.473 ms
Location: Virār, Maharashtra, India, Asia
Zip: 401303, Coordinates: 19.466700,72.800003

 4  26-69-245-103.dnainfotel.com (103.245.69.26)  7.137 ms  7.850 ms  7.460 ms
Location: Saint Thomas Mount, Tamil Nadu, India, Asia
Zip: 600001, Coordinates: 13.052400,80.250801

 5  52.46.166.32 (52.46.166.32)  5.264 ms  5.249 ms  5.234 ms
Location: Ashburn, Virginia, United States, North America
Zip: 20147, Coordinates: 39.043701,-77.474197

 6  52.95.67.132 (52.95.67.132)  6.218 ms 52.95.67.0 (52.95.67.0)  5.425 ms 52.95.67.66 (52.95.67.66)  8.803 ms
Cannot Determine Location
 7  52.95.64.200 (52.95.64.200)  8.258 ms 52.95.64.194 (52.95.64.194)  7.728 ms 52.95.64.248 (52.95.64.248)  14.031 ms
Location: Powai, Maharashtra, India, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

 8  52.95.64.243 (52.95.64.243)  9.400 ms 52.95.64.223 (52.95.64.223)  19.349 ms 52.95.64.225 (52.95.64.225)  8.690 ms
Location: Powai, Maharashtra, India, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

 9  52.95.67.61 (52.95.67.61)  40.869 ms 52.95.67.17 (52.95.67.17)  40.855 ms 52.95.67.149 (52.95.67.149)  40.839 ms
Location: Powai, Maharashtra, India, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

10  52.95.65.135 (52.95.65.135)  9.313 ms 52.95.67.182 (52.95.67.182)  13.609 ms 52.95.65.135 (52.95.65.135)  9.285 ms
Location: Powai, Maharashtra, India, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

11  * * *
12  * * *
13  * * *
14  * * *
15  * * *
16  * * *
17  * * *
18  * * *
19  * * *
20  * * *
21  * * *
22  * * *
23  * * *
24  * * *
25  * * *
26  * * *
27  * * *
28  * * *
29  * * *
30  * * *
```

## How does it work ?

`locate_route` parses the output from traceroute to find all the ip addresses and then
uses the API provided by https://ipstack.com/ to determine the location.

## Build and Install

1. `git clone https://github.com/junaidrahim/locate-route`
2. `mkdir build && cd build`
3. `cmake ..`
4. `make`

The binary `locate_route` will compile in the `build/` directory. You can run it from there,
or copy it into `/usr/local/bin` to access it from anywhere on your terminal.

I am working on publishing this as a snap package. 

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






 
