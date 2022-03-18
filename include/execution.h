/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:02:36 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 01:36:17 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

void	exec_cmd(t_data *data, char **envp, int i);
char	*get_bin_path(char *command);
char	**get_path_env(char **envp);
void	new_proccess_cmd(t_data *data, int i, int pipe_in, int pipe_fd[2]);
void	check_hc(int **tab_hc);
void	add_to_waitlist(int *tab_pid, int pid, int i);

int		prepare_redir_in(t_token *redir_in, int **hc_cmd, t_data *data, int i);
int		prepare_redir_out(t_data *data, t_token *redir_out);
int		execute_list(t_data *data, int **tab_pid, int **tab_read_fd);
int		try_builtin(t_data *data, int i);
int		try_errno(char *prefix);
int		is_simple_cmd(t_data *data);
int		wait_all(int *tab_pid, int ret_val);
int		get_cmd_count(t_token **tab_dir);
int		is_path_empty(char **path_list, int i, char *full_path);

#endif
