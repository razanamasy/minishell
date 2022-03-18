/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_lst_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:52:35 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 14:54:28 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	multi_token(t_token *big, t_token *small, t_token *ss, t_token *se)
{
	free_old_str(&big->str);
	big->str = ft_strdup(ss->str);
	free(ss->str);
	if (!big->str)
	{
		free_lst_token_content(&small);
		free(small);
		return (1);
	}
	if (ss->next)
		ss = ss->next;
	while (se->next != NULL)
	{
		se->type = 10;
		se = se->next;
	}
	se->type = 10;
	se->next = big->next;
	big->next = ss;
	free(small->save_str);
	free(small);
	return (0);
}

int	insert_lst(t_token *control_big, t_token *small)
{
	int		size_small;
	t_token	*control_s_start;
	t_token	*control_s_end;

	size_small = get_lst_size(&small);
	control_s_start = small;
	control_s_end = small;
	if (size_small > 1)
	{
		if (multi_token(control_big, small
				, control_s_start, control_s_end))
			return (1);
	}
	else
	{
		free_old_str(&control_big->str);
		control_big->str = ft_strdup(control_s_start->str);
		free(small->save_str);
		free(small->str);
		free(small);
	}
	return (0);
}
