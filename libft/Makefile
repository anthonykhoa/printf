NAME = libft.a

INCLUDES = libft.h

DIR_O = temporary

SRCS = ft_memmove.c ft_memset.c ft_strdup.c ft_strlen.c ft_isdigit.c ft_memalloc.c ft_strnequ.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c hidden_c.c hidden_c2.c ft_atoull.c ft_lltoa.c find_c.c remove_c.c strequ.c fill_str.c insert_c.c rem_c.c hidden_c3.c replace_c.c sub_str.c rev_str.c base16x.c base16xl.c base8.c push_str.c potato.c ft_pow.c str_chop.c hidden_c4.c str_chop2.c round_potato.c potato_magic.c ft_maxtoa.c ft_umaxtoa.c

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@RANLIB $(NAME)
	@echo "libft.a compilation...COMPLETE! (✿◠‿◠)"

$(DIR_O)/%.o: ./%.c
	@mkdir -p temporary
	@gcc -Werror -Wextra -Wall -I $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf temporary

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
