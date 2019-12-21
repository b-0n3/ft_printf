SRC = 	ft_atoi.c ft_isdigit.c ft_itoa.c ft_memcmp.c ft_print_char.c	ft_print_hex.c	ft_print_hex2.c 	ft_print_int.c 	ft_print_int2.c		ft_print_p.c 	ft_print_p2.c 		ft_print_string.c 	ft_print_string2.c ft_print_un.c 	ft_printf.c ft_memcpy.c	ft_printf2.c ft_putchar_fd.c 	ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c 
OBJ = ft_atoi.o ft_isdigit.o ft_itoa.o ft_memcmp.o ft_print_char.o	ft_print_hex.o	ft_print_hex2.o 	ft_print_int.o	ft_print_int2.o	ft_print_p.o 		ft_print_p2.o 		ft_print_string.o 	ft_print_string2.o ft_print_un.o 	ft_printf.o ft_memcpy.o	ft_printf2.o ft_putchar_fd.o 	ft_putstr_fd.o ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcpy.o ft_strlen.o 
NAME = libftprintf.a

all : $(NAME)

$(NAME):
		gcc -c -Wall -Wextra -Werror $(SRC) 
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
clean:
	rm -f $(OBJ)

fclean : clean 
	rm -f $(NAME)

re : fclean $(NAME)
