DISKNAME="/dev/sda1"
DISKTOTALKB=$(df | grep $DISKNAME | awk {'print $2'})
DISKTOTALB="$((DISKTOTALKB * 1000 ))"
echo $DISKTOTALB
./manage 127.0.0.1 2204 disktotal $DISKTOTALB
