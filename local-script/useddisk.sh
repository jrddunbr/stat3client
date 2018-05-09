DISKNAME="/dev/sda1"
DISKUSEDKB=$(df | grep $DISKNAME | awk {'print $3'})
DISKUSEDB="$((DISKUSEDKB * 1000 ))"
echo $DISKUSEDB
./manage 127.0.0.1 2204 diskused $DISKUSEDB
