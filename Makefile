# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -gdwarf-4

# Output binary name
NAME = pipex

# Directories
SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

# Source files
SRC_FILES = pipex.c pipex_utils.c pipex_helper.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Object files from libraries
LIBFT_FILES = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_FILES:.c=.o)

PRINTF_FILES = $(wildcard $(PRINTF_DIR)/*.c)
PRINTF_OBJS = $(PRINTF_FILES:.c=.o)

# All object files
OBJS = $(SRCS:.c=.o) $(LIBFT_OBJS) $(PRINTF_OBJS)

# Include paths
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Colors for terminal output
RESET = \033[0m
BOLD = \033[1m
NAVY = \033[34m        # Dark Blue (Navy)
PINK = \033[35m        # Pink (Magenta)
CYAN = \033[36m        # Cyan

# Emoticons
EMOJI_1 = .𖥔 ݁ ˖🛸── .✦
EMOJI_2 = ๋⭑🛸๋⭑
EMOJI_3 = 👽⋆｡°✩

# Default target: Compile everything
all: $(NAME)

# Link the object files to create the executable
$(NAME): $(OBJS)
	@echo "$(CYAN)$(EMOJI_1) Linking object files to create executable...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAVY)$(EMOJI_3) $(NAME) successfully created!$(RESET)"

# Rule to compile .c files into .o files
%.o: %.c
	@echo "$(PINK)$(EMOJI_2) Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(CYAN)$(EMOJI_3) Compiled $< successfully!$(RESET)"

# Clean up object files
clean:
	@echo "$(NAVY)$(EMOJI_1) Cleaning object files...$(RESET)"
	rm -f $(OBJS) $(LIBFT_DIR)/*.o $(PRINTF_DIR)/*.o
	@echo "$(CYAN)$(EMOJI_3) Object files cleaned!$(RESET)"

# Full clean (removes object files and the executable)
fclean: clean
	@echo "$(PINK)$(EMOJI_2) Removing the executable...$(RESET)"
	rm -f $(NAME)
	@echo "$(CYAN)$(EMOJI_3) Executable $(NAME) removed!$(RESET)"

# Rebuild everything (clean and then all)
re: fclean
	@echo "$(NAVY)$(EMOJI_1) Rebuilding everything...$(RESET)"
	$(MAKE) all

# Declare non-file targets to avoid conflicts
.PHONY: all clean fclean re
