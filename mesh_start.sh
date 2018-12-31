#! /bin/bash

#Set IP
ip_prefix="10.1.1."
name=`hostname`
ip_suffix="${name//[!0-9]/}"
ip_address=${ip_prefix}${ip_suffix}/24


pkill wpa_supplicant

#Enable Mesh Node
iw dev wlan0 interface add mesh0 type mp mesh_id mnet
iw dev mesh0 set channel 1
ifconfig wlan0 down
ifconfig mesh0 up
ip addr add ${ip_address} dev mesh0

/home/debian/project/OONF/build/olsrd2_static -l /root/tools/mesh_script/olsrd.conf mesh0  > /root/olsr2.log 2>&1 &




