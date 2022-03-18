/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:51:10 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/04 12:13:51 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstdelone(t_token *lst)
{
	if (lst->str != NULL)
	{
		free(lst->str);
		lst->str = NULL;
		free(lst->save_str);
		lst->save_str = NULL;
	}
	free(lst);
}
