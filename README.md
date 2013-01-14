ACSO Laboratory work 2
=========

Goal
-
  - make the output to screen easy:
  - implement putc (print a character at the current cursor position and increase the position of the cursor)
  - implement puts (print a caracter at the current cursor position, and advance the position of the cursor with the length of the string)
  - implement clrscr (clear the screen)
  - create a command prompt which can read and parse commands, and will respond to all commands with "you typed: <command>"
  - implement gets (get a string from keyboard)
  - when a command is typed, the output should be written below the command and the prompt should be moved below the output.

Reaching the goal
-
*video.c*

  - Let's get started with video.c file. Here we had to add a global variable (int i) which represents our current position in **vidmem**. Also, there are several helping functions to make the input/output process real. A brief description of the functions coming up.

    -  'int typer (char* vidmem, int pos, char* string)' - outputs the "You Typed: " message for inputs
    -  `int putc (char* vidmem, int pos, char c)` - outputs a single character to the screen.
    -  `int puts (char* vidmem, char* str, int pos)` - outputs an array of characters to the screen.
    -  `int clrscr(char* vidmem)` - clears all the screen.



  
    
