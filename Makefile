SRC = *.c ./libft/*.c
INC = ./libft/
OBJ = *.o 
NAME = libftprintf.a
all : $(NAME)

$(NAME):
		gcc -c $(SRC) -I $(INC)
		ar rc $(NAME) $(OBJ) 