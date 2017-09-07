clear
rm -f test_out
touch test_out
make re
./resources/filler_vm -p2 ./filler -p1 ./resources/players/abanlin.filler -f resources/maps/map04
cat test_out
