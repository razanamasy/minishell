/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_redir_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:54:08 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 18:03:35 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fillin_proc(t_token *one_tr, t_token **control_t, t_token **control_p)
{
	*control_t = *control_p;
	if (scan_here_doc(one_tr, *control_p))
		return (1);
	*control_p = *control_t;
	if (scan_redir_in(one_tr, *control_p))
		return (1);
	*control_p = *control_t;
	if (scan_redir_out(one_tr, *control_p))
		return (1);
	return (0);
}

void	go_next_child(t_token **control_parse)
{
	while ((*control_parse)->type != PIPE && (*control_parse)->next != NULL)
		*control_parse = (*control_parse)->next;
	if ((*control_parse)->type == PIPE)
		*control_parse = (*control_parse)->next;
}

int	fill_tab(t_token **tab_redir, t_token **al_parse, int size_tab)
{
	t_token	*control_parse;
	t_token	*control_temp;
	int		i;

	i = 0;
	control_parse = *al_parse;
	init_all_lst(tab_redir, size_tab);
	while (i < size_tab)
	{
		while (control_parse->next != NULL
			&& control_parse->type != PIPE)
		{
			if (is_redir(control_parse->type))
			{
				if (fillin_proc(tab_redir[i],
						&control_temp, &control_parse))
					return (1);
				break ;
			}
			control_parse = control_parse->next;
		}
		go_next_child(&control_parse);
		i++;
	}
	return (0);
}

t_token	**create_redir_tab(t_token **al_parse, t_token **tab_redir, int *ret)
{
	int	size_tab;

	size_tab = 1;
	size_tab = get_size_tab(al_parse);
	tab_redir = (t_token **)malloc((size_tab + 1) * sizeof(t_token *));
	if (tab_redir == NULL)
	{
		*ret = 1;
		return (NULL);
	}
	tab_redir[size_tab] = NULL;
	if (fill_tab(tab_redir, al_parse, size_tab) == 1)
		*ret = 1;
	return (tab_redir);
}
