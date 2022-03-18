/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:24:11 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:30:40 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_mess(void)
{
	write(2, "chdir: error retrieving current", 31);
	write(2, " directory: getcwd: cannot access", 33);
	write(2, " parent directories: ", 21);
	write(2, "No such file or directory\n", 26);
}

int	ft_pwd(t_data *data, int mode)
{
	char	buf[PATH_MAX];
	char	*ret_pwd;

	(void)mode;
	ret_pwd = getcwd(buf, PATH_MAX);
	if (ret_pwd == NULL && data->first_time_pwd)
	{
		data->first_time_pwd = 0;
		error_mess();
		data->first_time_pwd = 1;
		return (1);
	}
	else if (ret_pwd == NULL && !data->first_time_pwd)
	{
		error_mess();
		return (1);
	}
	else
	{
		write(1, buf, ft_strlen(buf));
		write (1, "\n", 1);
	}
	return (0);
}
