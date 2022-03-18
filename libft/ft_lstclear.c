/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:14:10 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/04 12:14:25 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear(t_token **lst)
{
	t_token	*begin;
	t_token	*control;

	control = *lst;
	if (!lst)
		return ;
	while (control)
	{
		begin = control;
		control = control->next;
		ft_lstdelone(begin);
	}
	*lst = NULL;
}
