#! /bin/bash

pkill wpa_supplicant

iw dev wlan0 interface add mesh0 type mp mesh_id mnet
ifconfig wlan0 down
ifconfig mesh0 up
