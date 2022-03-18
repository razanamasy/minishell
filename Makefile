# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lefendie <lefendie@42.student.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 16:49:02 by lefendie          #+#    #+#              #
#    Updated: 2022/02/09 01:38:17 by lefendie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	= minishell

#LIBFT_A = libft/libft.a

MAIN := main.c

SRC		:= main.c\
				 execution/exec_tools.c execution/execution.c execution/here_doc.c\
				 execution/pipe.c execution/redirection.c execution/here_doc2.c\
				 execution/here_doc3.c execution/test.c\
				 execution/utils_execution.c execution/wait.c execution/redirection2.c\
				 execution/error.c execution/lib_exec1.c execution/lib_exec2.c\
				 execution/lib_exec3.c execution/error2.c \
				 init/create_cmd_tab.c init/create_redir_tab.c init/init_history.c\
				 init/get_cmd.c init/cmd_utils_assign.c init/redir_utils.c\
				 init/redir_proc_fill.c init/init_exec.c\
				 parsing/expansion.c parsing/lexer.c parsing/parse_cmd_arg.c parsing/delete_not_set.c\
				 parsing/parsing.c parsing/token_tools.c\
				 parsing/utils_lexer.c parsing/check_syntaxe_err.c\
				 other/free_tabs.c other/utils.c other/get_next_line.c\
				 other/process.c other/process2.c other/free.c other/utils_lst.c other/utils_check.c\
				 other/free2.c other/free_exec.c\
				 libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstnew.c\
				 libft/libft.c libft/ft_strjoin.c libft/ft_strcmp.c libft/ft_strdup.c\
				 libft/ft_lstadd_back.c libft/ft_split_.c\
				 libft/ft_isalphanum.c libft/ft_isdigit.c libft/ft_isalpha.c\
				 builtin/echo.c builtin/exit.c builtin/env.c builtin/export.c builtin/unset.c\
				 builtin/cd.c builtin/pwd.c builtin/tools.c builtin/echo_utils.c\
				 builtin/cd_process.c builtin/cd_utils.c builtin/cd_many_args.c builtin/cd_no_args.c\
				 builtin/cd_last_pwd.c builtin/utils_cdpath.c builtin/cdpath.c builtin/cd_general.c\
				 builtin/export_utils.c builtin/key_already_exist.c builtin/valid_key.c\
				 builtin/utils_env_fct.c builtin/ft_getenv.c builtin/unset_utils.c\
				 parsing/exp_lst_insert.c parsing/exp_utils_replacesplit.c\
				 parsing/exp_replacesplit.c parsing/exp_replacesplit_bis.c parsing/exp_replaceonly.c parsing/exp_utils_proc_replace.c\
				 parsing/exp_proc_replace.c parsing/quote_expansion.c parsing/utils2_lexer.c\
				 signals/signal.c signals/signal2.c signals/handler.c

OBJ		:= $(SRC:.c=.o)

%.o: %.c; ${CC} ${CFLAGS} -o $@ -c $<

RM	= /bin/rm -rf

CC	= clang

CFLAGS	=  -Wall -Wextra -Werror -g3 -Iinclude/

LFLAGS	=  -ltinfo -lreadline

LFLAGS	=  -lreadline

all: ${NAME} 

${NAME}:  ${OBJ}
	${CC} ${LFLAGS} ${OBJ} -o ${NAME} 

debug: LFLAGS+= -fsanitize=address
debug: ${OBJ}	
	${CC} ${LFLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ} ${OBJ_BONUS} main.o

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: re clean fclean all debug
