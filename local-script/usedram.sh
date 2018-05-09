read _1 MEMTOTALKB _2 <<< $(cat /proc/meminfo | grep MemTotal:)
read _1 MEMAVAILKB _2 <<< $(cat /proc/meminfo | grep MemAvail)
MEMUSEDB="$(((MEMTOTALKB - MEMAVAILKB) * 1000 ))"
echo $MEMUSEDB
./manage 127.0.0.1 2204 memused $MEMUSEDB
