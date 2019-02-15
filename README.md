# printf
printf fucking

Take a look at the PDF to see what my implementation of printf can do.

Type in {COLORNAME} in order to change color of the output. Multiple colors can be used in a single output.
Take a look at the t_color table in the ft_printf.c file to see the color codes. There are 16 which represent the 16 possible ANSI colors.
Example: ft_printf("{BG}%sOHMAGERRR{P}YUCHANGE{O}%dWHATTHEFUCK\n", "dick", 69);

I've included a test file too. Clone this repository, and type in the command make in order to compile the printf library, as well as run the tests.

If you'd like, you can add more tests to the main.c test file. Pressing make will recompile the whole printf library as well as run the new main.c test file. 

If you don't want to wait though, then type in the command gcc main.c libftprintf.a to compile, and then ./a.out to execute
