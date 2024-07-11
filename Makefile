SERVER	:= server
CLIENT	:= client
CFLAGS	:= -Wextra -Wall -Werror -Ofast
INCLUDE := -I./lib/libft/libft.a -I./lib/printf/libftprintf.a
LIBS := -L./lib/libft -L./lib/printf -lft -lftprintf
SRCS	:= server.c client.c
OBJS	:= ${SRCS:.c=.o}

all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) && printf "Compiling: $(notdir $<)"
	@make -C lib/printf
	@make -C lib/libft

$(SERVER): server.o
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBS) -o $@

$(CLIENT): client.o
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBS) -o $@

clean:
	rm -rf *.o
	@make -C lib/libft clean
	@make -C lib/printf clean

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	@make -C lib/libft fclean
	@make -C lib/printf fclean

re: clean all


