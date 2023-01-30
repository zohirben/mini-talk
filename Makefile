SRCS = server.c client.c unit_tools.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = server_bonus.o client_bonus.o unit_tools.o

SERVER_NAME = server
CLIENT_NAME = client
BONUS_SERVER_NAME = server_bonus
BONUS_CLIENT_NAME = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF = ft_printf/
FT_PRINTF_A = $(FT_PRINTF)libftprintf.a

.PHONY: all clean fclean re ft_printf bonus

all: ft_printf $(SERVER_NAME) $(CLIENT_NAME)

ft_printf:
	make -C $(FT_PRINTF)

$(SERVER_NAME): server.o unit_tools.o $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $^ -o $(SERVER_NAME)

$(CLIENT_NAME): client.o unit_tools.o $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $^ -o $(CLIENT_NAME)

bonus: ft_printf $(BONUS_SERVER_NAME) $(BONUS_CLIENT_NAME)

$(BONUS_SERVER_NAME): server_bonus.o unit_tools.o $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $^ -o $(BONUS_SERVER_NAME)

$(BONUS_CLIENT_NAME): client_bonus.o unit_tools.o $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $^ -o $(BONUS_CLIENT_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(FT_PRINTF) clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME) $(BONUS_SERVER_NAME) $(BONUS_CLIENT_NAME)
	make -C $(FT_PRINTF) fclean

re: fclean all
