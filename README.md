# Calculator with Stack

**Calculator with Stack** is a simple C program that acts as a calculator with support for storing operations in a stack structure (Last-In-First-Out). Users can perform basic arithmetic operations, undo the last operation, view the full history, and reset the calculator.

## Features

- Perform basic operations: `+`, `-`, `*`, `/`
- Stores each operation and result in a fixed-size stack
- Undo (pop) the last operation
- View all stored operations (stack history)
- Reset (clear) all operations

## Installation

No installation is required. You can compile and run the program using a standard C compiler like `gcc`.

### Compile

```c
gcc -o calcstack calcstack.c
```

### Run

```c
./calcstack
```

## Usage

Once compiled and running, the program provides a text-based menu:

```c
----- Main menu -----
1. Operate
2. Show all operations.
3. Undo last operation.
4. Clear all.
5. Exit
```

### Example

```c
Insert the first number: 5
Insert the second number: 2
Select the operation (+ - * /): *
5.00 * 2.00 = 10.00
```

You can then view or undo this operation from the menu.

## Code Structure

- Operation: Struct to hold a single calculation.
- History: Struct to manage a stack of operations.
- Core functions:
  - initialize(): Initializes or clears the history.
  - push(): Adds an operation to the stack.
  - pop(): Removes the last operation.
  - peek(): Views the last operation without removing.
  - isEmpty(): Checks if the stack is empty.
  - operate(): Handles user input and performs calculations.
  - showAll(): Displays all stored operations.
  - clearInputBuffer(): Cleans up invalid input from stdin.

## Contributing

Pull requests are welcome. If you’d like to improve the functionality (e.g., support for more operations, dynamic stack resizing, file save/load), feel free to fork the repo and submit a PR.

Please open an issue to discuss any major changes before implementation.

## License

[MIT](https://choosealicense.com/licenses/mit/)
