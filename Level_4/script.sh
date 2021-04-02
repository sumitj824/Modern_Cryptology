rm -f cipher_pair.txt overall_input.txt
g++ gen_input_pair.cpp 
g++ input.cpp -o input.out
g++ read.cpp -o r.out
for i in {1..100}
do  
    echo "Doing  iteration ${i}"

    ./a.out > input_pair.txt
    ./input.out > in.txt
    ssh -tt student@65.0.124.36 < in.txt > out.txt 
    ./r.out < out.txt 
    rm  in.txt  out.txt input_pair.txt 
done

rm a.out r.out input.out
