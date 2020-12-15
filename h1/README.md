# README FILE for Manuel's VG101 homework 1

Created by Zhang Jingyan.



## Ex1. What a README file is and what it should contain. 

A README is a text file that **introduces and explains a project**. 

It contains information that is commonly required to understand what the project is about. 



## Ex5. Explain Eratosthenes's method and write an algorithm describing it.



### His method:

Eratosthenes knew that at local noon on the summer solstice (at the time of the longest day, about 21 June in the northern hemisphere) in Syene (modern Aswan, Egypt), the Sun was directly overhead – Syene was in fact slightly north of the tropic,which means that the angle of elevation of the Sun would be 90° ，and In Alexandria, **the angle of elevation of the Sun would be 83° or 7° **south of the zenith on June, 21.

Assuming that Alexandria was due north of Syene (in fact, Alexandria is on a more westerly longitude) he concluded, using geometry of parallel lines, that **the distance from Alexandria to Syene must be 7/360 of the total circumference of the Earth**. 360/7 is close to 1/50th of a circle, so Eratosthenes concluded that the Earth’s circumference was fifty times that distance.The distance between the cities was known from caravan travelings to be about 5,000 stadia. So the circumference was about 250,000 stadia.



### Algorithm: Calculate the Earth’s circumference C

**Input:**  the different angles x°,y° of elevation of the Sun in Syene and Alexandria at 21 July; the distance from Alexandria to Syene z 
**Output:**  the circumference of the Earth 
1.w=(x-y)/360 
2.C=z/w





## OJ SCORE: 50