NAME = push_swap

SRC = algo.c \
		check.c \
		compteur.c \
		free.c \
		main.c \
		moveif.c \
		pre_tri.c \
		print.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		tri_3_5.c \
		utils.c \
		utils2.c \
		utils3.c \

OBJS = $(SRC:.c=.o)

CFLAGS = -Wextra -Wall -Wall 

CC = cc


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re 