/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:38:04 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/07 14:19:01 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <limits.h>
# include <signal.h>
# include <dirent.h>

# define SUCCESS 1
# define FAILURE 0
# define BUFFER_SIZE 32
# define DEBUG 0

# include "minishell_struct.h"
# include "libft.h"
# include "builtin.h"
# include "process.h"
# include "utils.h"
# include "parsing.h"
# include "free.h"
# include "here_doc.h"
# include "execution.h"
# include "redirection.h"
# include "affichage.h"
# include "error.h"
# include "token_tools.h"
# include "utils_execution.h"
# include "env.h"
# include "test.h"
# include "signals.h"
# include "pipe.h"
# include "init.h"

#endif
