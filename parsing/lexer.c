/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:24:23 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:36:22 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_quote_lexer(t_quote *quote, char **lst_str1)
{
	*lst_str1 = NULL;
	quote->s_quote = 0;
	quote->d_quote = 0;
	quote->lst_str1 = *lst_str1;
	return (0);
}

int	process_cond0(t_quote *_quote, char *entry, int *i, t_token **lst_token)
{
	int	ret;

	ret = 0;
	if (is_quote(entry[*i]))
	{
		ret = 2;
		if (check_quote(&(_quote->d_quote),
				&(_quote->s_quote), entry[*i], &(_quote->lst_str1)) == 1)
			return (fail_malloc_check(&(_quote->lst_str1)));
	}
	else if (entry[*i] == '|' && (!_quote->s_quote && !_quote->d_quote))
	{
		ret = 2;
		if (check_pipe(&(_quote->lst_str1), lst_token, entry[*i]) == 1)
			return (fail_malloc_check(&(_quote->lst_str1)));
	}
	else if ((entry[*i] == '>' || entry[*i] == '<')
		&& (!_quote->s_quote && !_quote->d_quote))
	{
		ret = 2;
		if (check_redir(&(_quote->lst_str1), lst_token, i, entry) == 1)
			return (fail_malloc_check(&(_quote->lst_str1)));
	}
	return (return_condition_lexer(ret));
}

int	process_cond1(t_quote *_quote, char *entry, int *i, t_token **lst_token)
{
	int	ret;

	ret = 0;
	ret = process_cond0(_quote, entry, i, lst_token);
	if (ret == 1)
		return (1);
	if (!ret && (entry[*i] == ' ' || entry[*i] == '\t'))
	{
		if (!_quote->s_quote && !_quote->d_quote)
		{
			ret = 2;
			if (check_break_space(entry[*i + 1],
					&(_quote->lst_str1), lst_token) == 1)
				return (fail_malloc_check(&(_quote->lst_str1)));
		}
		else if (_quote->s_quote || _quote->d_quote)
		{
			ret = 2;
			if (push_c(&(_quote->lst_str1), entry[*i]))
				return (fail_malloc_check(&(_quote->lst_str1)));
		}
	}
	return (return_condition_lexer(ret));
}

int	lexer_process(t_quote *_quote, char *entry, int *i, t_token **lst_token)
{
	int	ret;

	ret = 0;
	ret = process_cond1(_quote, entry, i, lst_token);
	if (ret == 1)
		return (1);
	if (ret == 0)
	{
		if (push_c(&(_quote->lst_str1), entry[*i]))
			return (fail_malloc_check(&(_quote->lst_str1)));
	}
	return (0);
}

int	lexer(char *entry, t_token **lst_token)
{
	t_quote	_quote;
	int		i;
	char	*lst_str1;

	i = init_quote_lexer(&_quote, &lst_str1);
	while (entry[i] == ' ' || entry[i] == '\t')
		i++;
	while (entry[i])
	{
		if (lexer_process(&_quote, entry, &i, lst_token))
			return (1);
		i++;
	}
	if (lst_push(&(_quote.lst_str1), lst_token))
		return (1);
	free_old_str(&(_quote.lst_str1));
	if (!check_quote_err(_quote.s_quote, _quote.d_quote))
		return (2);
	return (0);
}
