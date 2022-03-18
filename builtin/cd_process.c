/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:27:54 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 16:28:40 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	to_home1(t_data *data)
{
	if (no_arg(data, 1) == 1)
		return (1);
	return (0);
}

int	to_home2(t_data *data)
{
	if (no_arg(data, 1) == 1)
		return (1);
	return (0);
}

int	to_oldpwd(t_data *data)
{
	if (cd_last_pwd(data, 1) == 1)
		return (1);
	return (0);
}

int	to_dot(char **tab_cmd, t_data *data)
{
	if ((tab_cmd[1][0] == '.' && tab_cmd[1][1] == '\0')
		|| (!ft_strncmp(tab_cmd[1], "..", 2) && tab_cmd[1][2] == '\0'))
	{
		if (change_directory(tab_cmd[1], data, 1) == 1)
			return (1);
		return (0);
	}
	return (0);
}

int	to_cdpath(int curpath, char *cdpath_before
		, t_data *data, char **tab_cmd)
{
	if (!curpath)
	{
		getcwd(cdpath_before, PATH_MAX);
		if (!check_cdpath(data, tab_cmd[1], cdpath_before))
			return (0);
	}
	return (1);
}
