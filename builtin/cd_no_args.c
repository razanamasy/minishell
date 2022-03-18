/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_no_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:19:20 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 16:19:54 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	home_not_set(char *home_path)
{
	if (!home_path)
	{
		write(2, "HOME not set\n", 14);
		return (1);
	}
	return (0);
}

int	no_arg(t_data *data, int mode)
{
	char	*home_path;
	char	*pwd_before_path;

	(void)mode;
	home_path = NULL;
	home_path = ft_getenv_env("HOME", data);
	pwd_before_path = ft_getenv("PWD", data);
	if (home_not_set(home_path) == 1)
		return (1);
	if (home_path[0] == '\0')
		return (0);
	if (chdir(home_path) == -1)
	{
		write(2, home_path, ft_strlen(home_path));
		write(2, ": No such file or directory", 28);
		write (2, "\n", 1);
		return (1);
	}
	if (replacement_condition(pwd_before_path, data) == 1)
		return (1);
	return (0);
}
