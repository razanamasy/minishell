/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils_proc_replace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:22:38 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/06 09:56:27 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_str_not_set(t_token *control, char *lst_str2)
{
	if (!control->is_quote && lst_str2 == NULL)
	{
		if (control->type == FILE_OUT || control->type == FILE_IN
			|| control->type == FILE_EOF)
		{
			free_old_str(&control->save_str);
			control->save_str = ft_strdup(control->str);
		}
	}
}

int	replace_all_void(char **lst_str2, t_token **lst_temp)
{
	if (*lst_str2 == NULL && !*lst_temp)
	{
		*lst_str2 = ft_strdup("\0");
		if (lst_push(lst_str2, lst_temp))
		{
			free_lst_token_content(lst_temp);
			free(lst_temp);
			return (1);
		}
	}
	return (0);
}

int	push_last_node(char **lst_str2, t_token **lst_temp)
{
	if (lst_str2 != NULL)
	{
		if (lst_push(lst_str2, lst_temp))
		{
			free_lst_token_content(lst_temp);
			free(lst_temp);
			return (1);
		}
	}
	return (0);
}

int	is_file_cond(enum e_flag token)
{
	if (token == FILE_IN || token == FILE_OUT
		|| token == COND || token == FILE_EOF)
		return (1);
	return (0);
}
