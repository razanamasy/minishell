/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:20:49 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:23:04 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *key, t_data *data)
{
	int	size_key;
	int	i;

	i = 0;
	size_key = 0;
	while (key[size_key] != '=' && key[size_key] != '\0')
		size_key++;
	while (data->env[i])
	{
		if (!(ft_strncmp(data->env[i], key, size_key)))
		{
			if ((data->env[i][size_key] == '='
				|| data->env[i][size_key] == '\0')
					&& (key[size_key] == '='
						|| key[size_key] == '\0'))
			{
				if (data->env[i][size_key] == '\0')
					return ("\0");
				else
					return (&(data->env[i][size_key + 1]));
			}
		}
		i++;
	}
	return (NULL);
}

char	*ft_getenv_env(char *key, t_data *data)
{
	int	size_key;
	int	i;

	i = 0;
	size_key = 0;
	while (key[size_key] != '=' && key[size_key] != '\0')
		size_key++;
	while (data->env[i])
	{
		if (!(ft_strncmp(data->env[i], key, size_key)))
		{
			if ((data->env[i][size_key] == '=')
				&& (key[size_key] == '='
					|| key[size_key] == '\0'))
				return (&(data->env[i][size_key + 1]));
		}
		i++;
	}
	return (NULL);
}
