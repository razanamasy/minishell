/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:34:44 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/06 18:42:09 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_key_to_del(char *to_compare, char *find_key, int size_key)
{
	if (!(ft_strncmp(to_compare, find_key, size_key)))
	{
		if ((equal_or_end(to_compare[size_key]))
			&& (equal_or_end(find_key[size_key])))
			return (0);
	}
	return (1);
}

int	recreate_env(int *j, char **new_env, t_data *data, int i)
{
	if (*j < size_env(data->env))
	{
		new_env[*j] = ft_strdup(data->env[i]);
		if (new_env[*j] == NULL)
		{
			free_fail_env(new_env);
			return (1);
		}
		*j = *j + 1;
	}
	return (0);
}

int	delete_key(char *find_key, t_data *data)
{
	int		i;
	int		size_key;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	size_key = 0;
	new_env = (char **)malloc(size_env(data->env) * sizeof(char *));
	if (!new_env)
		return (1);
	size_key = get_size_key(find_key);
	while (data->env[i])
	{
		if (get_key_to_del(data->env[i], find_key, size_key)
			&& recreate_env(&j, new_env, data, i))
			return (1);
		i++;
	}
	reattr_env(new_env, j, data);
	return (0);
}

int	ft_unset(char **tab_cmd, t_data *data, int mode)
{
	int	i;
	int	ret;
	int	ret_valid;

	ret = 0;
	i = 1;
	(void)mode;
	while (tab_cmd[i])
	{
		ret_valid = is_valid_key(tab_cmd[i], "unset : ", 2);
		if (ret_valid == 0 && already_exist(data->env, tab_cmd[i]))
		{
			if (delete_key(tab_cmd[i], data) == 1)
				return (1);
		}
		else if (ret_valid == 1)
			ret = 1;
		i++;
	}
	return (ret);
}
