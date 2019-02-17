# printf
printf fucking

Take a look at the PDF to see what my implementation of printf can do. My goal with this project was to make my code as readable and concise as possible while respecting my school's formatting standard.

Type in {COLORNAME} in order to change color of the output. Multiple colors can be used in a single output.
Take a look at the t_color table in the ft_printf.c file to see the color codes. There are 16 which represent the 16 possible ANSI colors.
Example: ft_printf("{BG}%sOHMAGERRR{P}YUCHANGE{O}%dWHATTHEFUCK\n", "dick", 69);

I've included a test file too. Clone this repository, and type in the command make in order to compile the printf library, as well as run the tests.

If you'd like, you can add more tests to the main.c test file. Pressing make will recompile the whole printf library as well as run the new main.c test file. 

If you don't want to wait though, then type in the command gcc main.c libftprintf.a to compile, and then ./a.out to execute

If you want the make command to only compile the libftprintf.a file without running the test file included, then delete the first 4 lines of the makefile.
