/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_proc_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:05:53 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 18:35:54 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	rep_or_fill(t_token *one_tab_redir, t_token *control_parse)
{
	if (one_tab_redir->str[0] == '\0' && one_tab_redir->type == UNDIF_CHAR)
	{
		free_old_str(&(one_tab_redir->str));
		one_tab_redir->str = ft_strdup(control_parse->next->str);
		if (!one_tab_redir->str)
			return (1);
		free_old_str(&(one_tab_redir->save_str));
		one_tab_redir->save_str = ft_strdup(control_parse->next->save_str);
		if (!one_tab_redir->save_str)
			return (1);
		one_tab_redir->type = control_parse->next->type;
		one_tab_redir->is_quote = control_parse->next->is_quote;
	}
	else
	{
		if (add_maillon_lst(&one_tab_redir, control_parse))
			return (1);
	}
	return (0);
}

int	scan_here_doc(t_token *one_tab_redir, t_token *control_parse)
{
	while (control_parse->next != NULL && control_parse->type != PIPE)
	{
		if (control_parse->type == HERE_DOC)
		{
			if (rep_or_fill(one_tab_redir, control_parse))
				return (1);
		}
		control_parse = control_parse->next;
	}
	return (0);
}

int	scan_redir_in(t_token *one_tab_redir, t_token *control_parse)
{
	while (control_parse->next != NULL && control_parse->type != PIPE)
	{
		if (control_parse->type == IN_REDIR)
		{
			if (rep_or_fill(one_tab_redir, control_parse))
				return (1);
		}
		control_parse = control_parse->next;
	}
	return (0);
}

int	scan_redir_out(t_token *one_tab_redir, t_token *control_parse)
{
	while (control_parse->next != NULL && control_parse->type != PIPE)
	{
		if (control_parse->type == OUT_REDIR || control_parse->type == OUT_EOF)
		{
			if (rep_or_fill(one_tab_redir, control_parse))
				return (1);
		}
		control_parse = control_parse->next;
	}
	return (0);
}
