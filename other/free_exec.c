/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:08:48 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/11 12:39:28 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_execution_child(t_data *data)
{
	free_allocated(data);
	free(*(data->tab_pid));
	free_3dim_list((void ***)data->tab_hc);
	free(*(data->tab_read_fd));
	free_env(data);
	close_std();
	close(3);
	rl_clear_history();
}

void	free_cmd_error(t_data *data, char **cmd, char *bin_path)
{
	if (bin_path && bin_path != cmd[0])
		free(bin_path);
	free_2dim_list((void **)cmd);
	free_env(data);
	close_std();
	rl_clear_history();
}

void	free_execution_parent(t_data *data)
{
	free_3dim_list((void ***)data->tab_hc);
	data->tab_hc = NULL;
	free(*(data->tab_read_fd));
	free(*(data->tab_pid));
}

void	free_before_execve(t_data *data)
{
	close_all_hc(data->tab_hc, get_cmd_count(data->tab_dir));
	free_allocated(data);
	free(*(data->tab_pid));
	free_3dim_list((void ***)data->tab_hc);
	free(*(data->tab_read_fd));
	rl_clear_history();
}

void	free_before_here_doc(t_data *data)
{
	free(*(data->tab_pid));
	free(*(data->tab_read_fd));
	free_env(data);
	close_std();
	close(3);
	rl_clear_history();
}
