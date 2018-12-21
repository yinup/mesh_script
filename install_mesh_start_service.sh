#!/bin/bash

cp ./mesh-start.service  /etc/systemd/system/

systemctl daemon-reload

systemctl enable mesh-start
