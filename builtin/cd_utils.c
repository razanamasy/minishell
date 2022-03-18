/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:28:56 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 16:30:20 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	replace_path_env(t_data *data, char *key, char *replacer, int mode)
{
	char	*new_value;
	char	*new_tab_value[3];
	char	*key_with_equal_cpy;

	(void)mode;
	new_value = NULL;
	key_with_equal_cpy = ft_strdup(key);
	if (!key_with_equal_cpy)
		return (1);
	new_value = ft_strjoin(key_with_equal_cpy, replacer);
	new_tab_value[0] = "export";
	new_tab_value[1] = new_value;
	new_tab_value[2] = NULL;
	ft_export(new_tab_value, data, 0);
	free(new_tab_value[1]);
	return (0);
}

int	replace_void(t_data *data, char *to_unset)
{
	char	*value_to_unset[3];
	char	*value_to_create[3];
	char	*to_unset_cpy1;
	char	*to_unset_cpy2;

	to_unset_cpy1 = NULL;
	to_unset_cpy1 = ft_strdup(to_unset);
	if (!to_unset_cpy1)
		return (1);
	to_unset_cpy2 = NULL;
	to_unset_cpy2 = ft_strdup(to_unset);
	if (!to_unset_cpy2)
		return (1);
	value_to_unset[0] = "unset";
	value_to_unset[1] = to_unset_cpy1;
	value_to_unset[2] = NULL;
	ft_unset(value_to_unset, data, 0);
	value_to_create[0] = "export";
	value_to_create[1] = to_unset_cpy2;
	value_to_create[2] = NULL;
	ft_export(value_to_create, data, 0);
	free (value_to_unset[1]);
	free (value_to_create[1]);
	return (0);
}

int	replacement_condition(char *pwd_before_path, t_data *data)
{
	char	pwd_path[PATH_MAX];

	getcwd(pwd_path, PATH_MAX);
	if (ft_getenv_env("PWD", data))
	{
		if (replace_path_env(data, "OLDPWD=", pwd_before_path, 1) == 1)
			return (1);
	}
	else
	{
		if (replace_void(data, "OLDPWD") == 1)
			return (1);
	}
	if (replace_path_env(data, "PWD=", pwd_path, 1) == 1)
		return (1);
	return (0);
}

DIR	*is_dir_null(char *pwd_path)
{
	DIR	*dir;

	getcwd(pwd_path, ft_strlen(pwd_path) + 1);
	dir = opendir((const char *)pwd_path);
	return (dir);
}
