if [ ! -f numbers.txt ]
then
    touch numbers.txt
    max=10
    for i in `seq 1 $max`
    do
      echo "$i" >> numbers.txt
    done
fi
ln numbers.txt numbers.txt.lock
LAST=`tail -1 numbers.txt`
LAST=$((LAST+1))
echo "$LAST" >> numbers.txt
rm numbers.txt.lock
