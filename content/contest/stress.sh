g++ -o A A.cpp
g++ -o B B.cpp
g++ -o gen gen.cpp
for ((i = 1; ; ++i)); do  # if they are same then will loop forever
    echo $i
    ./gen $i > int
    ./A < int > out1
    ./B < int > out2
     diff -w <(./A < int) <(./B < int) || break
done
