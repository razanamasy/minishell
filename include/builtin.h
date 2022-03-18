/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:50:49 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/05 21:38:35 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		b_exit(t_data *data, char **cmd, int verbose);
//ECHO
int		b_echo(char **args);
int		init_print(int *i, char **args, char **to_print);

//UTILS ENV FCT
void	free_inside_env(t_data *data);
int		get_env_size(char **env);
char	**cpy_env(char **env);
//FT GET ENV
char	*ft_getenv(char *key, t_data *data);
char	*ft_getenv_env(char *key, t_data *data);
//ENV
int		ft_env(t_data *data);
//IS VALID KEY
int		is_valid_key(char *key, char *prefix, int mode);
//ALREADY EXIST
int		already_exist(char **env, char *arg);
//UTILS EXPORT
int		size_env(char **env);
int		arg_with_equal(char *arg);
int		equal_or_end(char c);
void	free_fail_env(char **fail_env);
int		reattr_and_err(t_data *data, int i, char **old_arg);
//EXPORT
int		ft_export(char **tab_cmd, t_data *data, int mode);
//UTILS UNSET
int		get_size_key(char *find_key);
void	reattr_env(char **new_env, int j, t_data *data);
//UNSET
int		ft_unset(char **tab_cmd, t_data *data, int mode);
//UTILS CD PATH
void	free_tab_path(char **tab_path);
int		fail_malloc_path(char ***tab_path);
//CD PATH
int		init_tab(char **tab_char, t_data *data, char ***tab_path);
char	*join_slash(int i, int lenght_path, char **tab_path);
int		succes_cd(char **path, char ***tab_path,
			char *pwd_before_path, t_data *data);
int		check_cdpath(t_data *data, char *arg, char *pwd_before_path);
//CD GENERAL
int		special_case(DIR *fd_dir, t_data *data, char *arg);
int		change_directory(char *arg, t_data *data, int mode);
//CD LAST PWD
int		cd_last_pwd(t_data *data, int mode);
//CD NO ARGS
int		home_not_set(char *home_path);
int		no_arg(t_data *data, int mode);
//CD TO MANY ARG
int		count_args(char **tab_cmd);
//CD UTILS
int		replace_path_env(t_data *data, char *key, char *replacer, int mode);
int		replace_void(t_data *data, char *to_unset);
int		replacement_condition(char *pwd_before_path, t_data *data);
DIR		*is_dir_null(char *pwd_path);
//CD PROCESS
int		to_home1(t_data *data);
int		to_home2(t_data *data);
int		to_oldpwd(t_data *data);
int		to_dot(char **tab_cmd, t_data *data);
int		to_cdpath(int curpath, char *cdpath_before, t_data *data,
			char **tab_cmd);
//CD
int		ft_cd(t_data *data, char **tab_cmd);
//PWD
int		ft_pwd(t_data *data, int mode);

#endif
