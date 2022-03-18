/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_many_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:15:44 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:42:39 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_args(char **tab_cmd)
{
	int	nb_args;

	nb_args = 0;
	while (tab_cmd[nb_args])
		nb_args++;
	if (nb_args > 1)
	{
		write(2, "cd : Too many arguments\n", 25);
		return (1);
	}
	return (0);
}
