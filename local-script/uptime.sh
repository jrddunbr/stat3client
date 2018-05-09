#!/bin/bash
DATA=$(uptime -p)
echo $DATA
./manage 128.153.145.62 2204 uptime "$DATA"
