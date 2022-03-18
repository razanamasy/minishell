/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:25:13 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/04 12:27:31 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote_err(int s_quote, int d_quote)
{
	char	*prefix;

	prefix = "Syntax error unexpected open quote";
	if (s_quote || d_quote)
	{
		write (2, prefix, ft_strlen(prefix) + 1);
		write(1, "\n", 2);
		return (0);
	}
	return (1);
}

int	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	else
		return (0);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
