/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:34:51 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 16:35:26 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_data *data)
{
	int	size_line;
	int	i;

	size_line = 0;
	i = 0;
	while (data->env[i])
	{
		size_line = ft_strlen(data->env[i]);
		if (ft_strchr(data->env[i], '=') != NULL)
		{
			write(1, data->env[i], size_line);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
