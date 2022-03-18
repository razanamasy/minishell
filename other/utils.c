/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:22:40 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/06 09:07:00 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fail_malloc_check(char **lst_str)
{
	if (!*lst_str)
		*lst_str = NULL;
	return (1);
}

int	get_lst_size(t_token **lst)
{
	t_token	*control;
	int		size;

	size = 0;
	control = *lst;
	while (control != NULL)
	{
		control = control->next;
		size++;
	}
	return (size);
}

int	get_size_tab(t_token **parse)
{
	t_token	*control;
	int		size_tab;

	size_tab = 1;
	control = *parse;
	while (control->next != NULL)
	{
		if (control->type == PIPE)
			size_tab++;
		control = control->next;
	}
	return (size_tab);
}
