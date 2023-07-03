<h1 align="center">
	Push_Swap
</h1>

<p align="center">
	<b><i>42 CURSUS PUSH_SWAP PROJECT</i></b><br>
</p>

## 💡 About the project

This project consists of creating a program, which orders a string of numbers, with specific movements with two stacks

## Instruction set

For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | Swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | Swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | Both `sa` and `sb`                                     |
| `pa`  | push a                              | Moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | Moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | Shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | Shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | Both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | Shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | Shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | Both `rra` and `rrb`                                   |

## Algorithm

I revise the numbers quantity that are passed to the program, with this options:
-  Two numbers: for two numbers I revise if is sorted, and if isn't sorted realise the movement `sa`.
-  Three Numbers: for three numbers only exist the next options:
  
      |  Case    | Actions                         |
      | -------- | ------------------------------- |
      | `1 2 3`  | No Actions                      |
      | `1 3 2`  | `rra` -> 2 1 3 -> `sa` -> 1 2 3 |
      | `2 1 3`  | `sa` -> 1 2 3                   |
      | `2 3 1`  | `rra` -> 1 2 3                  |
      | `3 2 1`  | `ra` -> 1 2 3                   |
      | `3 1 2`  | `ra` -> 2 1 3 -> `sa` -> 1 2 3  |
-  More Numbers:
   - We sort three elements separately because there are only five possible cases, excluding the one case where the numbers are already sorted, and this way, we ensure that it's sorted in two moves or fewer. Also, we make a previous ordenation pushing first the ones with smaller indixes.
   - We sort the 3 numbers left in stack A. With these three values in order, all we need to do is insert each element in stack B at the right position in stack A.
   - Finding the current position withing the stack.
   - Finding the target postion, where an element of stack B needs to be in stack A. We can spot this target position simply by scanning stack A for the closest superior index to the one of the stack B element. This is important because we will be able to determine how many actions it will take to get each stack in the right position for each element.
   - Calculating cost in Stack A and Stack B to determine how many actions are needed to move the stacks to their correct positions. In addition, we divide both stack in two halves because we're going to do rotate for the top half and reverse rotate for the bottom. Futhermore, we will make the cost of reverse rotate negative so that when we have to make the movements, we know immediately which rotate to make just by looking at the sign.
   - Choosing the cheapest cost.
   - Executing the chosen sequence of actions. If both costs are positive, we rotate both stacks to save moves until one of them reaches 0. Otherwise, if both cost are negative, we must do reverse rotate in both stack as we have done previously. When one of the cost becomes 0 means that we don't have to make more moves in one stack, so we make the aproppiate moves (rotate or reverse) in the other stack.
   - Shift the already sorted stack_a but getting it in the rigth position.


## Bonus
The bonus part is to write a program named checker, which will get as an argument the stack A formatted as a list of integers. Checker will then wait and read instructions on the standard input. Once all the instructions have been read, checker will execute them on the stack received as an argument (After giving the instructions press CTRL + D).

If after executing those instructions, stack a is actually sorted and b is empty, then checker must display "OK" else "KO". If checker arguments are invalid it displays Error.
