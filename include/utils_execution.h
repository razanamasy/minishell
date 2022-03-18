/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execution.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:10:51 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/06 09:52:59 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_EXECUTION_H
# define UTILS_EXECUTION_H

# include "minishell.h"

char	*get_bin(char *command, char **envp);
char	**ft_strlistdup(char **strlist);
int		is_path_correct(char *path);
int		check_ambiguous_redir(t_token *tab_dir);
int		redirect_write(t_data *data, char *file);
int		redirect_read(char *file, t_data *data, int i);
int		branch_write_to(int pipe[2], int fd);
int		branch_read_to(int pipe[2], int fd);
int		redirect_write_end(t_data *data, char *file);
char	*dup_cmd(t_data *data, char **cmd_arg, char *bin_path);
int		redir_mode(void);

#endif
