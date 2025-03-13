NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

SRC_FILES = pipex.c pipex_utils.c pipex_helper.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

LIBFT_FILES = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_FILES:.c=.o)

PRINTF_FILES = $(wildcard $(PRINTF_DIR)/*.c)
PRINTF_OBJS = $(PRINTF_FILES:.c=.o)

OBJS = $(SRCS:.c=.o) $(LIBFT_OBJS) $(PRINTF_OBJS)

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) *.o

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re