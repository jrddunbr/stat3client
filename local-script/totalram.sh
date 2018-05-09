read _1 MEMTOTALKB _2 <<< $(cat /proc/meminfo | grep MemTotal:)
MEMTOTALB="$((MEMTOTALKB * 1000 ))"
echo $MEMTOTALB
./manage 127.0.0.1 2204 memtotal $MEMTOTALB
