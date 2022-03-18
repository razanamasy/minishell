/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:08:41 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 18:09:14 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_maillon_lst(t_token **one_lst_redir, t_token *control_parse)
{
	t_token	*new;

	new = ft_lstnewcpy(control_parse->next);
	if (!new)
		return (1);
	ft_lstadd_back(one_lst_redir, new);
	return (0);
}

int	init_all_lst(t_token **tab_redir, int size_tab)
{
	int	i;

	i = 0;
	while (i < size_tab)
	{
		tab_redir[i] = ft_lstnew(ft_strdup("\0"));
		if (tab_redir[i] == NULL)
			return (1);
		tab_redir[i]->type = UNDIF_CHAR;
		i++;
	}
	return (0);
}
