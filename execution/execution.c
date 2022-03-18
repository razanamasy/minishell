/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:52:51 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/11 12:39:23 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int	get_cmd_count(t_token **tab_dir)
{
	int	i;

	i = 0;
	while (tab_dir[i])
		i++;
	return (i);
}

int	special_cases(t_data *data, int i)
{
	char	**cmd;

	cmd = data->tab_cmd[i];
	if (is_simple_cmd(data) && cmd[0])
	{
		if (ft_strncmp(cmd[0], "export\0", 7) == 0)
			return (ft_export(cmd, data, 0));
		else if (ft_strncmp(cmd[0], "unset\0", 6) == 0)
			return (ft_unset(cmd, data, 1));
		else if (ft_strncmp(cmd[0], "cd\0", 3) == 0)
			return (ft_cd(data, cmd));
		else if (ft_strncmp(cmd[0], "env\0", 4) == 0)
			return (ft_env(data));
		else if (ft_strncmp(cmd[0], "exit\0", 5) == 0)
			return (b_exit(data, cmd, 1));
		return (0);
	}
	return (0);
}

void	new_proccess_cmd(t_data *data, int i, int pipe_in, int *pipe_fd)
{
	int	id;
	int	ret_val;

	id = fork();
	if (!id)
	{
		custom_sigquit();
		ret_val = check_ambiguous_redir(data->tab_dir[i]);
		if (ret_val)
		{
			free_execution_child(data);
			free(pipe_fd);
			exit (ret_val);
		}
		link_processes(i, pipe_in, pipe_fd, get_cmd_count(data->tab_dir));
		free(pipe_fd);
		prepare_redir_out(data, (data->tab_dir)[i]);
		prepare_redir_in((data->tab_dir)[i], data->tab_hc[i], data, i);
		close_all_hc(data->tab_hc, get_cmd_count(data->tab_dir));
		exec_cmd(data, data->env, i);
	}
	if (pipe_in)
		close(pipe_in);
	add_to_waitlist(*data->tab_pid, id, i);
}

int	execute_list(t_data *data, int **tab_pid, int **tab_read_fd)
{
	int	i;
	int	*pipe_fd;
	int	pipe_in;
	int	ret_val;

	i = -1;
	pipe_in = 0;
	ret_val = get_hc_tab(data);
	if (ret_val != 0)
		return (ret_val);
	while ((data->tab_dir)[++i] != NULL)
	{
		prepare_pipe(&pipe_fd, get_cmd_count(data->tab_dir), i);
		new_proccess_cmd(data, i, pipe_in, pipe_fd);
		ret_val = special_cases(data, i);
		check_hc((data->tab_hc)[i]);
		save_prev_pipe(&pipe_in, pipe_fd, i, get_cmd_count(data->tab_dir));
		if (pipe_fd)
			(*tab_read_fd)[i] = pipe_fd[0];
	}
	if (pipe_fd)
		free(pipe_fd);
	(*tab_read_fd)[i - 1] = -1;
	(*tab_pid)[i] = 0;
	return (ret_val);
}

void	check_hc(int **tab_hc)
{
	int	*last_hc;

	last_hc = get_last_hc(tab_hc);
	if (last_hc)
	{
		close(last_hc[0]);
		close(last_hc[1]);
	}
}
