# README for VG101 Homework 5

Written by Zhang Jingyan, 520370910005

### How to run ex5 and ex6

for ex5:

`gcc ex5.c -o ex5 -Wall -Wextra -Werror -Wpedantic`

Then three decks of cards will show on the command line.(with `\n` to distinguish each deck)



for ex6:

`gcc ex6.c -o ex6 -Wall -Wextra -Werror -Wpedantic`

Then it will show a formula like `a*b=c RAND_MAX`

If you add `#define TEST` in the code, there will be no output.



### Karatsuba algorithm

Input: two integer number a,b

Output: a*b

1. let a takes N positions in the storage; b takes M.

2. let n=N/2; m=M/2;

3. a = x1*2^n+x0; 

   b = y1*2^m+y0;

4. a*b

   = (x1*2^n+x0) * (y1*2^m+y0)

   = x1 * 2^n + y1 * 2^m + x0 * y1 * 2^m + x1 * y0 * 2^n + x0 * y0