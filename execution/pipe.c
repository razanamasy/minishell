/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:26:09 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/11 12:26:43 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	link_processes(int i, int pipe_in, int *pipe_fd, int tab_size)
{
	if (i != tab_size -1)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	if (i != 0)
	{
		dup2(pipe_in, 0);
		close(pipe_in);
		if (i == tab_size)
			close(pipe_fd[1]);
	}
}

int	prepare_pipe(int **pipe_fd, int tab_size, int i)
{
	if (tab_size > 1)
	{
		if (i == 0)
		{
			*pipe_fd = malloc(sizeof(int) * 2);
			if (!(*pipe_fd))
				return (FAILURE);
		}
		if (i != tab_size - 1)
			pipe(*pipe_fd);
	}
	else
		*pipe_fd = NULL;
	return (SUCCESS);
}

void	save_prev_pipe(int *pipe_in, int *pipe_fd, int i, int tab_size)
{
	if (pipe_fd)
	{
		*pipe_in = pipe_fd[0];
		close(pipe_fd[1]);
	}
	i++;
	tab_size++;
}
