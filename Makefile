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
		ft_split.c \
		printf/ft_choix.c \
		printf/ft_printf.c \
		printf/ft_putchar.c \
		printf/ft_puthex.c \
		printf/ft_puthexm.c \
		printf/ft_putnbr.c \
		printf/ft_putp.c \
		printf/ft_putstr.c \
		printf/ft_putuint.c \

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