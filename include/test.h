/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:14:52 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/07 18:44:27 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "minishell.h"

int	is_bin_local(char *command, char **path_list);
int	is_path_correct(char *path);
int	is_str_numeric(char *str);
int	check_eof(char *line, char *delimiter);

#endif
