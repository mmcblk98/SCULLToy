#!/bin/bash

module = "scullToy"
device = "scullToy"

mode = "664"		#Set the device mode 

/sbin/insmode ./$module.ko $* ||exit 1

rm -f /dev/$
