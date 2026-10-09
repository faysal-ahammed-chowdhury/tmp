unset HISTFILE
g++ -O2 -std=c++17 -o a a.cpp
g++ -O2 -std=c++17 -o a_bruteforce a_bruteforce.cpp
g++ -O2 -std=c++17 -o randomTestGenerator randomTestGenerator.cpp
# g++ -O2 -std=c++17 -Wshadow -Wall -o a a.cpp
# g++ -O2 -std=c++17 -Wshadow -Wall -o a_bruteforce a_bruteforce.cpp
# g++ -O2 -std=c++17 -Wshadow -Wall -o randomTestGenerator randomTestGenerator.cpp

for((i = 1; ; ++i)); do
    ./randomTestGenerator $i > inputRandom.txt
    ./a <inputRandom.txt > outputMe.txt
    ./a_bruteforce <inputRandom.txt > outputBrute.txt
    diff -w outputMe.txt outputBrute.txt || break
    echo "Passed test: "  $i
done

echo -e "\nWA on the following test:"
cat inputRandom.txt
echo "Your answer is:"
cat outputMe.txt
echo "Correct answer is:"
cat outputBrute.txt