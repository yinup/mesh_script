#!/bin/bash

/lib/systemd/systemd-sysv-install enable dnsmasq

cp ./mesh-start.service  /etc/systemd/system/

systemctl daemon-reload

systemctl enable mesh-start
