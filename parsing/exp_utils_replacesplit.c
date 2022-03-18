/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils_replacesplit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:23:27 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:23:54 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	push_or_get_name_size(char *lst_str1, char **lst_str2)
{
	int	size;

	size = 1;
	while (lst_str1[size])
	{
		if (!ft_isalpha(lst_str1[1]) && lst_str1[1] != '_')
		{
			if (push_c(lst_str2, '$'))
			{
				if (*lst_str2 != NULL)
					free(*lst_str2);
				return (1);
			}
			return (2);
		}
		if (!ft_isalnum(lst_str1[size]) && lst_str1[size] != '_')
			break ;
		size++;
	}
	return (size);
}

int	is_ret_val(char **lst_str2, int *i)
{
	push_nbr(lst_str2, g_ret_val);
	*i = *i + 1;
	return (0);
}

int	end_of_story(char **lst_str2)
{
	if (push_c(lst_str2, '$'))
	{
		if (*lst_str2 != NULL)
			free(*lst_str2);
		return (1);
	}
	return (2);
}

int	fail(char **lst_str2)
{
	if (*lst_str2 != NULL)
		free(*lst_str2);
	return (1);
}
