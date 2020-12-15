# README for Manuel's Homework 3

Written by Zhang Jingyan, 520370910005.

## How to run my code

#### ex1.

Only click `run` and the result will be displayed.



#### ex3.

It's  a function and only click `run` .

I think it's much easier using `input data` from excel. However, the JOJ engine can't recognize more than one file.



#### ex5.

1. Click `run`.
2. Input a function in the form of `@(x)`.  eg. `@(x)x^2-3*x+1`
3. Input an interval that contains the roots of the function. eg.`[0 1]`





## Algorithm for ex5.

**Input:**  an interval [x1,x2]

**Output:** the root r in 0.001 accuracy.

1. Determine x3=(x1+x2)/2.

2. If f(x3)*f(x1)==0, the root will be x3 or x1.

3. If f(x3)*f(x1)>0, x1<--x3, and 

   continue x3=(x1+x2)/2 until f(x3)*f(x1)==0. The same as <0 situations.

4. r= round(r,3) when format longg.