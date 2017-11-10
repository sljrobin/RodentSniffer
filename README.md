# RodentSniffer
[RodentSniffer] is a sniffer developed in C using [libpcap] with the main goal to give an in-depth understanding of the classical network protocols you are using everyday.

## Table of contents
* [Requirements]
* [Sniff the Network]
* [Usage & Options]
* [rosnlib]
* [License]

## Requirements
* [libpcap] to capture packets
* [gcc] to compile the project
* `root` privileges for packet collection

## Sniff the Network
* Download the repository: `git clone git://github.com/sljrobin/RodentSniffer`
* Clean the project with the [makefile]: `make clean`
* Compile using the [makefile]: `make all`

## Usage & Options
* __Usage__: `rosn <option>`
* __Options__
    * `-f <"filter">`: add a filter with the [pcap-filter syntax]
    * `-h`: print the help
    * `-l`: list the available devices
    * `-s <device>`: indicate the device to open
* __Exemples__
    * `rosn -s eth0`
    * `rosn -p -f "arp" -s eth0`
    * `rosn -h`
    * `rosn -l`
* __Note__: the order of the options matters
    * `-p`
    * `-f "<filter>"`
    * `-s <device>`

## rosnlib
The folder [`rosnlib/`] contains:
* [`boot/`]: boot checks as options management, getting the link-layer header type, etc.
* [`process/`]: the main loop function used for sniffing
* [`prots/`]: files which are handling the different protocols (Ethernet, ARP, IPv4, IPv6, TCP, etc.)
* [`utils/`]: miscellaneous elements as help or color printers

## License
[RodentSniffer] is distributed under the same terms as [libpcap] itself. See [libpcap license] for more information.

[`boot/`]: /rosnlib/boot "boot/"
[`process/`]: /rosnlib/process "process/"
[`prots/`]: /rosnlib/prots "prots/"
[`rosnlib/`]: /rosnlib "rosnlib/"
[`utils/`]: /rosnlib/utils "utils/"
[License]: /README.md#license "License"
[Requirements]: /README.md#requirements "Requirements"
[rosnlib]: /README.md#rosnlib "rosnlib"
[Sniff the Network]: /README.md#sniff-the-network "Sniff the Network"
[Usage & Options]: /README.md#usage--options "Usage & Options"

[gcc]: https://gcc.gnu.org/ "gcc"
[libpcap]: http://www.tcpdump.org/ "libpcap"
[libpcap license]: http://www.tcpdump.org/license.html "libpcap license"
[makefile]: /makefile "makefile"
[pcap-filter syntax]: http://www.tcpdump.org/manpages/pcap-filter.7.html "pcap-filter syntax"
[RodentSniffer]: / "RodentSniffer"
[RodentSniffer webpage]: http://work.sljrobin.com/rodentsniffer "RodentSniffer webpage"
