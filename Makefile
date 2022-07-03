NAME	=	poke_calc

CC	=	gcc -g

SRCS	=	main.c		\
		pokemon.c	\

OBJS	=	$(SRCS:.c=.c)

REMOVE	=	rm -rf

%.o: %.c
	$(CC) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(REMOVE) $(NAME)

fclean:
	$(REMOVE) $(NAME)
	$(REMOVE) $(NAME)
re:
	make fclean
	make
