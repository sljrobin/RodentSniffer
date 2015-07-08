## Makefile
## Description: a makefile for the RodentSniffer project
## Author: Simon L. J. Robin - http://sljrobin.com
## Usage: make <option>
################################################################################

CC=gcc
CFLAGS=-c -Wall
PCAP=-lpcap
LIBDIR=./rosnlib/
LIBBOOT=$(LIBDIR)boot/
LIBPROCESS=$(LIBDIR)process/
LIBPROTS=$(LIBDIR)prots/
LIBUTILS=$(LIBDIR)utils/

################################################################################

# Rule: All - Compile the project
all: main


# Rule: Clean - Delete the odd files
clean:
	rm -f rosn
	rm -f *.o
	rm -f $(LIBBOOT)*.o
	rm -f $(LIBPROCESS)*.o
	rm -f $(LIBPROTS)*.o
	rm -f $(LIBUTILS)*.o

################################################################################

# Source code: All
main: $(LIBUTILS)clrprnt.o $(LIBUTILS)help.o $(LIBUTILS)pkttime.o $(LIBBOOT)args.o $(LIBBOOT)ckid.o $(LIBBOOT)devs.o $(LIBBOOT)dtlnk.o $(LIBBOOT)header.o $(LIBPROTS)arp.o $(LIBPROTS)eth.o $(LIBPROTS)icmp.o $(LIBPROTS)ip.o $(LIBPROTS)tcp.o $(LIBPROTS)udp.o $(LIBPROCESS)sniff.o rosn.o
	$(CC) $(LIBUTILS)clrprnt.o $(LIBUTILS)help.o $(LIBUTILS)pkttime.o $(LIBBOOT)args.o $(LIBBOOT)ckid.o $(LIBBOOT)devs.o $(LIBBOOT)dtlnk.o $(LIBBOOT)header.o $(LIBPROTS)arp.o $(LIBPROTS)eth.o $(LIBPROTS)icmp.o $(LIBPROTS)ip.o $(LIBPROTS)tcp.o $(LIBPROTS)udp.o $(LIBPROCESS)sniff.o rosn.o $(PCAP) -o rosn


# Source code: Boot
args.o: $(LIBBOOT)args.c
	$(CC) $(CFLAGS) $(LIBBOOT)args.c

ckid.o: $(LIBBOOT)ckid.c
	$(CC) $(CFLAGS) $(LIBBOOT)ckid.c

devs.o: $(LIBBOOT)devs.c
	$(CC) $(CFLAGS) $(LIBBOOT)devs.c

dtlnk.o: $(LIBBOOT)dtlnk.c
	$(CC) $(CFLAGS) $(LIBBOOT)dtlnk.c

header.o: $(LIBBOOT)header.c
	$(CC) $(CFLAGS) $(LIBBOOT)header.c


# Source code: Main file
rosn.o: rosn.c
	$(CC) $(CFLAGS) rosn.c


# Source code: Process
sniff.o: $(LIBPROCESS)sniff.c
	$(CC) $(CFLAGS) $(LIBPROCESS)sniff.c


# Source code: Protocols
arp.o: $(LIBPROTS)arp.c
	$(CC) $(CFLAGS) $(LIBPROTS)arp.c

eth.o: $(LIBPROTS)eth.c
	$(CC) $(CFLAGS) $(LIBPROTS)eth.c

icmp.o: $(LIBPROTS)icmp.c
	$(CC) $(CFLAGS) $(LIBPROTS)icmp.c

ip.o: $(LIBPROTS)ip.c
	$(CC) $(CFLAGS) $(LIBPROTS)ip.c

tcp.o: $(LIBPROTS)tcp.c
	$(CC) $(CFLAGS) $(LIBPROTS)tcp.c

udp.o: $(LIBPROTS)udp.c
	$(CC) $(CFLAGS) $(LIBPROTS)udp.c


# Source code: Utils
clrprnt.o: $(LIBUTILS)clrprnt.c
	$(CC) $(CFLAGS) $(LIBUTILS)clrprnt.c

help.o: $(LIBUTILS)help.c
	$(CC) $(CFLAGS) $(LIBUTILS)help.c

pkttime.o: $(LIBUTILS)pkttime.c
	$(CC) $(CFLAGS) $(LIBUTILS)pkttime.c
