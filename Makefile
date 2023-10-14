NAME		= minishell
MKF			= Makefile

# Sources
SRC			=	main.c \
				env_get.c \
				env_set.c \
				get_input.c \
				tokenize.c \
				utils_char.c \
				utils_free.c \
				utils_str.c \
				utils_strarr.c
SRCDIR		= src/
SRCS		= $(addprefix $(SRCDIR), $(SRC))

# Objects
OBJDIR		= .obj/
OBJS		= $(addprefix $(OBJDIR), $(SRC:.c=.o))

# Libraries
RL_DIR	= readline/

# Dependencies
DEPDIR		= .dep/
DEPS		= $(addprefix $(DEPDIR), $(SRC:.c=.d))

# Includes
INC			=	-I ./includes/\

RM			= rm -fr
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RLFLAGS		= -lreadline
DFLAGS		= -MT $@ -MMD -MP
# XFLAGS		= -fsanitize=address -g

# Colors
WHITE		= \033[0;37m
GREEN		= \033[0;32m
RED			= \033[0;31m
BLUE		= \033[0;34m
YELLOW		= \033[0;33m
DEFAULT		= \033[0m
BGREEN		= \033[1;32m
BRED		= \033[1;31m
BBLUE		= \033[1;34m
BYELLOW		= \033[1;33m

all:		makelib $(NAME)

makelib:					# THIS IS UNTESTED
			cd $(RL_DIR)
			./configure --prefix=$(pwd)
			make
			make install
			cd ..

$(OBJDIR)%.o :	$(SRCDIR)%.c $(MKF)
			@mkdir -p $(@D)
			@mkdir -p $(DEPDIR)
			@$(CC) $(FLAGS) $(XFLAGS) $(DFLAGS) $(RLFLAGS) -c $< -o $@ $(INC)
			@echo "$@ compiled"
			@mv $(OBJDIR)*.d $(DEPDIR)

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(INC)
			@echo "$(BGREEN)$@ created!$(DEFAULT)\n"

$(NAME_B):	$(OBJS_B)
			@$(CC) $(OBJS_B) -o $(NAME_B) $(INC)
			@echo "$(BGREEN)$@ created!$(DEFAULT)\n"

clean:
			@$(RM) -fr $(OBJDIR) $(DEPDIR)
			@make clean -sC $(LIBFT_DIR)
			@echo "$(YELLOW)[ Object files cleared ]$(DEFAULT)"

fclean:		
			@$(RM) $(OBJDIR) $(NAME) $(DEPS)
			@make fclean -sC $(LIBFT_DIR)
			@echo "$(YELLOW)[ All created files cleared ]$(DEFAULT)"

re:			fclean all

norm:
			@norminette $(SRCDIR)* includes/*

-include $(DEPS)

.PHONY: 	clean fclean re norm makelib bonus