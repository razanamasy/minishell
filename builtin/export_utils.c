/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:19:51 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:20:34 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	size_env(char **env)
{
	int	size_env;

	size_env = 0;
	while (env[size_env])
		size_env++;
	return (size_env);
}

int	arg_with_equal(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	equal_or_end(char c)
{
	if (c == '=' || c == '\0')
		return (1);
	return (0);
}

void	free_fail_env(char **fail_env)
{
	int	i;

	i = 0;
	while (fail_env[i])
	{
		free(fail_env[i]);
		i++;
	}
	if (fail_env)
		free(fail_env);
}

int	reattr_and_err(t_data *data, int i, char **old_arg)
{
	data->env[i] = *old_arg;
	return (1);
}
