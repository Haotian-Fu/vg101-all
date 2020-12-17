# README for Manuel's project1 milestone3

Written by Zhang Jingyan，520370910005

## How to run my code
0. Put all the files into one directory. Maybe you need download Simulink to use some functions.

1. open main.m

2. click `run`

3. Select the difficulty in `Easy` , `Hard` , `Customize`.

   In `Customize` difficulty, you need to input parameters by yourself.

**if there's crash, 'You lose' will appear on the screen. If there's no crash and all cars passed,'You win' will appear on the screen. **



## My Algorithm for Ex1.-3:

**Input: ** 

1. number of cars  `n`
2. the time for green/red/orange lights  `g,r,o`
3. the probability that a cars does not stop at the red light `p`

**Output: ** nothing

**Algorithm: ** 

1. [up,dw,lf,rg] <--car1(n) ; function car1(n) makes up,dw,lf <-- `ceil((n/2)*rand)` & `rg>0`

   up means from the upper, dw means from the down, lf -->left, rg -->right.

2. use `while true` to count time `counting'`, relating to the true time.

3. function a  status to tell cars whether to move or stop.

4. initialize the lights(color,interval) and give the three situation of lights three status.

5. initialize cars(position, direction, color,size,plate)

6. draw lights based on `counting`.

7. move(car) when the status ==1 or 3, while judge if the car will jump the red light.

8. if one car stops at the cross, the following cars need to stop.

9. when all the cars have moved or stopped, then draw(car).

10. pause 0.1 second and come into the next iteration.

## Features

1. There's more realistic cars of various sizes
2. There's three difficulties that you can choose.