# README FOR MIDTERM

Written by Zhang Jingyan,520370910005;

### ex1 algorithm

Input: the bouncing time n; the size of square;

Output: nothing

Function:

1. use plot() to initiate the ball;

2. the location of ball(x,y) change with f(x); eg.@(x)x -->(x+a,y+a);

3. if

    x or y achieve the boundary of the square

   then 

   it bounce eg.(xnew-a,ynew+a);

end





### ex2 

Input: number 3 ; plate

Output: output.txt

Algorithm:



i=1;

function move(plate(i))

if  plate(i)< other plate && plate(i) is on the top

​	move plate;

else

​	move(plate(i+1));

end