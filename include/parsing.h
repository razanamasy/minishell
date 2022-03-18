/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:57:40 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/06 10:12:07 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
//UTILS LEXER
int		is_redir(enum e_flag token);
int		return_condition_lexer(int ret);
int		check_quote(int *d_quote, int *s_quote, char entry, char **lst_str);
int		check_quote_expand(t_quote *quote, char entry, char **lst_str,
			t_token *control);
int		check_pipe(char **lst_str, t_token **lst_token, char entry);
int		check_redir(char **lst_str, t_token **lst_token, int *i, char *entry);
int		check_break_space(char entry, char **lst_str, t_token **lst_token);
//PARSING
int		lexer(char *entry, t_token **lst_token);
int		check_syntaxe_err(t_token **alst);
void	parsing1(t_token **alst);
void	parsing2(t_token **alst);
//EXPANSION
//INSERT LST
int		insert_lst(t_token *control_big, t_token *small);
//EXP UTILS REPLACE AND SPLIT
int		push_or_get_name_size(char *lst_str1, char **lst_str2);
int		is_ret_val(char **lst_str2, int *i);
int		end_of_story(char **lst_str2);
int		fail(char **lst_str2);
//EXP REPLACE AND SPLIT
int		push_rest(int data_i, char **lst_str2,
			int space_start, t_token **small_lst);
int		replace_and_split(int *i, char *lst_str1, char **lst_str2,
			t_data *data);
//EXP REPLACE ONLY
int		replace_var(int *i, char *lst_str1, char **lst_str2, t_data *data);
//EXP UTILS PROC REPLACE
void	save_str_not_set(t_token *control, char *lst_str2);
int		replace_all_void(char **lst_str2, t_token **lst_temp);
int		push_last_node(char **lst_str2, t_token **lst_temp);
int		is_file_cond(enum e_flag token);
//EXP PROC REPLACE
int		replace_str(char *lst_str1, t_token *control, t_data *data);
//EXP MAIN
int		expansion(t_token **lst_token, t_data *data);
void	parse_cmd_arg(t_token **alst);
int		delete_not_set(t_token **lst_token);
#endif
