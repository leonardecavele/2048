# structure
NAME = 2048
LIBFT_A = $(LIBFT_DIR)/libft.a

# directories 
SRCS_DIR = srcs
INC_DIR = includes
BUILD_DIR = build
LIBFT_DIR = libft

# flags
CC = cc
CFLAGS = -MMD -MP -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR)/includes
LINK := -lncurses

# files
SRCS = \
	main.c \
	error.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

# rules
all: $(NAME)

$(NAME): $(OBJS) | libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LINK) -o $@

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean
	@$(MAKE) all --no-print-directory

libft:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

# miscellaneous
.PHONY: all clean fclean re libft
-include $(DEPS)
