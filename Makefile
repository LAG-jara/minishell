NAME		= minishell
MKF			= Makefile

# Sources
SRC			=	main.c \
				basic_utils/utils_char.c \
				basic_utils/utils_itoa.c \
				basic_utils/utils_p_malloc.c \
				basic_utils/utils_rm_at_indexes.c \
				basic_utils/utils_split.c \
				basic_utils/utils_str.c \
				arrstr/arrstr_fill_idx.c \
				arrstr/arrstr_add.c \
				arrstr/arrstr_dup.c \
				arrstr/arrstr_free.c \
				arrstr/arrstr_get_size.c \
				arrstr/arrstr_rm.c \
				arrstr/arrstr_set.c \
				env_find.c \
				env_get.c \
				env_set.c \
				expand_and_split.c \
				expand_vars.c \
				get_input.c \
				gnl_utils.c \
				input_utils.c \
				arrint.c \
				parse.c \
				print_error.c \
				quote_utils.c \
				remove_quotes.c \
				split_words.c \
				token_utils.c \
				tokenize.c \
				debug.c	# TODO: Remove debug utils
				
SRCDIR		= src/
SRCS		= $(addprefix $(SRCDIR), $(SRC))

# Objects
OBJDIR		= .obj/
OBJS		= $(addprefix $(OBJDIR), $(SRC:.c=.o))

# Libraries
RL_DIR		= readline/

# Dependencies
DEPDIR		= .dep/
DEPS		= $(addprefix $(DEPDIR), $(SRC:.c=.d))

# Includes
INCDIR		= inc/
INCFLAG		= -I $(INCDIR)

RM			= rm -fr
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RLFLAGS		= -lreadline
DFLAGS		= -MT $@ -MMD -MP
XFLAGS		= -fsanitize=address -g

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

all:		$(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.c $(MKF)
			@mkdir -p $(@D)
			@mkdir -p $(DEPDIR)
			@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ $(INCFLAG)
			@echo "$@ compiled"
			
# @mv $(OBJDIR)*.d $(DEPDIR)

$(NAME):	$(OBJS) $(MKF)
			@$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) -o $(NAME) $(INCFLAG) $(RLFLAGS) 
			@echo "$(BGREEN)$@ created!$(DEFAULT)\n"

clean:
			@$(RM) $(OBJDIR) $(DEPDIR)
			@echo "$(YELLOW)[ Object files cleared ]$(DEFAULT)"

fclean:		
			@$(RM) $(OBJDIR) $(NAME) $(DEPS)
			@echo "$(YELLOW)[ All created files cleared ]$(DEFAULT)"

re:			fclean all

norm:
			@norminette $(SRCDIR)* $(INCDIR)*

# rl_install:
# 			LIB_FOLDER=vendor

# 			mkdir $(LIB_FOLDER)

# 			TEMP_FOLDER=$(LIB_FOLDER)/.tmp_readline-install/
# 			READLINE_PATH=$(LIB_FOLDER)/readline/

# 			ARCHIVE=$(LIB_FOLDER)/readline-8.1.tar.gz
# 			INSTALLER=$(LIB_FOLDER)/readline-8.1
# 			BASEDIR=$(pwd)
# 			curl -k https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz > $ARCHIVE

# 			tar -xf $(ARCHIVE) -C $(LIB_FOLDER)/
# 			mkdir -p $(READLINE_PATH)
# 			cd $(READLINE_PATH)
# 			(READLINE_PATH)=$(pwd)
# 			cd $(BASEDIR)
# 			mkdir -p $(TEMP_FOLDER)

# 			cd $(TEMP_FOLDER)
# 			../../$(INSTALLER)/configure --prefix=$(READLINE_PATH)

# 			cd $(BASEDIR)
# 			make -C $(TEMP_FOLDER)
# 			make -C $(TEMP_FOLDER) install
# 			make -C $(TEMP_FOLDER) clean
# 			rm -rf $(TEMP_FOLDER) $(ARCHIVE) $(INSTALLER)

-include $(DEPS)

.PHONY: 	clean fclean re norm rl_install