#variable
CC = cc  
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
C_libf = push_swap_utils.c\
         push_swap.c\
         push_swap_fonct.c\
         push_swap_fonct2.c\
         push_swap_algo.c\
         push_swap_algo2.c\
         push_swap_algo3.c\
         push_swap_algo4.c\
		 push_swap_algo5.c\
		 push_swap_algo6.c\
         push_swap_verif.c\
		 ft_split.c
LIB_OBJS = $(C_libf:.c=.o)

all: $(NAME)

#executable
$(NAME): $(LIB_OBJS)
	$(CC) $(CFLAGS) $(LIB_OBJS) -o $(NAME)

#to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#just remove the .o
clean:
	$(RM) $(LIB_OBJS) 

#remove all executables
fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re