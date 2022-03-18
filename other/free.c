/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:33:20 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/06 09:09:40 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_allocated(t_data *data)
{
	if (data->entry != NULL)
	{
		free(data->entry);
		data->entry = NULL;
	}
	if (data->lst_token)
	{
		free_lst_token_content(&(data->lst_token));
		free(data->lst_token);
		data->lst_token = NULL;
	}
	if (data->tab_cmd)
	{
		free_tab_cmd_content(data->tab_cmd, data->size_tab);
		free(data->tab_cmd);
		data->tab_cmd = NULL;
	}
	if (data->tab_dir)
	{
		free_tab_dir_content(data->tab_dir, data->size_tab);
		free(data->tab_dir);
		data->tab_dir = NULL;
	}
}

void	free_env(t_data *data)
{
	int	i;

	i = 0;
	if (data->env == NULL)
		return ;
	while ((data->env)[i])
	{
		free((data->env)[i]);
		i++;
	}
	free(data->env);
}

void	free_bef_readline(t_data *data)
{
	free_env(data);
	close(3);
	close_std();
	rl_clear_history();
}
