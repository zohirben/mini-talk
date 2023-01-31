SRCS = server.c client.c unit_tools.c
BONUS_SRCS = server_bonus.c client_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

SERVER_OBJS = server.o unit_tools.o
CLIENT_OBJS = client.o unit_tools.o

SERVER_BONUS_OBJS = server_bonus.o unit_tools.o
CLIENT_BONUS_OBJS = client_bonus.o unit_tools.o

SERVER_NAME = server
CLIENT_NAME = client

SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF = ft_printf/
FT_PRINTF_A = $(FT_PRINTF)libftprintf.a

.PHONY: all clean fclean re ft_printf bonus

all: ft_printf $(SERVER_NAME) $(CLIENT_NAME)

ft_printf:
	make -C $(FT_PRINTF)

$(SERVER_NAME): $(SERVER_OBJS) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(FT_PRINTF_A) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(FT_PRINTF_A) -o $(CLIENT_NAME)

$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJS) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(FT_PRINTF_A) -o $(SERVER_BONUS_NAME)

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_OBJS) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(FT_PRINTF_A) -o $(CLIENT_BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(FT_PRINTF) clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)
	make -C $(FT_PRINTF) fclean

bonus: ft_printf $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

re: fclean all
