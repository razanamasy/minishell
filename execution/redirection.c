/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:55:37 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 18:16:26 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prepare_redir_in(t_token *redir_in, int **hc_cmd, t_data *data, int i)
{
	t_token	*last_redir_in;

	last_redir_in = get_last_token_as(redir_in, FILE_IN, COND);
	if (!last_redir_in)
		return (FAILURE);
	else
	{
		while (redir_in)
		{
			if (redir_in == last_redir_in)
				break ;
			if (redir_in->type == FILE_IN)
				try_opening_file(data, redir_in->str, O_RDONLY, 0);
			redir_in = redir_in->next;
		}
		choose_redir_in(last_redir_in, hc_cmd, data, i);
	}
	return (SUCCESS);
}

int	choose_redir_in(t_token *redir_in, int **hc_cmd, t_data *data, int i)
{
	if (redir_in->type == FILE_IN)
	{
		if (!redirect_read(redir_in->str, data, i))
			return (FAILURE);
	}
	else if (redir_in->type == COND)
	{
		if (!branch_read_to(get_last_hc(hc_cmd), 0))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	prepare_redir_out(t_data *data, t_token *redir_out)
{
	t_token	*last_redir_out;

	last_redir_out = get_last_token_as(redir_out, FILE_EOF, FILE_OUT);
	if (!last_redir_out)
		return (FAILURE);
	else
	{
		while (redir_out)
		{
			if (redir_out == last_redir_out)
				break ;
			if (redir_out->type == FILE_OUT || redir_out->type == FILE_EOF)
				try_opening_file(data, redir_out->str,
					open_option(redir_out), redir_mode());
			redir_out = redir_out->next;
		}
		choose_redir_out(data, last_redir_out);
	}
	return (SUCCESS);
}

int	open_option(t_token *redir_out)
{
	int	open_options;

	if (redir_out->type == FILE_OUT)
		open_options = (O_WRONLY | O_CREAT | O_TRUNC);
	else
		open_options = (O_RDWR | O_CREAT | O_APPEND);
	return (open_options);
}

int	choose_redir_out(t_data *data, t_token *redir_out)
{
	if (redir_out->type == FILE_EOF)
		redirect_write_end(data, redir_out->str);
	else
		redirect_write(data, redir_out->str);
	return (SUCCESS);
}
