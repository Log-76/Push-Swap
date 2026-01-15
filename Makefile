#variable
CC = cc  
CFLAGS = -Wall -Wextra -Werror
NAME = pushSwap.a
C_libf = push_swap_utils.c\
		 push_swap.c\
		 push_swap_fonct.c\
		 push_swap_fonct2.c\
		 push_swap_algo.c\
		 push_swap_algo2.c\
		 push_swap_algo3.c\
		 push_swap_algo4.c\
		 push_swap_verif.c

LIB_OBJS =  $(C_libf:.c=.o)
all: $(NAME)

#archive
$(NAME): $(LIB_OBJS)
	ar rc $(NAME) $(LIB_OBJS) 
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