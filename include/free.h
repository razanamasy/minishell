/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:00:18 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/06 19:34:13 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "minishell.h"

void	free_tab_dir_content(t_token **tab_dir, int size_tab);
void	free_tab_cmd_content(char ***tab_cmd, int size_tab);
void	free_lst_token_content(t_token **lst_token);
void	free_str_list(char **str_list);
void	free_inside_env(t_data *data);
void	free_before_here_doc(t_data *data);

void	free_allocated(t_data *data);
void	free_bef_readline(t_data *data);
void	free_env(t_data *data);
void	free_debug(t_data *data);
void	free_2dim_list(void **list);
void	free_3dim_list(void ***list);
void	free_execution_child(t_data *data);
void	free_execution_parent(t_data *data);
void	free_cmd_error(t_data *data, char **cmd, char *bin_path);
void	free_before_execve(t_data *data);
void	close_std(void);

#endif
