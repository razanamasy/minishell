/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:17:41 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 01:40:08 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_exec(t_data *data, int **tab_pid, int **tab_read_fd)
{
	int	cmd_count;

	cmd_count = get_cmd_count(data->tab_dir);
	*tab_pid = malloc(sizeof(int) * (cmd_count + 1));
	if (!*tab_pid)
		return (-1);
	*tab_read_fd = malloc(sizeof(int) * cmd_count);
	if (!*tab_read_fd)
		return (-1);
	return (0);
}
