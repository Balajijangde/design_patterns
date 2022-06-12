# Factory design pattern

## Problem

Client had to select a vehicle type from its own and if we add a vehicle type than client code has to changed to get that vehicle.

## Solution

Client can't get a vehicle by himself instead they has access to a factory which give client a vehicle a/c to its passenger count, and its implementation should be abstract from client.
