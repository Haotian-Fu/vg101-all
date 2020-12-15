# README for Homework 8

Written by Zhang Jingyan, 520370910005



## How to run my code

#### ex1.

Go to pass JOJ

if you want to stop input, press  `Ctrl+Z` or `Ctrl+C`

#### ex2.

For Windows:

```text
g++ -O2 -Wall -Werror -Wpedantic -Wextra -Wconversion -Wvla -g -o ex2 -std=c++17 ex2.cpp -lglu32 -lfreeglut -lopengl32
./ex2.exe
```



For Linux:

```text
g++ -Wall -Werror -Wpedantic -Wextra -Wconversion -Wvla -std=c++17 -o ex2 ex2.cpp -lglut -lGL -lGLU
./ex2
```

#### ex3.
For Windows:

```text
g++ -O2 -Wall -Werror -Wpedantic -Wextra -Wconversion -Wvla -g -o ex2 -std=c++17 ex2.cpp -lglu32 -lfreeglut -lopengl32
./ex2.exe
```



For Linux:

```text
g++ -Wall -Werror -Wpedantic -Wextra -Wconversion -Wvla -std=c++17 -o ex2 ex2.cpp -lglut -lGL -lGLU
./ex2
```



## ex1 BEST CHOICE

The best way for both parts is to use `std::vector<string>`. Because it can store the string you input, and output it easily for both ordered and reversed. Vector also doesn't need deletion, as it may cost more time.



