/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:26:55 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 01:39:35 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *  Function: redirect_read
 *  -------------------------
 *  Redirect the file to the input of the process
 *  
 *  file:	File to read
 *
 *  Returns: Success state
 */

int	redirect_read(char *file, t_data *data, int i)
{
	int	fd_file;
	int	ret;
	int	pipe_count;
	int	cmd_count;

	fd_file = open(file, O_RDONLY);
	if (fd_file == -1)
	{
		pipe_count = list_size((void **)data->tab_cmd) - 1;
		cmd_count = list_size((void **)data->tab_cmd[i]);
		ret = try_errno(file);
		free_execution_child(data);
		if (pipe_count > 0 && cmd_count == 0)
			exit(0);
		exit(ret);
	}
	if (dup2(fd_file, 0) < -1)
		return (FAILURE);
	close(fd_file);
	return (SUCCESS);
}

/*
 *  Function: redirect_write
 *  -------------------------
 *  Redirect the output of the process to a file
 *  
 *  file:	File to write *
 *  Returns: Success state
 */

int	redirect_write(t_data *data, char *file)
{
	int	fd_file;
	int	ret_val;

	fd_file = open(file, O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_file == -1)
	{
		ret_val = try_errno(file);
		free_execution_child(data);
		exit(ret_val);
		return (0);
	}
	if (dup2(fd_file, 1) < -1)
		return (FAILURE);
	close(fd_file);
	return (SUCCESS);
}

/*
 *  Function: redirect_write_end
 *  -------------------------
 *  Allows the transfer of data to a file by writing to the end
 *  of the file
 *
 *	file: File where the redirection is done
 *
 *  Returns: Success state
 */

int	redirect_write_end(t_data *data, char *file)
{
	int	fd_file;
	int	ret_val;

	fd_file = open(file, O_WRONLY | O_APPEND | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_file == -1)
	{
		ret_val = try_errno(file);
		free_execution_child(data);
		exit(ret_val);
	}
	if (dup2(fd_file, 1) < -1)
		return (FAILURE);
	close(fd_file);
	return (SUCCESS);
}

void	try_opening_file(t_data *data, char *file, int option, int mode)
{
	int	fd;
	int	ret_val;

	if (mode == 0)
		fd = open(file, option);
	else
		fd = open(file, option, mode);
	if (fd != -1)
		close(fd);
	else
	{
		ret_val = try_errno(file);
		free_execution_child(data);
		close_std();
		exit(ret_val);
	}
}

void	close_std(void)
{
	close(0);
	close(1);
	close(2);
}
