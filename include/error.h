/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:09:35 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 01:40:58 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

void	try_accessible(t_data *data, char **cmd, char *bin_path);
void	try_cmd_not_found(t_data *data, char **cmd, char *bin_path);
void	catch_exit_hc(t_data *data, int parent_id, int status);
void	try_file_error(t_data *data, char **cmd, char *bin_path);
int		err_with_msg_info(char *error_message, char *additional_info);

#endif
