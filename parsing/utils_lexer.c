/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:43:18 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:44:04 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lex_check_dquote(int *d_quote, int *s_quote, char entry, char **lst_str)
{
	if (entry == '"' && *s_quote == 1)
	{
		if (push_c(lst_str, entry))
			return (1);
	}
	else if (entry == '"' && *s_quote == 0)
	{
		if (push_c(lst_str, entry))
			return (1);
		if (*d_quote == 0)
			*d_quote = 1;
		else if (*d_quote == 1)
			*d_quote = 0;
	}
	return (0);
}

int	check_quote(int *d_quote, int *s_quote, char entry, char **lst_str)
{
	if (lex_check_dquote(d_quote, s_quote, entry, lst_str))
		return (1);
	if (entry == '\'' && *d_quote == 1)
	{
		if (push_c(lst_str, entry))
			return (1);
	}
	else if (entry == '\'' && *d_quote == 0)
	{
		if (push_c(lst_str, entry))
			return (1);
		if (*s_quote == 0)
			*s_quote = 1;
		else if (*s_quote == 1)
			*s_quote = 0;
	}
	return (0);
}

int	check_pipe(char **lst_str, t_token **lst_token, char entry)
{
	if (lst_push(lst_str, lst_token))
		return (1);
	if (push_c(lst_str, entry))
		return (1);
	if (lst_push(lst_str, lst_token))
		return (1);
	free_old_str(lst_str);
	return (0);
}

int	check_redir(char **lst_str, t_token **lst_token, int *i, char *entry)
{
	if (lst_push(lst_str, lst_token))
		return (1);
	if (push_c(lst_str, entry[*i]))
		return (1);
	if (entry[*i + 1] == entry[*i])
	{
		*i = *i + 1;
		*lst_str = ft_strjoin_c(*lst_str, entry[*i]);
		if (!*lst_str)
			return (1);
	}
	if (lst_push(lst_str, lst_token))
		return (1);
	free_old_str(lst_str);
	return (0);
}

int	check_break_space(char entry, char **lst_str, t_token **lst_token)
{
	if (entry != ' ' || entry != '\t')
	{
		if (lst_push(lst_str, lst_token))
			return (1);
	}
	free_old_str(lst_str);
	return (0);
}
