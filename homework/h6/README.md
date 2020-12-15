# README for Homework 6

Written by Zhang Jingyan, 520370910005.



## How to run my code

First of all, you should open your **Powershell**.

Or you can use JOJ to test.



## Explain my choice of ex2.c

I use two structures, 

- one is for point P in Cartesian coordinates. The elements in the structure are real part and imaginary part.
- the other is for point P in Polar coordinates. The elements in the structure are radius `r` and the angle.

As we should convert them, it's better using two structures representing two coordinates.

For datatypes, I use `double`, because I include `<math.h>` , `M_PI` in it is double. Also because we need five decimals.



## Online research of ex7

a)   A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers. In simple words, a linked list consists of nodes where each node contains a data field and a reference(link) to the next node in the list.

b)   Applications of linked list:

- Dynamic memory allocation

- Performing arithmetic operations on long integers. (for example, Karatsuba's algorithm).

- Implement advanced data structures. (for example, Fibonacci Heap).

c) Kinds of linked list:

- Singly Linked List
- Doubly Linked List
- Circular Linked List
- Doubly Circular Linked List
- Header Linked List









### Reference

https://www.geeksforgeeks.org/applications-of-linked-list-data-structure/#:~:text=Applications%20of%20linked%20list%20data%20structure%201%20Implementation,arithmetic%20operations%20on%20long%20integers%20More%20items...%20



https://www.geeksforgeeks.org/types-of-linked-list/