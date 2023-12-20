NAME		= minishell
MKF			= Makefile

# Sources
SRC			= main.c \
			minishell.c \
			get_input.c \
			open_file.c \
			parse_tokens.c \
			quote_utils.c \
			signal_utils.c \
			token.c \
			tokenize.c \
			arrstr/arrstr_add.c \
			arrstr/arrstr_dup.c \
			arrstr/arrstr_free.c \
			arrstr/arrstr_rm.c \
			arrstr/arrstr_set.c \
			arrstr/arrstr_size.c \
			basic_utils/utils_arr.c \
			basic_utils/utils_atoll.c \
			basic_utils/utils_char.c \
			basic_utils/utils_itoa.c \
			basic_utils/utils_p_malloc.c \
			basic_utils/utils_putstr.c \
			basic_utils/utils_restore_exit.c \
			basic_utils/utils_split.c \
			basic_utils/utils_str.c \
			basic_utils/utils_strjoin.c \
			basic_utils/utils_strjoin_free.c \
			basic_utils/utils_strlcat.c \
			basic_utils/utils_substr.c \
			builtins/builtin_utils.c \
			builtins/cd.c \
			builtins/echo.c \
			builtins/env.c \
			builtins/exit.c \
			builtins/export.c \
			builtins/pwd.c \
			builtins/unset.c \
			env/env_find.c \
			env/env_get.c \
			env/env_set.c \
			env/env_utils.c \
			execute/exec_cmd.c \
			execute/execute_builtin.c \
			execute/execute_command.c \
			execute/get_args_from_cmd.c \
			expand_and_split/expand_and_split.c \
			expand_and_split/expand.c \
			expand_and_split/normalize.c \
			expand_and_split/remove_quotes.c \
			expand_and_split/split_words.c \
			input_utils/is_blankchr.c \
			input_utils/is_metachr.c \
			input_utils/is_operatorchr.c \
			input_utils/is_quotechr.c \
			input_utils/is_redirectionchr.c \
			input_utils/is_word.c \
			list/lst_add.c \
			list/lst_add_many.c \
			list/lst_clear.c \
			list/lst_delone.c \
			list/lst_first.c \
			list/lst_last.c \
			list/lst_link.c \
			list/lst_move.c \
			list/lst_new.c \
			list/lst_rm_many.c \
			list/lst_rm_one.c \
			list/lst_size.c \
			list/lst_split.c \
			print_error/print_err_builtin.c \
			print_error/print_err_exec.c \
			print_error/print_err_misc.c \
			redirect/clear_heredoc.c \
			redirect/clear_heredocs.c \
			redirect/delim_quote_remove.c \
			redirect/expand_vars.c \
			redirect/has_quotes.c \
			redirect/heredoc_filename.c \
			redirect/link_heredoc.c \
			redirect/link_input_file.c \
			redirect/link_output_file.c \
			redirect/read_heredoc.c \
			redirect/read_heredocs.c \
			redirect/redirect.c \
			redirect/save_restore_stdio.c \
			redirect_and_execute/fork_or_die.c \
			redirect_and_execute/link_read_end.c \
			redirect_and_execute/link_write_end.c \
			redirect_and_execute/pipe_or_die.c \
			redirect_and_execute/read_all_heredocs.c \
			redirect_and_execute/redirect_and_execute.c \
			redirect_and_execute/wait_children.c \
			xchar/str_to_xclst.c \
			xchar/xc_get.c \
			xchar/xc_new.c \
			xchar/xclst_to_str.c \
			xtoken/tok_to_xtok.c \
			xtoken/xtok_add_many.c \
			xtoken/xtok_addc.c \
			xtoken/xtok_adds.c \
			xtoken/xtok_addxc.c \
			xtoken/xtok_get.c \
			xtoken/xtok_rm_many.c \
			xtoken/xtok_rm_one.c \
			xtoken/xtok_rm_xcs.c \
			xtoken/xtok_strncmp.c \
			xtoken/xtok_to_tok.c \
			xtoken/xtoklst_clear.c \
			debug.c						# TODO: Remove before submitting

DEPDIRS		= $(DEPDIR)arrstr/ \
			$(DEPDIR)basic_utils/ \
			$(DEPDIR)builtins/ \
			$(DEPDIR)env/ \
			$(DEPDIR)expand_and_split/ \
			$(DEPDIR)get_next_line/ \
			$(DEPDIR)list/ \
			$(DEPDIR)redirect_and_execute/ \
			$(DEPDIR)xtoken/

SRCDIR		= src/
SRCS		= $(addprefix $(SRCDIR), $(SRC))

# Objects
OBJDIR		= .obj/
OBJS		= $(addprefix $(OBJDIR), $(SRC:.c=.o))

# Libraries
RL_LIB		= readline/
INCFLAG		:= -I $(RL_LIB)
READLINE	:= $(RL_LIB)libreadline.a $(RL_LIB)libhistory.a

# Dependencies
DEPDIR		= .dep/
DEPS		= $(addprefix $(DEPDIR), $(SRC:.c=.d))

# Includes
INCDIR		= inc/
INCFLAG		+= -I $(INCDIR)

LIBS		= -lreadline -ltermcap
RM			= rm -fr
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
DEFS		= -DREADLINE_LIBRARY
DFLAGS		= -MT $@ -MMD -MP
XFLAGS		= -fsanitize=address

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

all:		$(READLINE) $(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.c $(MKF)
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(XFLAGS) $(DEFS) $(DFLAGS) $(INCFLAG) -c $< -o $@ 
			@printf "\r\t$(YELLOW)$< $(GREEN)compiled$(DEFAULT)                             \r"
#			@mkdir -p $(DEPDIR) $(DEPDIRS)
#			@mv $(OBJDIR)*.d $(DEPDIR)

$(NAME)::	$(OBJS) $(MKF) $(READLINE)
			@$(CC) $(CFLAGS) $(XFLAGS) $(DEFS) $(LIBS) $(READLINE) $(OBJS) -o $(NAME)  
			@echo "\n$(GREEN)[ $(BGREEN)MINISH $(GREEN)created! ]$(DEFAULT)"

$(NAME)::	
			@echo "$(BLUE)[ All done already ]$(DEFAULT)"

clean:
			@$(RM) $(OBJDIR) $(DEPDIR)
			@echo "$(BRED)[ Object files cleared ]$(DEFAULT)"

fclean:		clean
			@$(RM) $(NAME) $(READLINE)
			@echo "$(RED)[ All created files cleared ]$(DEFAULT)"

re:			fclean all
			@echo "$(BBLUE)[ All cleared and compiled ]$(DEFAULT)"

norm:
			@norminette $(SRCDIR)* $(INCDIR)*


$(READLINE): 
			@cd ./$(RL_LIB) && ./configure && make


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
