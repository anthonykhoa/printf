woo:
	make re
	gcc -Werror -Wextra -Wall main.c libftprintf.a
	./a.out

NAME = libftprintf.a

INCLUDES = ft_printf.h

DIR_O = temporary

SRCS = ft_printf.c set_attr.c di.c oux.c dubz.c

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS) 
	RANLIB $(NAME)

$(DIR_O)/%.o: ./%.c
	@mkdir -p temporary
	@gcc -Werror -Wextra -Wall -I $(INCLUDES) -o $@ -c $<

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)
	

re: fclean all

