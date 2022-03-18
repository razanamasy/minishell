/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:35:59 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:19:36 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only_replace(char *arg, t_data *data)
{
	int		i;
	int		size_key;
	char	*old_arg;

	i = -1;
	size_key = 0;
	size_key = get_size_key(arg);
	while (data->env[++i])
	{
		if (!(ft_strncmp(data->env[i], arg, size_key)))
		{
			if (equal_or_end(data->env[i][size_key])
				&& equal_or_end(arg[size_key]))
			{
				old_arg = data->env[i];
				data->env[i] = ft_strdup(arg);
				if (!data->env[i])
					return (reattr_and_err(data,
							i, &old_arg));
				free_old_str(&old_arg);
				return (0);
			}
		}
	}
	return (1);
}

int	realloc_env(char *arg, t_data *data)
{
	char	**new_env;
	int		s_env;
	int		i;

	i = 0;
	s_env = size_env(data->env);
	new_env = (char **)malloc((s_env + 1 + 1) * sizeof(char *));
	if (!new_env)
		return (1);
	while (data->env[i])
	{
		new_env[i] = ft_strdup(data->env[i]);
		if (!new_env[i])
			free_fail_env(new_env);
		i++;
	}
	new_env[i] = ft_strdup(arg);
	if (!new_env[i])
		free_fail_env(new_env);
	new_env[i + 1] = NULL;
	free_inside_env(data);
	data->env = new_env;
	return (0);
}

int	fill_or_replace(char *arg, t_data *data)
{
	if (already_exist(data->env, arg))
	{
		if (arg_with_equal(arg))
		{
			if (only_replace(arg, data))
				return (1);
		}
	}
	else
	{
		if (realloc_env(arg, data))
			return (1);
	}
	return (0);
}

void	affiche_env(t_data *data)
{
	int	i;
	int	size_str;

	i = 0;
	size_str = 0;
	while (data->env[i])
	{
		size_str = ft_strlen(data->env[i]);
		write (1, "export ", 7);
		write (1, data->env[i], size_str);
		write (1, "\n", 1);
		i++;
	}
}

int	ft_export(char **tab_cmd, t_data *data, int mode)
{
	int	local_ret_val;
	int	i;

	i = 1;
	local_ret_val = 0;
	(void)mode;
	if (tab_cmd[1] == NULL)
		affiche_env(data);
	while (tab_cmd[i])
	{
		if (!is_valid_key(tab_cmd[i], "export : ", 1))
		{
			if (fill_or_replace(tab_cmd[i], data))
				return (1);
		}
		else
			local_ret_val = 1;
		i++;
	}
	return (local_ret_val);
}
