/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:39:27 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:40:16 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_double_quote(int *d_quote, int *s_quote, char entry, char **lst_str)
{
	if (entry == '"' && *s_quote == 1)
	{
		if (push_c(lst_str, entry))
			return (1);
	}
	else if (entry == '"' && *s_quote == 0)
	{
		if (*d_quote == 0)
			*d_quote = 1;
		else if (*d_quote == 1)
			*d_quote = 0;
	}
	return (0);
}

void	set_data_quote(t_token *control, int d_quote, int s_quote)
{
	if (d_quote || s_quote)
	{
		control->temp_quote = 1;
		control->is_quote = 1;
	}
	else
		control->temp_quote = 0;
}

int	check_quote_expand(t_quote *quote, char entry, char **lst_str,
		t_token *control)
{
	quote->_data->i = -1;
	if (set_double_quote(&quote->d_quote, &quote->s_quote, entry, lst_str))
		return (1);
	if (entry == '\'' && quote->d_quote == 1)
	{
		if (push_c(lst_str, entry))
			return (1);
	}
	else if (entry == '\'' && quote->d_quote == 0)
	{
		if (quote->s_quote == 0)
			quote->s_quote = 1;
		else if (quote->s_quote == 1)
			quote->s_quote = 0;
	}
	set_data_quote(control, quote->d_quote, quote->s_quote);
	return (0);
}
