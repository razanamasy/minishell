/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:21:03 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/05 15:42:45 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_next_token_as(t_token *cmd_dir, int type)
{
	while (cmd_dir)
	{
		if ((int)cmd_dir->type == type)
			return (cmd_dir);
		cmd_dir = cmd_dir->next;
	}
	return (NULL);
}

t_token	*get_last_token_as(t_token *lst_token, int type1, int type2)
{
	t_token	*last_token;

	last_token = NULL;
	while (lst_token)
	{
		if ((int)lst_token->type == type1 || (int)lst_token->type == type2)
			last_token = lst_token;
		lst_token = lst_token->next;
	}
	return (last_token);
}

int	get_redir_count(t_token *redir_list, int type)
{
	int	count;

	count = 0;
	if (!redir_list)
		return (0);
	while (redir_list)
	{
		if ((int)redir_list->type == type)
			count++;
		redir_list = redir_list->next;
	}
	return (count);
}
