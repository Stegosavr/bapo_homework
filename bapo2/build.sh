#!/bin/bash

gcc url_ip.c json/json.c net/net.c -I./ -lcurl -o ip
