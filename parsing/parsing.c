/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:37:33 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:39:04 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	type_assign1(t_token *control)
{
	if (!ft_strncmp(control->str, "|", 1))
		control->type = PIPE;
	else if (!ft_strncmp(control->str, "<<", 2))
		control->type = HERE_DOC;
	else if (!ft_strncmp(control->str, "<", 1))
		control->type = IN_REDIR;
	else if (!ft_strncmp(control->str, ">>", 2))
		control->type = OUT_EOF;
	else if (!ft_strncmp(control->str, ">", 1))
		control->type = OUT_REDIR;
	else
		control->type = UNDIF_CHAR;
}

void	type_assign2(t_token *control)
{
	if (control->type == HERE_DOC && (control->next)->type
		== UNDIF_CHAR)
		control->next->type = COND;
	else if (control->type == IN_REDIR && (control->next)->type
		== UNDIF_CHAR)
		control->next->type = FILE_IN;
	else if (control->type == OUT_EOF && (control->next)->type
		== UNDIF_CHAR)
		control->next->type = FILE_EOF;
	else if (control->type == OUT_REDIR && (control->next)->type
		== UNDIF_CHAR)
		control->next->type = FILE_OUT;
}

void	parsing1(t_token **alst)
{
	t_token	*control;

	control = *alst;
	while (control->next != NULL)
	{
		type_assign1(control);
		control = control->next;
	}
	type_assign1(control);
}

void	parsing2(t_token **alst)
{
	t_token	*control;

	control = *alst;
	while (control->next != NULL)
	{
		if (control->next != NULL)
		{
			type_assign2(control);
			control = control->next;
		}
	}
	if (control->next != NULL)
		type_assign2(control);
}
