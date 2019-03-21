NAME = libftprintf.a

DIR_O = temporary

SRCS = ft_printf.c set_attr.c di.c oux.c dubz.c csp.c oux_whash.c dubz_signs.c

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@RANLIB $(NAME)

$(DIR_O)/%.o: ./%.c
	@mkdir -p temporary
	@gcc -Werror -Wextra -Wall -o $@ -c $<

clean:
	@rm -rf temporary

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all