/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:25:30 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 15:31:05 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	err_with_msg_info(char *error_message, char *additional_info)
{
	char	*full_err;

	full_err = NULL;
	full_err = ft_strjoin(additional_info, error_message);
	if (!full_err)
		return (-1);
	full_err = ft_strjoin(full_err, "\n");
	if (!full_err)
		return (-1);
	write(2, full_err, ft_strlen(full_err));
	free(full_err);
	return (0);
}

int	try_errno(char *prefix)
{
	int	ret_val;

	ret_val = 0;
	if (errno != 0)
	{
		ret_val = errno;
		if (!*prefix)
			prefix = " ";
		perror((const char *)prefix);
		ret_val = 1;
		return (ret_val);
	}
	return (0);
}

void	try_cmd_not_found(t_data *data, char **cmd_arg, char *bin_path)
{
	char	*cmd;

	cmd = dup_cmd(data, cmd_arg, bin_path);
	if (cmd)
	{
		if (cmd[0] == 26)
			err_with_msg_info(" : command not found", cmd);
		else
			err_with_msg_info(": command not found", cmd);
		free_cmd_error(data, cmd_arg, bin_path);
		exit(127);
	}
	free(cmd);
}

void	try_accessible(t_data *data, char **cmd_arg, char *bin_path)
{
	char	*cmd;

	cmd = dup_cmd(data, cmd_arg, bin_path);
	if (!ft_strncmp(cmd, ".", 2))
	{
		err_with_msg_info(": filename argument required", cmd);
		free_cmd_error(data, cmd_arg, bin_path);
		exit(2);
	}
	if (!ft_strncmp(cmd, "..", 3))
		err_with_msg_info(" : command not found", cmd);
	else if (!bin_path)
		err_with_msg_info(" : No such file or directory", cmd);
	else if (access(bin_path, F_OK) == -1 && is_path_correct(bin_path))
	{
		perror(cmd);
		free(cmd);
	}
	if (!ft_strncmp(cmd_arg[0], "..", 3) || !bin_path
		|| (access(bin_path, F_OK) == -1 && is_path_correct(bin_path)))
	{
		free_cmd_error(data, cmd_arg, bin_path);
		exit(127);
	}
	free(cmd);
}

void	try_file_error(t_data *data, char **cmd, char *bin_path)
{
	int	fd;

	if (errno == EACCES)
	{
		fd = open(bin_path, O_RDWR);
		if (fd == -1)
		{
			perror(cmd[0]);
			free_cmd_error(data, cmd, bin_path);
			exit (126);
		}
	}
}
