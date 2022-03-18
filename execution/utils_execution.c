/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:13:37 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 15:38:43 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *  Function: get_bin
 *  -------------------------
 *  Get the bin path to the command, it is used in case if the command is
 *  not in the current directory
 *  
 *  command:	Command to execute
 *  envp:			List containing the environnement variables
 *
 *	Returns: Binary path
 */

char	*get_bin(char *command, char **envp)
{
	char	**path_list;
	char	*full_path;
	int		i;

	path_list = get_path_env(envp);
	if (is_bin_local(command, path_list) == 0)
		return (command);
	else if (!path_list || is_bin_local(command, path_list) == -1)
		return (NULL);
	full_path = NULL;
	i = 0;
	while (ft_access(full_path) == -1 && path_list[i])
	{
		if (full_path)
			free(full_path);
		full_path = ft_strjoin(path_list[i++], command);
		if (!full_path)
			return (NULL);
	}
	if (is_path_empty(path_list, i, full_path))
		return (ft_strdup(command));
	while (path_list[i])
		free(path_list[i++]);
	free(path_list);
	return (full_path);
}

/*
 *  Function: branch_write_to
 *  -------------------------
 *  Connects the write end of the pipe to the designated file descriptor
 *  
 *  pipe: Pipe to branch
 *  fd:		file descriptor to branch to
 *
 *	Returns: Success state
 */

int	branch_write_to(int pipe[2], int fd)
{
	close(pipe[0]);
	if (dup2(pipe[1], fd) < -1)
		return (FAILURE);
	close(pipe[1]);
	return (SUCCESS);
}

/*
 *  Function: branch_read_to
 *  -------------------------
 *  Connects the read end of the pipe to the designated file descriptor
 *  
 *  pipe: Pipe to branch
 *  fd:		file descriptor to branch to
 *
 *	Returns: Success state
 */

int	branch_read_to(int pipe[2], int fd)
{
	close(pipe[1]);
	if (dup2(pipe[0], fd) < -1)
		return (FAILURE);
	close(pipe[0]);
	return (SUCCESS);
}

char	*dup_cmd(t_data *data, char **cmd_arg, char *bin_path)
{
	char	*cmd;

	if (cmd_arg[0][0] == 26)
		cmd = ft_strdup("");
	else
		cmd = ft_strdup(cmd_arg[0]);
	if (!cmd)
	{
		free_cmd_error(data, cmd_arg, bin_path);
		exit(0);
	}
	return (cmd);
}

int	redir_mode(void)
{
	return (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}
