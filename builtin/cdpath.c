/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdpath.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:20:08 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 16:27:38 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_tab(char **tab_char, t_data *data, char ***tab_path)
{
	*tab_char = ft_getenv_env("CDPATH", data);
	if (!*tab_char || *tab_char[0] == '\0')
		return (1);
	*tab_path = ft_split_(*tab_char, ':');
	if (!*tab_path)
		return (1);
	return (0);
}

char	*join_slash(int i, int lenght_path, char **tab_path)
{
	char	*path;

	path = NULL;
	if (tab_path[i][lenght_path - 1] == '/')
	{
		path = ft_strdup(tab_path[i]);
		if (!path)
		{
			free_tab_path(tab_path);
			return (NULL);
		}
	}
	else
	{
		path = ft_strjoin_c(ft_strdup(tab_path[i]), '/');
		if (!path)
		{
			free_tab_path(tab_path);
			return (NULL);
		}
	}
	return (path);
}

int	succes_cd(char **path, char ***tab_path,
		char *pwd_before_path, t_data *data)
{
	char	pwd_path_after[PATH_MAX];

	getcwd(pwd_path_after, PATH_MAX);
	write(1, pwd_path_after, ft_strlen(pwd_path_after) + 1);
	write(1, "\n", 2);
	if (replacement_condition(pwd_before_path, data) == 1)
		return (1);
	free_tab_path(*tab_path);
	free_old_str(path);
	return (0);
}

int	check_cdpath(t_data *data, char *arg, char *pwd_before_path)
{
	int		i;
	char	**tab_path;
	char	*tab_char;
	char	*path;

	i = 0;
	if (init_tab(&tab_char, data, &tab_path) == 1)
		return (1);
	while (tab_path[i] != NULL)
	{
		path = join_slash(i, ft_strlen(tab_path[i]), tab_path);
		if (path == NULL)
			return (1);
		path = ft_strjoin(path, arg);
		if (!path)
			return (fail_malloc_path(&tab_path));
		if (!chdir(path))
			return (succes_cd(&path, &tab_path, pwd_before_path, data));
		free_old_str(&path);
		i++;
	}
	free_tab_path(tab_path);
	return (1);
}
