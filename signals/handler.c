/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:30:33 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 20:49:42 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler_readline(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_ret_val = 130;
	}
}

void	sigint_handler_here_doc(int signum)
{
	int	fd_copy;

	if (signum == SIGINT)
	{
		fd_copy = dup(0);
		close(0);
		g_ret_val = fd_copy;
		g_ret_val = g_ret_val << 4;
		g_ret_val = g_ret_val | 130;
		write(1, "\n", 1);
	}
}
