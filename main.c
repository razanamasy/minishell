/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:45:11 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 19:15:05 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_ret_val;

void	init_data(t_data *data)
{
	data->lst_token = NULL;
	data->lst_token_temp = NULL;
	data->tab_cmd = NULL;
	data->tab_dir = NULL;
	data->entry = NULL;
	data->size_tab = 0;
	data->only_void = 0;
	data->i = 0;
}

int	is_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == '\t')
			i++;
		else
			break ;
	}
	if (i > 0 && str[i] == '\0')
		return (1);
	return (0);
}

int	main_process(char **envp)
{
	t_data	data;
	int		fd_history;
	int		ret_val;

	init_data(&data);
	data.entry = "";
	data.first_time_pwd = 1;
	fd_history = open(".history", O_RDWR | O_CREAT, redir_mode());
	init_history(fd_history);
	data.env = cpy_env(envp);
	while (1)
	{
		data.entry = get_input(&data, data.entry);
		while (is_only_space(data.entry))
			data.entry = get_input(&data, data.entry);
		add_to_history(fd_history, data.entry);
		ret_val = parsing_and_tab(&data);
		if (data.only_void)
			ret_val = 0;
		g_ret_val = execution(&data, ret_val);
		free_allocated(&data);
		data.only_void = 0;
	}
	free_inside_env(&data);
	return (free(data.env), close(fd_history), g_ret_val);
}

int	main(int argc, char **argv, char **envp)
{
	g_ret_val = 0;
	if (argc == 1 && argv && envp)
	{
		custom_sigint();
		ignore_sigquit();
		g_ret_val = main_process(envp);
	}
	return (g_ret_val);
}
