# Push_swap
<div align = "center">

<img src = "https://www.vangproperties.com/media/3830/42lisboa.jpg?preset=imageWithTextInsideText" alt = "42 lisbon img">

</div>

## About
The aim of this project is develop a sorting algorithm to organize a stack. We only can use 2 stacks and cannot duplicate the original, and also we only can use predifined operations. The aim of bonus part is create on checker.

## Mandatory

### Rules
- [x] Minimum use instructions as possible;
- [x] instructions separated by \n;
- [x] Should not print anything if the following tests are made:
    - [x] No parameter.
    - [x] Single numeric argument.
    - [x] The numbers are already sorted.

- [x] Error Message - `Error` follow by a new line if the following tests are made:
    - [x] Non-numeric parameters.
    - [x] Duplicate numeric parameter.
    - [x] Numeric parameter greater than INT_MAX.
    - [x] Numeric parameter less than INT_MIN.

- [x] Sorting **3 values**: no more than **3 actions**.
- [x] Sorting **5 values**: no more than **12 actions**.
- [x] Sorting **100 values**: **rating from 1 to 5 points** depending on the number of actions


#### Predifined operations:
- [x] `pa` **(push A)**: Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
- [x] `pb` **(push B)**: Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
- [x] `sa` **(swap A)**: Swap the first 2 elements at the top of stack A. Do nothing if there are only one or no elements.
- [x] `sb` **(swap B)**: Swap the first 2 elements at the top of stack B. Do nothing if there are only one or no elements.
- [x] `ss`: `sa` and `sb` at the same time.
- [x] `ra` **(rotate A)**: Shift all elements of stack A up by 1. The first element becomes the last one.
- [x] `rb` **(rotate B)**: Shift all elements of stack B up by 1. The first element becomes the last one.
- [x] `rr` : `ra` and `rb` at the same time.
- [x] `rra` **(reverse rotate A)**: Shift all elements of stack A down by 1. The last element becomes the first one.
- [x] `rrb` **(reverse rotate B)**: Shift all elements of stack b down by 1. The last element becomes the first one.
- [x] `rrr` : `rra` and `rrb` at the same time.


## Bonus
- [ ] Create a checker for push_swap that will read the program instructions and display `KO` or `OK`.

## Some Resources
https://github.com/duarte3333/Push_Swap
https://www.youtube.com/watch?v=OaG81sDEpVk
https://www.toptal.com/developers/sorting-algorithms
