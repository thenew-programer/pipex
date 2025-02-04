CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I $(HEAD)
LDFLAGS		= -L$(LIBFT_DIR) -lft
RM			= rm -rf

SRCS_DIR	= src
BSRCS_DIR	= bonus
OBJS_DIR	= obj
BOBJS_DIR	= bobj
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
HEAD		= inc

FILES		= err.c cmd.c dealloc.c exec.c here_doc.c init.c io.c \
			  main.c parser.c path.c pipex.h syscalls.c utils.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(FILES))
BSRCS		= $(addprefix $(BSRCS_DIR)/, $(FILES))
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
BOBJS		= $(patsubst $(BSRCS_DIR)/%.c, $(BOBJS_DIR)/%.o, $(BSRCS))

NAME		= pipex
BNAME		= pipex_bonus

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJS_DIR)/%.o:		$(SRCS_DIR)/%.c
			@mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
			@echo "Building libft"
			@make all bonus -C $(LIBFT_DIR)

bonus:		$(BNAME)

$(BNAME):	 $(BOBJS) $(LIBFT)
			$(CC) $(BOBJS) -o $(NAME) $(LDFLAGS)

$(BOBJS_DIR)/%.o:		$(BSRCS_DIR)/%.c
			@mkdir -p $(BOBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS_DIR)
			$(RM) $(BOBJS_DIR)
			@echo "Cleaning libft"
			@make clean -C $(LIBFT_DIR)

fclean:		clean
			$(RM) $(NAME)
			@echo "Fcleaning libft"
			@make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY: all clean fclean re bonus

# .SECONDARY: $(OBJS) $(BOBJS) $(LIBFT)
