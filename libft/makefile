NAME = libft.a

INCLUDES = libft.h

DIR_O = temporary

SRCS = ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strdup.c ft_strlen.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_sqrt.c get_next_line.c max.c min.c hidden_c.c hidden_c2.c ft_atoull.c ft_atoll.c ft_lltoa.c ft_ulltoa.c find_c.c match.c remove_c.c strequ.c found_u.c fill_str.c insert_c.c rem_c.c hidden_c3.c replace_c.c sub_str.c rev_str.c base16x.c base16xl.c base8.c push_str.c ft_ldtoa.c ft_pow.c str_chop.c hidden_c4.c

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	RANLIB $(NAME)

$(DIR_O)/%.o: ./%.c
	mkdir -p temporary
	gcc -Werror -Wextra -Wall -I $(INCLUDES) -o $@ -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
