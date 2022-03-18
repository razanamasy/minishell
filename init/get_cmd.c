/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:03:55 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/06 08:57:21 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	size_other_child(t_token *control_parse, int index)
{
	int	size_cmd;
	int	i;

	i = 0;
	size_cmd = 0;
	while (control_parse->next != NULL && i < index)
	{
		if (control_parse->type == PIPE)
			i++;
		control_parse = control_parse->next;
	}
	while (control_parse != NULL && control_parse->type != PIPE)
	{
		if (control_parse->type == CMD || control_parse->type == ARG)
			size_cmd++;
		control_parse = control_parse->next;
	}
	return (size_cmd);
}

int	get_size_cmd(t_token **al_parse, int index)
{
	int		size_cmd;
	t_token	*control_parse;

	size_cmd = 0;
	control_parse = *al_parse;
	if (index > 0)
		size_cmd = size_other_child(control_parse, index);
	else
	{
		while (control_parse != NULL && control_parse->type != PIPE)
		{
			if (control_parse->type == CMD
				|| control_parse->type == ARG)
				size_cmd++;
			control_parse = control_parse->next;
		}
	}
	return (size_cmd);
}
