#variable
CC = cc  
CFLAGS = -Wall -Wextra -Werror
NAME = pushSwap.a
C_libf = push_swap_utils.c\
		 push_swap.c

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