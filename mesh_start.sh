#!/bin/bash

#Set IP
ip_prefix="10.1.1."
name=`hostname`
#ip_suffix="${name//[!0-9]/}"
ip_suffix="4"
ip_address=${ip_prefix}${ip_suffix}/24

sudo systemctl stop wpa_supplicant bb-wl18xx-wlan0.service

#Enable Mesh Node
iw dev wlan0 interface add mesh0 type mp mesh_id mnet
iw dev mesh0 set channel 1
ifconfig wlan0 down
ifconfig mesh0 up
ip addr add ${ip_address} dev mesh0

#Enable olsrd
/usr/sbin/olsrd -i mesh0 > /dev/null 2>&1






