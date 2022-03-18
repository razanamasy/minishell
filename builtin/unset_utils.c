/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:37:22 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:37:50 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_size_key(char *find_key)
{
	int	size_key;

	size_key = 0;
	while (find_key[size_key] != '=' && find_key[size_key] != '\0')
		size_key++;
	return (size_key);
}

void	reattr_env(char **new_env, int j, t_data *data)
{
	new_env[j] = NULL;
	free_inside_env(data);
	data->env = new_env;
}
