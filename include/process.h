/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:52:31 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/06 10:45:40 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "minishell.h"

void	add_to_history(int fd_history, char *entry);
char	*get_input(t_data *data, char *entry);
void	catch_errno(void);
void	signal_handling(void);
int		main_process(char **envp);
int		parse_and_print(char *entry, t_token **lst_token, t_data *data);
void	parse_fail(t_token **lst_token, char ****tab_cmd, t_token ***tab_dir);
int		tab_init_and_print(t_token ***tab_dir, char ****tab_cmd,
			t_token **lst_token);
int		execution(t_data *data, int ret_val);
int		parsing_and_tab(t_data *data);

#endif
