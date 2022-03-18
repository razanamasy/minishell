/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_replacesplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:19:54 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:22:30 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	push_rest(int data_i, char **lst_str2, int space_start, t_token **small_lst)
{
	if (data_i && !*lst_str2)
		*lst_str2 = ft_strdup("\0");
	if (*lst_str2 && space_start)
		if (lst_push(lst_str2, small_lst))
			return (1);
	return (0);
}
