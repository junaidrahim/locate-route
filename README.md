# `locate_route`

A command line tool to get location information for the `traceroute` hops.

## Usage

NOTE: Make sure you have `traceroute` already installed

```bash
$ locate_route github.com
traceroute to github.com (13.234.210.38), 30 hops max, 60 byte packets

 1  _gateway (192.168.0.1)  1.524 ms  3.033 ms  3.016 ms

 2  4-144-31-103.dnainfotel.com (103.31.144.4)  3.000 ms  2.985 ms  2.970 ms
Location: Virār, India, Maharashtra, Asia
Zip: 401303, Coordinates: 19.466700,72.800003

 3  1-144-31-103.dnainfotel.com (103.31.144.1)  4.028 ms  3.734 ms  3.999 ms
Location: Virār, India, Maharashtra, Asia
Zip: 401303, Coordinates: 19.466700,72.800003

 4  26-69-245-103.dnainfotel.com (103.245.69.26)  7.113 ms  6.550 ms  7.489 ms
Location: Saint Thomas Mount, India, Tamil Nadu, Asia
Zip: 600001, Coordinates: 13.052400,80.250801

 5  52.46.166.32 (52.46.166.32)  5.572 ms  5.557 ms  5.209 ms
Location: Ashburn, United States, Virginia, North America
Zip: 20147, Coordinates: 39.043701,-77.474197

 6  52.95.67.44 (52.95.67.44)  7.025 ms 52.95.67.22 (52.95.67.22)  6.164 ms 52.95.67.132 (52.95.67.132)  5.977 ms
Location: Powai, India, Maharashtra, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

 7  52.95.64.202 (52.95.64.202)  5.467 ms 52.95.64.192 (52.95.64.192)  5.451 ms 52.95.64.234 (52.95.64.234)  15.853 ms
Location: Powai, India, Maharashtra, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

 8  52.95.64.235 (52.95.64.235)  5.890 ms 52.95.64.215 (52.95.64.215)  29.960 ms 52.95.64.247 (52.95.64.247)  29.945 ms
Location: Powai, India, Maharashtra, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

 9  52.95.67.131 (52.95.67.131)  5.377 ms 52.95.67.153 (52.95.67.153)  5.362 ms  5.348 ms
Location: Powai, India, Maharashtra, Asia
Zip: 400070, Coordinates: 19.076000,72.877701

10  52.95.67.210 (52.95.67.210)  5.333 ms 52.95.65.151 (52.95.65.151)  5.319 ms 52.95.67.214 (52.95.67.214)  5.305 ms
Location: Powai, India, Maharashtra, Asia
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



