SRCS = server.c client.c server_bonus.c client_bonus.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

client_bonus: client_bonus.o libft
	$(CC) -o $@ $< -Llibft -lft

server_bonus: server_bonus.o libft
	$(CC) -o $@ $< -Llibft -lft

bonus: server_bonus client_bonus

clean:
	rm -f $(OBJS)
	make -C libft clean
	
fclean: clean
	rm -f server client server_bonus client_bonus libft/libft.a

re: fclean all

.PHONY: all server_bonus clean_bonus libft clean fclean re bonus