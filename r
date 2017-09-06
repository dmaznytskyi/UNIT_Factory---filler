clear
rm -f test_out
touch test_out
make re
./resources/filler_vm -p1 ./filler -p2 ./resources/players/abanlin.filler -f resources/maps/map00
cat test_out
