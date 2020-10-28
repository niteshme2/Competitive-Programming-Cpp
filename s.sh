for((i = 1; ; ++i)); do
    echo $i
    ./gen.out $i > int
    ./a.out < int > out1
    ./brute.out < int > out2
    diff -w out1 out2 || break
    #diff -w <(./a < int) <(./brute < int) || break
done