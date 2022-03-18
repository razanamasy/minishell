/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cdpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:38:02 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:38:43 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab_path(char **tab_path)
{
	int	i;

	i = 0;
	while (tab_path[i] != NULL)
	{
		if (tab_path[i] != NULL)
		{
			free(tab_path[i]);
			tab_path[i] = NULL;
		}
		i++;
	}
	if (tab_path != NULL)
		free(tab_path);
}

int	fail_malloc_path(char ***tab_path)
{
	free_tab_path(*tab_path);
	return (1);
}
