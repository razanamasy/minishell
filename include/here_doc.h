/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:03:19 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/11 12:41:59 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

# include "minishell.h"

char	*expand_var_in_line(char *e_val, int *k, char *new_line);
int		expand_all_var_in_line(t_data *data, char **line);
int		get_e_val(t_data *data, char *line, int *i, char **e_val);
int		here_doc(t_data *data, int is_quote, char *delimiter, int *hrdc_pipe);
int		fill_hc_cmd(t_data *data, t_token *cmd_dir, int **hc_cmd);
int		*get_last_hc(int **hc_cmd);
int		get_hc_tab(t_data *data);
int		init_hc_cmd(int ***hc_cmd, int hc_count);
void	close_all_hc(int ***hc_cmd, int tab_size);

#endif
