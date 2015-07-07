# RodentSniffer
[RodentSniffer] is a sniffer developped in C using [libpcap] with the main goal to give an in-depth understanding of the classical network protocols you are using everyday. Feel free to check out the [RodentSniffer webpage].

## Table of contents
* [Usage & Options]
* [Compiling]
* [License]

## Usage & Options
* __Usage__: `rosn <option>`
* __Options
    * `-f <"filter">`: add a filter with the [pcap-filter syntax]
    * `-h`: print the help
    * `-l`: list the available devices
    * `-s <device>`: indicate the device to open
* __Exemples__
    * `rosn -s eth0`
    * `rosn -p -f "arp" -s eth0`
* __Note__: the order of the options matters
    1. `-p`
    * `-f "<filter>"`
    * `-s <device>`

## Compiling
Use the [makefile] with the following commands:
* `make clean`
* `make all`

## License
This project is under the [BSD 2-Clause license].


[Usage & Options]: /README.md#usage-&-options "Usage & Options"
[Compiling]: /README.md#compiling "Compiling"
[License]: /README.md#license "License"

[BSD 2-Clause license]: http://opensource.org/licenses/BSD-2-Clause "BSD 2-Clause license"
[libpcap]: http://www.tcpdump.org/ "libpcap"
[makefile]: /makefile "makefile"
[pcap-filter syntax]: http://www.tcpdump.org/manpages/pcap-filter.7.html "pcap-filter syntax"
[RodentSniffer]: / "RodentSniffer"
[RodentSniffer webpage]: http://work.sljrobin.com/rodentsniffer "RodentSniffer webpage"
