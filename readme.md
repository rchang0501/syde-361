# SYDE 361

This repo contains code for the SYDE 361 Needs Analysis and Prototyping Course.

## Solution Optimizer
### Prompt
I am a student building an electric generator that turns flowing water into electricity. I have performed a functional decomposition of the system. I now need to find solutions on how to implement each function of the system.


Given the list of provided functions, generate a list of 4 solutions to accomplish each.

For each solution, assign an effectiveness score and a cost score. 

The effectiveness score should be on a scale of 1 - 10. It denotes how capable it is of solving the objective.

The cost score should be the cost in dollars of each item.

Only choose items with a cost of at most $25. 

Solutions should also be items that are easily accessible to students.

Finally, enumerate the solutions for each function into a vector of pairs.

EXAMPLE:
Function: Track position of person

Solutions: 
1. RFID tag worn by shooter, effectiveness: 5, cost: 10 
2. Motion sensor, effectiveness: 10, cost: 50
3. Optical sensor, effectiveness: 7, cost: 25
4. Acoustic sensor, effectiveness: 3, cost: 30

{{5, 10}, {10, 50}, {7, 25}, {3, 30}}

TEMPLATE:
Function: 

Solutions: 
1. ______, effectiveness: __, cost: __ 
2. ______, effectiveness: __, cost: __ 
3. ______, effectiveness: __, cost: __ 
4. ______, effectiveness: __, cost: __ 

{{_, _}, {_, _}, {_, _}, {_, _}}


Objective: Pump water through pipe
Objective: Change of direction of water
Objective: Increase or decrease flow rate
Objective: Spin turbine
Objective: Discharge water back into well
Objective: Rotate motor
Objective: Convert AC to DC
Objective: Store electricity
Objective:  Power USB device

### Algorithm
Using the above schema we choose the highest effectiveness score combination. We also track the cost to make sure it's not out of budget.

### solutions.txt
This file contains all the combinations of solutions. The first column is the effectiveness. The second column is cost. The third column are the items.
