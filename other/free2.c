/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:07:53 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/06 09:10:21 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_2dim_list(void **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list[i]);
	free(list);
}

void	free_3dim_list(void ***list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			free(list[i][j]);
			j++;
		}
		free(list[i]);
		i++;
	}
	free(list[i]);
	free(list);
}

/*
 *  Function: free_str_list
 *  -------------------------
 *  Frees the list of string passed as parameter
 *  
 *  str_list: List of string to free
 *
 */

void	free_str_list(char **str_list)
{
	int	i;

	i = 0;
	while (str_list[i])
		free(str_list[i++]);
	free(str_list);
}
