#! /bin/bash

pkill wpa_supplicant

iw dev wlan0 interface add mesh0 type mp mesh_id mnet
iw dev mesh0 set channel 1
ifconfig wlan0 down
ifconfig mesh0 up
ip addr add 10.1.100.10/24 dev mesh0
