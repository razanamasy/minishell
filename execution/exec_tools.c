/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:21:59 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 18:16:26 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_args(char ***cmd)
{
	int	i;

	i = 0;
	while ((*cmd)[i])
	{
		if ((*cmd)[i][0] == 26)
			(*cmd)[i] = "";
		i++;
	}
}

int	check_ambiguous_redir(t_token *tab_dir)
{
	t_token	*sav_tab_dir;
	char	*tab_str_temp;

	sav_tab_dir = tab_dir;
	while (tab_dir)
	{
		if ((tab_dir)->str[0] == 25)
		{
			tab_str_temp = ft_strdup(tab_dir->save_str);
			if (!tab_str_temp)
				return (1);
			err_with_msg_info(": ambiguous redirect",
				tab_str_temp);
			return (1);
		}
		else if (tab_dir->str[0] == 26)
			tab_dir->str = "";
		tab_dir = (tab_dir)->next;
	}
	tab_dir = sav_tab_dir;
	return (0);
}

void	exec_cmd(t_data *data, char **envp, int i)
{
	char	*bin_path;
	char	**cmd;
	int		ret;

	cmd = ft_strlistdup(data->tab_cmd[i]);
	ret = try_builtin(data, i);
	close(3);
	if (ret == -1)
	{
		bin_path = NULL;
		if (ft_strcmp(cmd[0], ".") && ft_strcmp(cmd[0], ".."))
			bin_path = get_bin(cmd[0], envp);
		free_before_execve(data);
		try_accessible(data, cmd, bin_path);
		if (is_path_correct(bin_path))
		{
			clean_args(&cmd);
			execve(bin_path, cmd, envp);
		}
		try_file_error(data, cmd, bin_path);
		try_cmd_not_found(data, cmd, bin_path);
	}
	free_execution_child(data);
	free_2dim_list((void **)cmd);
	exit(ret);
}

char	**get_path_env(char **envp)
{
	char	**path_env;
	char	*temp;
	int		i;

	while (*envp && !isstr_start_equal(*envp, "PATH="))
		envp++;
	if (!*envp)
		return (NULL);
	path_env = ft_split_(*envp + 5, ':');
	if (!path_env)
		return (NULL);
	i = 0;
	while (path_env[i])
	{
		temp = path_env[i];
		path_env[i] = ft_strsufx("/", path_env[i]);
		free(temp);
		i++;
	}
	return (path_env);
}

int	is_path_empty(char **path_list, int i, char *full_path)
{
	if (!path_list[i])
	{
		free(path_list);
		free(full_path);
		return (1);
	}
	return (0);
}
