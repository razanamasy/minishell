/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:53:34 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:59:29 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_data *data, char **tab_cmd)
{
	char	cdpath_before[PATH_MAX];
	int		curpath;

	curpath = 0;
	if (count_args(&tab_cmd[1]) == 1)
		return (1);
	if (!tab_cmd[1])
		return (to_home1(data));
	if ((!ft_strncmp(tab_cmd[1], "~", 1) && tab_cmd[1][1] == '\0'))
		return (to_home2(data));
	if (tab_cmd[1][0] == 26)
		return (0);
	if (tab_cmd[1][0] == '-' && tab_cmd[1][1] == '\0')
		return (to_oldpwd(data));
	if (tab_cmd[1][0] == '/')
		curpath = 1;
	if ((tab_cmd[1][0] == '.' && tab_cmd[1][1] == '\0')
		|| (!ft_strncmp(tab_cmd[1], "..", 2) && tab_cmd[1][2] == '\0'))
		return (to_dot(tab_cmd, data));
	if (!to_cdpath(curpath, cdpath_before, data, tab_cmd))
		return (0);
	if (change_directory(tab_cmd[1], data, 1) == 1)
		return (1);
	return (0);
}
