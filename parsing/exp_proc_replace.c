/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_proc_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:55:04 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:17:27 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_quote(t_quote *quote, t_data **data, char *lst_str1)
{
	quote->s_quote = 0;
	quote->d_quote = 0;
	quote->_data = *data;
	quote->lst_str1 = lst_str1;
	return (0);
}

int	process_replace(t_quote *quote, int *i
		, char **lst_str2, t_token *control)
{
	int	ret;

	ret = 0;
	if (!((quote->d_quote == 0 && quote->s_quote == 0)
			&& (is_quote(quote->lst_str1[*i + 1]))))
	{
		if (!is_file_cond(control->type) && !control->temp_quote)
		{
			ret = replace_and_split(i, &(quote->lst_str1)[*i],
					lst_str2, quote->_data);
			if (ret == 1)
				return (1);
		}
		else
		{
			ret = replace_var(i, &(quote->lst_str1)[*i],
					lst_str2, quote->_data);
			if (ret == 1)
				return (1);
		}
	}
	return (0);
}

int	process_insertion(t_token *control, char **lst_str2, t_data *data)
{
	t_token	*controll;

	controll = data->lst_token_temp;
	while (controll && controll->next)
	{
		if (controll->str[0] == '\0')
			controll->is_quote = 1;
		controll = controll->next;
	}
	if (controll && controll->str[0] == '\0')
		controll->is_quote = 1;
	save_str_not_set(control, *lst_str2);
	if (replace_all_void(lst_str2, &data->lst_token_temp))
		return (1);
	if (push_last_node(lst_str2, &data->lst_token_temp))
		return (1);
	if (insert_lst(control, data->lst_token_temp))
		return (1);
	data->lst_token_temp = NULL;
	return (0);
}

int	extern_try(t_quote *quote, int *i
		, char **lst_str2, t_token *control)
{
	if (quote->_data->i == -1)
		quote->_data->i = *i;
	else
		quote->_data->i = 0;
	if (process_replace(quote, i, lst_str2, control))
		return (1);
	return (0);
}

int	replace_str(char *lst_str1, t_token *control, t_data *data)
{
	t_quote	quote;
	int		i;
	char	*lst_str2;

	lst_str2 = NULL;
	i = init_quote(&quote, &data, lst_str1) - 1;
	while (lst_str1[++i])
	{
		if (is_quote(lst_str1[i]))
		{
			if (check_quote_expand(&quote
					, lst_str1[i], &lst_str2, control) == 1)
				return (fail_malloc_check(&lst_str2));
		}
		else if (control->type != COND
			&& (lst_str1[i] == '$' && quote.s_quote == 0))
		{
			if (extern_try(&quote, &i, &lst_str2, control))
				return (1);
		}
		else if (push_c(&lst_str2, lst_str1[i]))
			return (fail_malloc_check(&lst_str2));
	}
	process_insertion(control, &lst_str2, data);
	return (0);
}
