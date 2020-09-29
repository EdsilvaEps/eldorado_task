# eldorado_task


## 1. Task 1:
D1 - Given an expression string exp, write a program to examine whether the pairs and the orders of parenthesis "(" and ")" are correct in exp.
For example, the program should print true for exp = ()(()) and false for exp = ())(

exp = "()(())"  answer: true
exp = "())("    answer: false

### 1.1. Code and execution
In this repository, the file `coding_task_1.cpp` refers to the first task and `task1` is its executable file. Examples of use are as follows:

```sh
$ ./task1 "()(()"
false
$ ./task1
digite o input ou (enter) para sair: "()()()"
true
digite o input ou (enter) para sair: "()(sometext)()"
true
digite o input ou (enter) para sair: 
false
$
```

## 2. Task 2: 
D2 - Given an array of integers, sort the array into a wave like array and return it.  In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5 ...

Given [1, 2, 3, 4]

One possible answer: [2, 1, 4, 3]

Another possible answer: [4, 1, 3, 2]

### 2.1. Code and execution
In this repository, the file `coding_task_2.cpp` refers to the first task and `task2` is its executable file. Examples of use are as follows:

```sh
$ ./task2 1 2 3 4 
seu array inicial: [1, 2, 3, 4]
array reorganizado: [2, 1, 4, 3]
$
$ ./task2 1 2 3 f
Numero invalido: f
$ 
```

