Take a look at the PDF to see what my implementation of printf can do. My goal with this project was to make my code as readable and concise as possible while respecting my school's formatting standard.

Type in {COLORNAME} in order to change color of the output. Multiple colors can be used in a single output. Take a look at the t_color table in the ft_printf.c file to see the color codes. There are 16 which represent the 16 possible ANSI colors. Example: ft_printf("{BG}%sOHMAGERRR{P}YUCHANGE{O}%dWHATTHEFUCK\n", "dick", 59);

Use ft_printf for normal printf function. Use ft_fprintf(fd, const *f, ...) if you want to write to a file descriptor.
