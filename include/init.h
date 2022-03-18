/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:50:49 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/06 10:45:49 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "minishell.h"

//INIT TAB REDIR
//UTILS
int		add_maillon_lst(t_token **one_lst_redir, t_token *control_parse);
int		init_all_lst(t_token **tab_redir, int size_tab);
//PROCESS FILL
int		scan_here_doc(t_token *one_tab_redir, t_token *control_parse);
int		scan_redir_in(t_token *one_tab_redir, t_token *control_parse);
int		scan_redir_out(t_token *one_tab_redir, t_token *control_parse);

t_token	**create_redir_tab(t_token **al_parse, t_token **tab_redir, int *ret);
void	get_the_right_pipe(t_token **control_parse, int index);
int		get_the_cmd(t_token **control_parse, char ***one_tab_cmd,
			int index, int *y);
int		get_all_args(t_token **control_parse, char ***one_tab_cmd,
			int index, int *y);
int		get_size_cmd(t_token **al_parse, int index);
char	***create_cmd_tab(t_token **parse, char ***tab_cmd, int *ret);
int		init_history(int fd_history);
//EXEC
int		init_exec(t_data *data, int **tab_pid, int **tab_read_fd);

#endif
