#!/bin/sh
./arithoh.sh &
./syscall.sh &
./arithoh.sh &
wait
