/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:49:30 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/11 12:39:41 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_to_history(int fd_history, char *entry)
{	
	write(fd_history, entry, ft_strlen(entry));
	write(fd_history, "\n", 1);
	add_history(entry);
}

int	parse_and_print(char *entry, t_token **lst_token, t_data *data)
{
	int	ret;
	int	ret_lex;

	ret = 0;
	ret_lex = lexer(entry, lst_token);
	if (ret_lex)
		return (ret_lex);
	parsing1(lst_token);
	parsing2(lst_token);
	ret = check_syntaxe_err(lst_token);
	if (ret != 0)
		return (ret);
	parse_cmd_arg(lst_token);
	if (expansion(lst_token, data) == 1)
		return (1);
	delete_not_set(lst_token);
	if (!*lst_token)
	{
		data->only_void = 1;
		return (1);
	}
	data->size_tab = get_size_tab(lst_token);
	return (0);
}

int	tab_init_and_print(t_token ***tab_dir, char ****tab_cmd,
		t_token **lst_token)
{
	int	ret;

	ret = 0;
	*tab_dir = create_redir_tab(lst_token, *tab_dir, &ret);
	if (ret == 1)
		return (1);
	*tab_cmd = create_cmd_tab(lst_token, *tab_cmd, &ret);
	if (ret == 1)
		return (1);
	return (0);
}

int	execution(t_data *data, int ret_val)
{
	int	i;
	int	*tab_pid;
	int	*tab_read_fd;

	if (!(ret_val == 0 && !data->only_void))
		return (ret_val);
	i = 0;
	if (init_exec(data, &tab_pid, &tab_read_fd) == -1)
		return (-1);
	data->tab_pid = &tab_pid;
	data->tab_read_fd = &tab_read_fd;
	while (i < get_cmd_count(data->tab_dir))
		tab_read_fd[i++] = 0;
	i = 0;
	ret_val = execute_list(data, data->tab_pid, data->tab_read_fd);
	if (ret_val == -1)
		free_execution_parent(data);
	if (ret_val == -1)
		return (-1);
	close_all_hc(data->tab_hc, get_cmd_count(data->tab_dir));
	while (tab_read_fd[i] != -1 && ret_val == 0)
		close(tab_read_fd[i++]);
	ret_val = wait_all(*(data->tab_pid), ret_val);
	free_execution_parent(data);
	return (ret_val);
}
