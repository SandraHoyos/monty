# monty
Monty 0.98 is a scripting language that is first compiled into Monty byte codes, Just like Python. It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.


The monty program
Usage: monty file
where file is the path to the file containing Monty byte code.
If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE.
If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE.
where <file> is the name of the file.
If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE.
where <line_number> the line number where the instruction appears.
Line numbers always start at 1.
The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file.
it finds an error in the file.
an error occured.
If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
Output
Here are some examples of the output for th opcodes used.

The push opcode - The opcode push pushes an element to the stack.

Usage: push <int>.
where <int> is an integer.
The pall opcode

The opcode pall prints all the values on the stack, starting from the top of the stack.
Usage pall.
Format: see example.
If the stack is empty, don’t print anything.
