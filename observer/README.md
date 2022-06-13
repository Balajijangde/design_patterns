# Observer pattern

## Problem

We can implement this design simply but then we have to ignore log of good practices in programming like: <br>

1. Observer and Subject has to be tightly coupled.
2. Subject will have access to whole Observer instead of having access to just its update method.
3. In future if we want to add more observers in subject we need to change its implementation.

## Solution

We can work on the below architecture. <br><br>
![](https://media.geeksforgeeks.org/wp-content/uploads/ObserverPatternSet-2.png)

1. Now observer and subject are loosely coupled.
2. Subject will only have access to observer's update method nothing else.
3. In future we can simply add a new observer to subject.
