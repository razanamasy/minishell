/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_last_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:13:12 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 16:15:28 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_no_file(char *old_path_before, char **old_path_before_cpy)
{
	write(2, old_path_before, ft_strlen(old_path_before));
	write(2, " : No such file or directory\n", 29);
	free(*old_path_before_cpy);
	*old_path_before_cpy = NULL;
}

void	write_last_pwd(char **old_path_before_cpy, char *pwd_path_after)
{
	if (*old_path_before_cpy[0] != '\0')
		write(1, pwd_path_after, ft_strlen(pwd_path_after));
	free(*old_path_before_cpy);
	*old_path_before_cpy = NULL;
	write (1, "\n", 1);
}

int	cd_last_pwd(t_data *data, int mode)
{
	char	*old_path_before;
	char	*pwd_path_before;
	char	pwd_path_after[PATH_MAX];
	char	*old_path_before_cpy;

	(void)mode;
	pwd_path_before = ft_getenv("PWD", data);
	old_path_before = ft_getenv_env("OLDPWD", data);
	if (old_path_before)
		old_path_before_cpy = ft_strdup(old_path_before);
	if (old_path_before == NULL)
	{
		write(2, "OLDPWD not set\n", 16);
		return (1);
	}
	if (old_path_before[0] != '\0' && chdir(old_path_before) == -1)
	{
		write_no_file(old_path_before, &old_path_before_cpy);
		return (1);
	}
	if (replacement_condition(pwd_path_before, data) == 1)
		return (1);
	getcwd(pwd_path_after, PATH_MAX);
	write_last_pwd(&old_path_before_cpy, pwd_path_after);
	return (0);
}
