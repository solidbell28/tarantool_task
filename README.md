# Tarantool Task
Solution of my Tarantool Lab case.

Problem description: the input to the program is an array of integers reflecting the height of the land at this point. All the space where water could linger is filled with water. The program should output the number of points filled with water.

Solution idea: to count for each height (from 1 to maximum) the number of blocks between the leftmost and the rightmost points with the curtain height and then to subtract the overall amount of blocks of land because they were not taken into account during the previous calculations.

Solution provided in C language.
