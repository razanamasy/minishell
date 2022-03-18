/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:47:57 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 19:14:39 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input(t_data *data, char *entry)
{
	entry = malloc(sizeof(char) * 2);
	custom_sigint();
	if (!entry)
		return (NULL);
	entry[0] = '\0';
	while (entry[0] == '\0')
	{
		if (entry != NULL)
		{
			free(entry);
			entry = NULL;
		}
		entry = readline("Minishell$ ");
		if (entry == NULL)
		{
			write(1, "exit\n", 5);
			free_bef_readline(data);
			exit(g_ret_val);
		}
	}
	return (entry);
}

void	catch_errno(void)
{
	if (DEBUG)
		perror("Minishell:");
}

void	parse_fail(t_token **lst_token, char ****tab_cmd, t_token ***tab_dir)
{
	if (lst_token)
	{
		free_lst_token_content(lst_token);
	}
	if (*tab_dir != NULL)
	{
		free_tab_dir_content(*tab_dir, 0);
		free(*tab_dir);
		tab_dir = NULL;
	}
	if (*tab_cmd != NULL)
	{
		free_tab_cmd_content(*tab_cmd, 0);
		free(*tab_cmd);
		tab_cmd = NULL;
	}
}

int	parsing_and_tab(t_data *data)
{
	t_token	*lst_token;
	t_token	**tab_dir;
	char	***tab_cmd;
	int		ret;

	ret = 0;
	lst_token = NULL;
	tab_dir = NULL;
	tab_cmd = NULL;
	ret = parse_and_print(data->entry, &lst_token, data);
	if (ret != 0 || data->only_void)
	{
		parse_fail(&lst_token, &tab_cmd, &tab_dir);
		return (ret);
	}
	ret = tab_init_and_print(&tab_dir, &tab_cmd, &lst_token);
	if (ret != 0)
	{
		parse_fail(&lst_token, &tab_cmd, &tab_dir);
		return (ret);
	}
	data->lst_token = lst_token;
	data->tab_cmd = tab_cmd;
	data->tab_dir = tab_dir;
	return (ret);
}
