ACSO Laboratory work 4
=========

Goal
-
  -Integrate setjmp and longjmp in your project.

Reaching the goal
-

 - We are given 2 files to work with, in other words, to integrate them in out project. [setjmp.asm](https://raw.github.com/gist/3969343/18ffb812722f2c44626200297fa01448e1ca343a/setjmp.asm) and [longjmp.c](https://raw.github.com/gist/3969339/552dce99630c7f17acdb33e603ced9afdb116994/longjmp.c)
 - We take the code from [setjmp.asm](https://raw.github.com/gist/3969343/18ffb812722f2c44626200297fa01448e1ca343a/setjmp.asm) and paste it directly in **loader.asm**
 - Next, we take the [longjmp.c](https://raw.github.com/gist/3969339/552dce99630c7f17acdb33e603ced9afdb116994/longjmp.c) file, and place it in **/lib** directory, also, we have to add a special structure in it, at the begining of the file.

`typedef struct
{
unsigned edi, esi, ebp, esp, ebx, edx, ecx, eax;
unsigned eip, eflags;
} jmp_buf[1];`

  - Now that we are finished, we call `make` in the main directory, and mount the image.
  - Run (at the moment there is no way to check how it works, in the next laboratory work we'll see).
