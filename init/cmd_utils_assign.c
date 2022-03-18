/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils_assign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:43:40 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:52:23 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_the_right_pipe(t_token **control_parse, int index)
{
	int	pipe;

	pipe = 0;
	while ((*control_parse)->next != NULL && pipe < index)
	{
		if ((*control_parse)->type == PIPE)
			pipe++;
		*control_parse = (*control_parse)->next;
	}
}

int	get_the_cmd(t_token **control_parse,
		char ***one_tab_cmd, int index, int *y)
{
	while (*control_parse != NULL && (*control_parse)->type != PIPE)
	{
		if ((*control_parse)->type == CMD)
		{
			one_tab_cmd[index][*y] = ft_strdup((*control_parse)->str);
			if (!one_tab_cmd[index][*y])
				return (1);
			*y = *y + 1;
			break ;
		}
		*control_parse = (*control_parse)->next;
	}
	return (0);
}

int	get_all_args(t_token **control_parse, char ***one_tab_cmd,
		int index, int *y)
{
	while (*control_parse != NULL && (*control_parse)->type != PIPE)
	{
		if ((*control_parse)->type == ARG)
		{
			one_tab_cmd[index][*y] = ft_strdup((*control_parse)->str);
			if (!one_tab_cmd[index][*y])
				return (1);
			*y = *y + 1;
		}
		*control_parse = (*control_parse)->next;
	}
	return (0);
}
