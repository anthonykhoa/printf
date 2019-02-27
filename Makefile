NAME = libftprintf.a

INCLUDES = ft_printf.h

DIR_O = temporary

SRCS = ft_printf.c set_attr.c di.c oux.c dubz.c csp.c oux_whash.c dubz_width.c

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS) 
	@RANLIB $(NAME)
	@echo "oheuhuehe libftprintf.a compilation.... COMPLETE! ᕕ( ᐛ )ᕗ"

$(DIR_O)/%.o: ./%.c
	@mkdir -p temporary
	@gcc -Werror -Wextra -Wall -I $(INCLUDES) -o $@ -c $<

clean:
	@make clean -C libft
	@rm -f $(OBJS)
	@rm -rf temporary

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)
	
re: fclean all

