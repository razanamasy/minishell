/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:36:40 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:37:12 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	attr_cmd(t_token *control)
{
	while (control != NULL && control->type != PIPE)
	{
		if (control->type == UNDIF_CHAR)
		{
			control->type = CMD;
			break ;
		}
		control = control->next;
	}
}

void	parse_cmd_arg(t_token **alst)
{
	t_token	*control;

	control = *alst;
	if (control->next == NULL && control->type == UNDIF_CHAR)
		control->type = CMD;
	while (control != NULL)
	{
		if (control->type != PIPE)
		{
			attr_cmd(control);
			if (control == NULL)
				break ;
			control = control->next;
			while (control != NULL && control->type != PIPE)
			{
				if (control->type == UNDIF_CHAR)
					control->type = ARG;
				control = control->next;
			}
		}
		else
			control = control->next;
	}
}
