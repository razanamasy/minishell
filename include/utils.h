/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:55:43 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/04 14:16:06 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

int	get_size_tab(t_token **parse);
int	is_quote(char c);
int	push_str(char **lst_str, char *str_to_join);
int	lst_push_cpy(t_token *to_cpy, t_token **lst_token);
int	push_nbr(char **lst_str, int n);
int	push_c(char **lst_str, char c);
int	lst_push(char **lst_str, t_token **lst_token);
int	check_quote_err(int s_quote, int d_quote);
int	fail_malloc_check(char **lst_str);
int	is_space(char c);
int	get_lst_size(t_token **lst);
int	ft_get_next_line(int fd, char **line);

#endif
