#! /bin/sh


# This script is used to run the program. It is called by the
# creator so dont dare to question it


echo dupa > test.txt
../prog -i test.txt
../prog -c test.txt "dupa"
echo dupa >> test.txt
../prog -c test.txt "dupa dupa"

