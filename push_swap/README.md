# push_swap

## 조건

- 2 stacks named a and b
- The stack a contains a random amount of negaive and / or positive numbers which cannot be duplicated
- The stack b is empty

## 목표

- soring in ascending order numbers into stack a

## operations

- sa (swap a): Swap the first 2 t_elements at the top of stack a.
  Do nothing if there is only one or no t_elements.

- sb (swap b): Swap the first 2 t_elements at the top of stack b.
  Do nothing if there is only one or no t_elements.

- ss : sa and sb at the same time.

- pa (push a): Take the first t_element at the top of b and put it at the top of a.
  Do nothing if b is empty.

- pb (push b): Take the first t_element at the top of a and put it at the top of b.
  Do nothing if a is empty.

- ra (rotate a): Shift up all t_elements of stack a by 1.
  The first t_element becomes the last one.

- rb (rotate b): Shift up all t_elements of stack b by 1.
  The first t_element becomes the last one.

- rr : ra and rb at the same time.

- rra (reverse rotate a): Shift down all t_elements of stack a by 1.
  The last t_element becomes the first one.

- rrb (reverse rotate b): Shift down all t_elements of stack b by 1.
  The last t_element becomes the first one.

- rrr : rra and rrb at the same time.
