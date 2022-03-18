/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:26:28 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/06 09:12:29 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lst_push(char **lst_str, t_token **lst_token)
{
	t_token	*new;
	char	*n_lst_str;

	if (*lst_str != NULL)
	{
		n_lst_str = ft_strdup(*lst_str);
		if (!n_lst_str)
			return (1);
		new = ft_lstnew(n_lst_str);
		if (!new)
			return (1);
		ft_lstadd_back(lst_token, new);
		free_old_str(lst_str);
	}
	return (0);
}

int	lst_push_cpy(t_token *to_cpy, t_token **lst_token)
{
	t_token	*new;

	if (to_cpy->str != NULL)
	{
		new = ft_lstnewcpy(to_cpy);
		if (!new)
			return (1);
		ft_lstadd_back(lst_token, new);
	}
	return (0);
}

int	push_str(char **lst_str, char *str_to_join)
{
	if (!*lst_str)
	{
		*lst_str = ft_strdup(str_to_join);
		if (!*lst_str)
			return (1);
	}
	else
	{
		*lst_str = ft_strjoin(*lst_str, str_to_join);
		if (!*lst_str)
			return (1);
	}
	return (0);
}

int	push_c(char **lst_str, char c)
{
	if (!*lst_str)
	{
		*lst_str = ft_strdup_c(c);
		if (!*lst_str)
			return (1);
	}
	else
	{
		*lst_str = ft_strjoin_c(*lst_str, c);
		if (!*lst_str)
			return (1);
	}
	return (0);
}

int	push_nbr(char **lst_str, int n)
{
	int long	nb;

	nb = (int long)n;
	if (n < 0)
	{
		if (*lst_str == NULL)
			*lst_str = ft_strdup("-");
		else
			*lst_str = ft_strjoin_c(*lst_str, '-');
		nb = (int long)n * -1;
	}
	if (nb >= 10)
	{
		push_nbr(lst_str, nb / 10);
		push_nbr(lst_str, nb % 10);
	}
	else
	{
		if (*lst_str == NULL)
			*lst_str = ft_strjoin_c(ft_strdup("\0"), nb + 48);
		else
			*lst_str = ft_strjoin_c(*lst_str, nb + 48);
	}
	return (1);
}
