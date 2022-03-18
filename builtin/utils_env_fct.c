/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:39:08 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:40:06 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_inside_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		free(data->env[i]);
		i++;
	}
	free(data->env);
	data->env = NULL;
}

int	get_env_size(char **env)
{
	int	size;

	size = 0;
	while (env[size] != NULL)
		size++;
	return (size);
}

char	**cpy_env(char **env)
{
	int		j;
	int		size_env;
	char	**new_env;

	j = 0;
	size_env = get_env_size(env);
	new_env = (char **)malloc((size_env + 1) * sizeof(char *));
	if (!new_env)
		return (NULL);
	while (env[j] != NULL)
	{
		new_env[j] = ft_strdup(env[j]);
		j++;
	}
	new_env[j] = NULL;
	return (new_env);
}
