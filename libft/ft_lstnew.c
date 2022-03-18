/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:45:11 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/04 12:27:29 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnew(char *str)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		return (0);
	new->str = str;
	new->next = NULL;
	new->to_split = 0;
	new->is_quote = 0;
	new->temp_quote = 0;
	new->save_str = ft_strdup("\0");
	return (new);
}

t_token	*ft_lstnewcpy(t_token *to_cpy)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		return (0);
	new->str = ft_strdup(to_cpy->str);
	new->save_str = ft_strdup(to_cpy->save_str);
	new->next = NULL;
	new->to_split = to_cpy->to_split;
	new->type = to_cpy->type;
	new->is_quote = to_cpy->is_quote;
	return (new);
}
