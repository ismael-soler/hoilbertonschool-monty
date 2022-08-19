#MontyByteCode Interpreter

##Description

This program is an interpreter for Monty ByteCode files, it will open the file and execute the instructions given inside. The program must be given only one argument, it being the name of the Monty file to be opened.

##Learning Objectives

- What do LIFO and FIFO mean
- What is a stack and a queue, and when to use them
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

##Instuctions it can handle:

- push: Pushes an element to the stack. The element must be an integer, otherwise it will exit with the status EXIT_FAILURE.
- pall: Prints all values of the stackstarting from the top. If the stack is empty it won't print anything.
- pint: Prints the value at the top of the stack followed by a new line. If the stack is empty, it will exit with the status EXIT_FAILURE.
- pop: Removes the top element of the stack. If the stack is empty, it will exit with the status EXIT_FAILURE.
- swap: Swaps the top two elements of the satck. If the stack has less than two elements 
, it will exit with the status EXIT_FAILURE.
- add: Adds up the top two elements of the stack, stores the result in the second top element, and deletes the top element of the stack. If stack has less than two elements, it will exit with the status EXIT_FAILURE.
- nop: Doesn't  do anything.

##Authors

- Ismael Soler
- Sebastian Lopez

:)
