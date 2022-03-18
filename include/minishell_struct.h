/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:45:01 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/07 14:18:56 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

extern int	g_ret_val;

enum e_flag
{
	PIPE = 1,
	IN_REDIR ,
	HERE_DOC ,
	OUT_REDIR ,
	OUT_EOF ,
	COND ,
	FILE_OUT ,
	FILE_IN ,
	CMD ,
	ARG ,
	UNDIF_CHAR ,
	AMBIGU_FILE ,
	FILE_EOF ,
};

typedef struct s_quote
{
	struct s_data	*_data;
	char			*lst_str1;
	int				s_quote;
	int				d_quote;
}	t_quote;

typedef struct s_token
{
	char			*str;
	char			*save_str;
	int				to_split;
	int				is_quote;
	int				temp_quote;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_data
{
	t_token	*lst_token;
	t_token	*lst_token_temp;
	t_token	**tab_dir;
	int		***tab_hc;
	char	***tab_cmd;
	char	**env;
	int		**tab_pid;
	int		**tab_read_fd;
	char	*entry;
	int		first_time_pwd;
	int		only_void;
	int		size_tab;
	int		i;
}								t_data;

#endif
