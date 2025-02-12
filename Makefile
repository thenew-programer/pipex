CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I$(HEAD)
LDFLAGS		= -L$(LIBFT_DIR) -lft
RM			= rm -rf

SRCS_DIR	= src
OBJS_DIR	= obj
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
HEAD		= inc

FILES		= err.c cmd.c dealloc.c exec.c here_doc.c init.c io.c \
			  main.c parser.c path.c pipex.h syscalls.c utils.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

NAME		= pipex

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJS_DIR)/%.o:		$(SRCS_DIR)/%.c
			@mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
			@echo "Building libft"
			@make all bonus -C $(LIBFT_DIR)

clean:
			$(RM) $(OBJS_DIR)
			@echo "Cleaning libft"
			@make clean -C $(LIBFT_DIR)

fclean:		clean
			$(RM) $(NAME)
			@echo "Fcleaning libft"
			@make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJS) $(LIBFT)
