/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:25:01 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/06 10:07:32 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ignore_builtin(char **cmd)
{
	if (ft_strncmp(cmd[0], "unset\0", 6) == 0
		|| ft_strncmp(cmd[0], "export\0", 7) == 0
		|| ft_strncmp(cmd[0], "cd\0", 3) == 0
		|| ft_strncmp(cmd[0], "exit\0", 5) == 0
		|| ft_strncmp(cmd[0], "env\0", 4) == 0)
		return (0);
	return (-1);
}

int	try_builtin(t_data *data, int i)
{
	char	**cmd;

	cmd = data->tab_cmd[i];
	if (!cmd[0])
		return (FAILURE);
	if (ft_strncmp(cmd[0], "echo\0", 5) == 0)
		return (b_echo(cmd));
	else if (ft_strncmp(cmd[0], "pwd\0", 4) == 0)
		return (ft_pwd(data, 1));
	if (!is_simple_cmd(data))
	{
		if (ft_strncmp(cmd[0], "cd\0", 3) == 0)
			return (ft_cd(data, cmd));
		else if (ft_strncmp(cmd[0], "export\0", 7) == 0)
			return (ft_export(cmd, data, 1));
		else if (ft_strncmp(cmd[0], "unset\0", 6) == 0)
			return (ft_unset(cmd, data, 1));
		else if (ft_strncmp(cmd[0], "env\0", 4) == 0)
			return (ft_env(data));
		else if (ft_strncmp(cmd[0], "exit\0", 5) == 0)
			return (b_exit(data, cmd, 1));
	}
	else if (ignore_builtin(cmd) == 0)
		return (0);
	return (-1);
}

int	is_simple_cmd(t_data *data)
{
	return (get_cmd_count(data->tab_dir) == 1);
}
