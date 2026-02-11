# Balanced Parentheses Checker

This program checks whether an expression contains balanced parentheses, brackets, and braces using a stack data structure.

## Data Structures

The program uses a character array to implement a stack:

- **stack[MAX]**: A character array of size 100 that stores opening brackets as they are encountered in the expression.
- **top**: An integer variable that keeps track of the topmost element in the stack. It is initialized to -1, indicating an empty stack.
- **MAX**: A constant defined as 100, representing the maximum size of the stack.

The stack follows the Last-In-First-Out (LIFO) principle, where the most recently added element is removed first.

## Functions Implemented

### 1. `void push(char ch)`
**Purpose**: Adds a character to the top of the stack.

This function checks if there is space available in the stack. If the stack is not full, it increments the top pointer and places the character at that position. This function is used to push opening brackets onto the stack.

### 2. `char pop()`
**Purpose**: Removes and returns the character at the top of the stack.

This function checks if the stack is empty. If not, it returns the character at the current top position and decrements the top pointer. If the stack is empty, it returns the null character '\0'.

### 3. `int isMatching(char open, char close)`
**Purpose**: Checks if a pair of brackets match.

This function takes two characters as input - an opening bracket and a closing bracket. It returns 1 if they form a valid matching pair (such as '(' with ')', '{' with '}', or '[' with ']'), and returns 0 otherwise.

### 4. `int isBalanced(char expr[])`
**Purpose**: Determines whether the entire expression has balanced brackets.

This is the core function that processes the expression character by character. When it encounters an opening bracket, it pushes it onto the stack. When it encounters a closing bracket, it pops from the stack and checks if the popped bracket matches with the current closing bracket using the isMatching function. If at any point a closing bracket appears without a corresponding opening bracket, or if brackets don't match, the function returns 0. After processing all characters, it checks if the stack is empty - if yes, all brackets were balanced and it returns 1.

## Organization of main() Method

The main function is organized as follows:

1. **Variable Declaration**: A character array `expr` of size MAX is declared to store the input expression.

2. **User Input**: The program prompts the user to enter an expression and reads it using `fgets()`, which safely reads a line of input including spaces.

3. **Balance Check**: The `isBalanced()` function is called with the expression as an argument. This function returns 1 if the expression is balanced, 0 otherwise.

4. **Output Result**: Based on the return value, an appropriate message is displayed to inform the user whether the expression has balanced parentheses or not.

5. **Program Termination**: The function returns 0, indicating successful execution.

## Sample Output

### Run 1: Balanced Expression
```
Enter an expression: {[()]}
Expression has balanced parentheses.
```

### Run 2: Unbalanced Expression
```
Enter an expression: {[(])}
Expression does NOT have balanced parentheses.
```

### Run 3: Missing Closing Bracket
```
Enter an expression: ((a+b)
Expression does NOT have balanced parentheses.
```

### Run 4: Extra Closing Bracket
```
Enter an expression: (a+b))
Expression does NOT have balanced parentheses.
```

### Run 5: Complex Balanced Expression
```
Enter an expression: {a + [b * (c - d)] / e}
Expression has balanced parentheses.
```
