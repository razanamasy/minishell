/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:53:04 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:53:51 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	malloc_each_cmd(t_token **al_parse, char ***one_tab_cmd, int index)
{
	int	size_cmd;

	size_cmd = get_size_cmd(al_parse, index);
	one_tab_cmd[index] = (char **)malloc((size_cmd + 1) * sizeof(char *));
	if (one_tab_cmd[index] == NULL)
		return (1);
	one_tab_cmd[index][size_cmd] = NULL;
	return (0);
}

int	assign_each_cmd(t_token **al_parse, char ***one_tab_cmd, int index)
{
	int		y;
	t_token	*control_parse;
	t_token	*control_temp;

	y = 0;
	control_parse = *al_parse;
	if (index > 0)
	{
		get_the_right_pipe(&control_parse, index);
		control_temp = control_parse;
		if (get_the_cmd(&control_parse, one_tab_cmd, index, &y))
			return (1);
		control_parse = control_temp;
		if (get_all_args(&control_parse, one_tab_cmd, index, &y))
			return (1);
	}
	else
	{
		if (get_the_cmd(&control_parse, one_tab_cmd, index, &y))
			return (1);
		control_parse = *al_parse;
		if (get_all_args(&control_parse, one_tab_cmd, index, &y))
			return (1);
	}
	return (0);
}

char	***fail_cmd(int *ret, char ***tab_cmd)
{
	*ret = 1;
	return (tab_cmd);
}

char	***create_cmd_tab(t_token **al_parse, char ***tab_cmd, int *ret)
{
	int	size_tab;
	int	i;

	i = 0;
	size_tab = get_size_tab(al_parse);
	tab_cmd = (char ***)malloc((size_tab + 1) * sizeof (char **));
	if (!tab_cmd)
		return (fail_cmd(ret, tab_cmd));
	while (i < size_tab)
	{
		if (malloc_each_cmd(al_parse, tab_cmd, i) == 1)
			return (fail_cmd(ret, tab_cmd));
		i++;
	}
	i = 0;
	while (i < size_tab)
	{
		if (assign_each_cmd(al_parse, tab_cmd, i))
			return (fail_cmd(ret, tab_cmd));
		i++;
	}
	tab_cmd[size_tab] = NULL;
	return (tab_cmd);
}
