/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:05:19 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/09 11:26:02 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_history(int fd_history)
{
	char	*line;

	line = NULL;
	while (ft_get_next_line(fd_history, &line))
	{
		add_history(line);
		free(line);
	}
	free(line);
	return (1);
}
