

rm -f cipher.txt plaintext.txt
g++ generate_input.cpp 
g++ input.cpp -o input.out
g++ read.cpp -o r.out
for i in {1..1}
do  
    echo "Doing  iteration ${i}"

    ./a.out > plaintext.txt
    ./input.out > in.txt
     ssh -tt student@65.0.124.36 < in.txt > out.txt 
    ./r.out < out.txt 
    rm  in.txt  out.txt 
done

rm a.out r.out input.out

