/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:16:03 by hrazanam          #+#    #+#             */
/*   Updated: 2021/05/31 15:57:35 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_token **alst, t_token *new)
{
	t_token	*control;

	control = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (control && control->next != NULL)
		control = control->next;
	control->next = new;
}
