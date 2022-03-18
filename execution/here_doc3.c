/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:24:44 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/11 12:41:05 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fill_hc_cmd(t_data *data, t_token *cmd_dir, int **hc_cmd)
{
	t_token	*curr_hc;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (hc_cmd[i] && ret == 0)
	{
		curr_hc = get_next_token_as(cmd_dir, COND);
		ret = here_doc(data, curr_hc->is_quote, curr_hc->str, hc_cmd[i]);
		if (ret == -1)
			return (-1);
		cmd_dir = curr_hc->next;
		i++;
	}
	return (ret);
}

int	fill_hc_cmd_list(t_data *data, int ***tab_hc, int tab_size, int hc_count)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (hc_count == 0)
		return (0);
	custom_sigint_heredoc();
	if (g_ret_val == 130)
		g_ret_val = 0;
	while (i < tab_size && ret == 0)
	{
		if (tab_hc[i] && get_redir_count((data->tab_dir)[i], COND) > 0)
		{
			ret = fill_hc_cmd(data, (data->tab_dir)[i], tab_hc[i]);
			if (ret == -1)
				return (-1);
		}
		i++;
	}
	return (ret);
}

void	set_defval_int_list(int ****list, int list_size)
{
	int	i;

	i = 0;
	while (++i < list_size + 1)
		(*list)[i] = 0;
}

int	get_hc_tab(t_data *data)
{
	int	hc_count;
	int	i;
	int	ret_val;
	int	tab_size;

	hc_count = 0;
	tab_size = get_cmd_count(data->tab_dir);
	data->tab_hc = malloc(sizeof(int **) * (tab_size + 1));
	if (!(data->tab_hc))
		return (-1);
	set_defval_int_list(&data->tab_hc, tab_size);
	i = -1;
	while (++i < tab_size)
	{
		hc_count += get_redir_count((data->tab_dir)[i], COND);
		(data->tab_hc)[i] = malloc(sizeof(int *) * (hc_count + 1));
		if (!(data->tab_hc)[i])
			return (-1);
		if (init_hc_cmd(&(data->tab_hc)[i], hc_count) == -1)
			return (-1);
	}
	ret_val = fill_hc_cmd_list(data, data->tab_hc, tab_size, hc_count);
	return (ret_val);
}
