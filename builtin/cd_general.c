/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_general.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:02:08 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:14:35 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	special_case(DIR *fd_dir, t_data *data, char *arg)
{
	if (fd_dir == NULL)
	{
		if (!data->first_time_pwd)
		{
			write(2, "chdir: error retrieving current", 31);
			write(2, " directory: getcwd: cannot access", 33);
			write(2, " parent directories: ", 21);
			write(2, "No such file or directory\n", 26);
			return (1);
		}
		else
		{
			write(2, arg, ft_strlen(arg) + 1);
			write(2, ": No such file or directory", 28);
			write (2, "\n", 1);
			return (1);
		}
	}
	else
		closedir(fd_dir);
	return (0);
}

int	change_directory(char *arg, t_data *data, int mode)
{
	char	pwd_path[PATH_MAX];
	char	pwd_before_path[PATH_MAX];
	int		ret;
	DIR		*fd_dir;

	(void)mode;
	ret = 0;
	getcwd(pwd_before_path, PATH_MAX);
	fd_dir = is_dir_null(pwd_before_path);
	if (special_case(fd_dir, data, arg) == 1)
		return (1);
	ret = chdir(arg);
	if (ret != 0)
	{
		perror(arg);
		return (1);
	}
	getcwd(pwd_path, PATH_MAX);
	if (replacement_condition(pwd_before_path, data) == 1)
		return (1);
	return (0);
}
