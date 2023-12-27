NAME		= minishell
MKF			= Makefile

# Sources
SRC			= main.c \
			minishell/minish_loop.c \
			minishell/print_welcome_msg.c \
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
			env/env_find_var_index.c \
			env/env_find_var_line.c \
			env/env_get_var.c \
			env/env_get_varname.c \
			env/env_get_vars.c \
			env/env_name_len.c \
			env/env_rm_var.c \
			env/env_set_var.c \
			env/env_valid_varname.c \
			execute/can_execute.c \
			execute/exec_cmd.c \
			execute/execute_builtin.c \
			execute/execute_command.c \
			execute/get_args_from_cmd.c \
			execute/get_executable.c \
			execute/is_directory.c \
			execute/path_exists.c \
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
			print_error/print_err_argc.c \
			print_error/print_err_builtin.c \
			print_error/print_err_cmd_not_found.c \
			print_error/print_err_exec.c \
			print_error/print_err_filename.c \
			print_error/print_err_heredoc.c \
			print_error/print_err_isdir.c \
			print_error/print_err_nofile.c \
			print_error/print_err_perm_denied.c \
			print_error/print_err_pipe.c \
			print_error/print_err_redir.c \
			print_error/print_err_syntax.c \
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
			xtoken/xtoklst_clear.c

SRCDIR		= src
SRCS		= $(addprefix $(SRCDIR)/, $(SRC))

# Objects
OBJDIR		= .obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Dependencies
DEPDIR		= .dep/
DEPS		= $(addprefix $(DEPDIR), $(SRC:.c=.d))
DEPDIRS		= $(DEPDIR)arrstr/ \
			$(DEPDIR)/basic_utils/ \
			$(DEPDIR)/builtins/ \
			$(DEPDIR)/env/ \
			$(DEPDIR)/execute/ \
			$(DEPDIR)/expand_and_split/ \
			$(DEPDIR)/input_utils/ \
			$(DEPDIR)/list/ \
			$(DEPDIR)/minishell/ \
			$(DEPDIR)/print_error/ \
			$(DEPDIR)/redirect/ \
			$(DEPDIR)/redirect_and_execute/ \
			$(DEPDIR)/xchar/ \
			$(DEPDIR)/xtoken/

# Includes
INCDIR		= inc
INCFLAG		:= -I $(INCDIR)

# Libraries
RL_DIR		= readline/
INCFLAG		+= -I $(RL_DIR)
READLINE	:= $(RL_DIR)libreadline.a $(RL_DIR)libhistory.a
RL_FILE		= readline.tar.gz
RL_URL		= http://git.savannah.gnu.org/cgit/readline.git/snapshot/readline-bfe9c573a9e376323929c80b2b71c59727fab0cc.tar.gz

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

$(RL_DIR):
			@curl -k $(RL_URL) > $(RL_FILE)
			@tar -xf $(RL_FILE) && mv readline-* readline
			@rm -rf $(RL_FILE)

$(READLINE): $(RL_DIR)
			@if [ ! -f $(RL_DIR)config.status ] ; then \
				printf "\t$(YELLOW)Configuring READLINE...$(DEFAULT)" && \
				cd ./$(RL_DIR) && \
				./configure &> /dev/null && \
				echo ✅; \
			fi
			@printf "\t$(YELLOW)Making READLINE...$(DEFAULT)"
			@cd ./$(RL_DIR) && make &> /dev/null
			@echo ✅

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(MKF)
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(XFLAGS) $(DEFS) $(DFLAGS) $(INCFLAG) -c $< -o $@ 
			@printf "\t$(YELLOW)$< $(GREEN)compiled$(DEFAULT)\n"
			@mkdir -p $(DEPDIR) $(DEPDIRS)
			@mv $(patsubst %.o,%.d,$@) $(subst $(OBJDIR),$(DEPDIR),$(@D))/

$(NAME)::	$(OBJS) $(READLINE) $(MKF)
			@$(CC) $(CFLAGS) $(XFLAGS) $(DEFS) $(LIBS) $(READLINE) $(OBJS) -o $(NAME)  
			@echo "$(GREEN)[ $(BGREEN)MINISH $(GREEN)created! ]$(DEFAULT)"

$(NAME)::
			@echo "$(BLUE)[ All done already ]$(DEFAULT)"

clean:
			@$(RM) $(OBJDIR) $(DEPDIR)
			@echo "$(BRED)[ Object and dep files cleared ]$(DEFAULT)"

fclean:
			@$(RM) $(OBJDIR) $(DEPDIR) $(NAME) $(READLINE)
			@echo "$(RED)[ All created files cleared ]$(DEFAULT)"

re:			fclean all
			@echo "$(BBLUE)[ All cleared and compiled ]$(DEFAULT)"

norm:
			@norminette $(SRCDIR)* $(INCDIR)*

-include $(DEPS)

.PHONY: 	clean fclean re norm
