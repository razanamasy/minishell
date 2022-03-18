/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:38:24 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 18:16:22 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_path_correct(char *path)
{	
	if (path)
	{
		if (path[0])
		{
			if (path[0] == '.')
			{
				if (path[1])
				{
					if (path[1] == '/')
						return (1);
				}
			}
			else if (path[0] == '/')
				return (1);
		}
		return (0);
	}
	return (0);
}

int	is_bin_local(char *command, char **path_list)
{
	int	fd;

	if (!path_list)
	{
		fd = open(command, O_RDONLY);
		if (fd == -1)
			return (-1);
		return (0);
	}
	return (1);
}

int	check_eof(char *line, char *delimiter)
{
	char	*delimiter_temp;
	char	*err_msg;

	if (line == NULL)
	{
		delimiter_temp = ft_strdup(delimiter);
		if (!delimiter_temp)
			exit(1);
		err_msg = ft_strdup(
				"warning: here-document delimited by EOF, wanted: ");
		if (!err_msg)
			exit(1);
		err_with_msg_info(delimiter_temp, err_msg);
		free(delimiter_temp);
		return (1);
	}
	return (0);
}

int	is_str_numeric(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!str[i])
			return (0);
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
	}
	return (1);
}
