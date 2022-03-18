/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:28:03 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 14:11:12 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_to_waitlist(int *tab_pid, int pid, int i)
{
	int	status;
	int	ret;

	ret = waitpid(pid, &status, WNOHANG);
	if (ret == 0)
		tab_pid[i] = pid;
	else
		tab_pid[i] = -1;
}

int	wait_all(int *tab_pid, int ret_val)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	ignore_sigint();
	if (ret_val != 0)
		return (ret_val);
	while (tab_pid[i])
	{
		if (tab_pid[i] != -1)
			waitpid(tab_pid[i], &status, 0);
		i++;
		if (WIFEXITED(status))
			ret_val = WEXITSTATUS(status);
		else if (WIFSIGNALED(status) && ret_val == 0)
			ret_val = WTERMSIG(status) + 128;
		if (ret_val == 131)
			write(2, "Quit (core dumped)\n", 19);
	}
	if (ret_val == 130)
		write(2, "\n", 1);
	custom_sigint();
	return (ret_val);
}
