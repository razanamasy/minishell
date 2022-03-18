/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntaxe_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:43:43 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/06 09:55:54 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(enum e_flag token)
{
	if (token == IN_REDIR || token == HERE_DOC || token == OUT_REDIR
		|| token == OUT_EOF)
		return (1);
	return (0);
}

int	err_start_pipe(t_token *control, char *prefix)
{
	if (control != NULL && control->type == PIPE)
	{
		write (2, prefix, ft_strlen(prefix) + 1);
		write(2, control->str, ft_strlen(control->str) + 1);
		write(1, "\n", 2);
		return (2);
	}
	return (0);
}

int	err_redir(t_token *control, char *prefix)
{
	if (is_redir(control->type))
	{
		if (control->next != NULL && (is_redir(control->next->type)
				|| control->next->type == PIPE))
		{
			write (2, prefix, ft_strlen(prefix) + 1);
			write(2, control->str, ft_strlen(control->str) + 1);
			write(1, "\n", 2);
			return (2);
		}
		else if (control->next == NULL)
		{
			write (2, prefix, ft_strlen(prefix) + 1);
			write(2, control->str, ft_strlen(control->str) + 1);
			write(1, "\n", 2);
			return (2);
		}
	}
	return (0);
}

int	err_pipe(t_token *control, char *prefix)
{
	if (control->type == PIPE)
	{
		if (control->next != NULL && control->next->type == PIPE)
		{
			write (2, prefix, ft_strlen(prefix) + 1);
			write(2, control->str, ft_strlen(control->str) + 1);
			write(1, "\n", 2);
			return (2);
		}
		else if (control->next == NULL)
		{
			write (2, prefix, ft_strlen(prefix) + 1);
			write(2, control->str, ft_strlen(control->str) + 1);
			write(1, "\n", 2);
			return (2);
		}
	}
	return (0);
}

int	check_syntaxe_err(t_token **alst)
{
	t_token	*control;
	char	*prefix;

	prefix = "Syntax error unexpected token near : ";
	control = *alst;
	if (err_start_pipe(control, prefix) == 2)
		return (2);
	while (control != NULL)
	{
		if (is_redir(control->type))
		{
			if (err_redir(control, prefix) == 2)
				return (2);
		}
		if (control->type == PIPE)
		{
			if (err_pipe(control, prefix) == 2)
				return (2);
		}
		control = control->next;
	}
	return (0);
}
