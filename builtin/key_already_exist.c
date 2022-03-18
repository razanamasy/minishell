/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_already_exist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:23:17 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:24:01 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	already_exist(char **env, char *arg)
{
	int	i;
	int	size_key;

	i = 0;
	size_key = 0;
	while (arg[size_key] != '=' && arg[size_key] != '\0')
		size_key++;
	while (env[i])
	{
		if (!(ft_strncmp(env[i], arg, size_key)))
		{
			if ((env[i][size_key] == '='
				|| env[i][size_key] == '\0')
					&& (arg[size_key] == '='
						|| arg[size_key] == '\0'))
				return (1);
		}
		i++;
	}
	return (0);
}
