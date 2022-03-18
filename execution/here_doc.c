/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:27:13 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/11 12:42:18 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*get_last_hc(int **hc_cmd)
{
	int	i;

	i = 0;
	while (hc_cmd[i])
		i++;
	if (i == 0)
		return (NULL);
	return (hc_cmd[i - 1]);
}

void	close_all_hc(int ***hc_cmd, int tab_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab_size)
	{
		j = 0;
		if (hc_cmd[i])
		{
			while (hc_cmd[i][j])
			{
				close(hc_cmd[i][j][0]);
				close(hc_cmd[i][j][1]);
				j++;
			}
		}
		i++;
	}
}

int	init_hc_cmd(int ***hc_cmd, int hc_count)
{
	int	i;

	i = 0;
	while (i < hc_count)
	{
		(*hc_cmd)[i] = malloc(sizeof(int) * 2);
		if (!(*hc_cmd)[i])
			return (-1);
		pipe((*hc_cmd)[i]);
		i++;
	}
	(*hc_cmd)[i] = NULL;
	return (0);
}

int	write_to_hc(t_data *data, int is_quote, int *hrdc_pipe, char *line)
{
	if (is_quote == 0 && line)
	{
		if (expand_all_var_in_line(data, &line) == -1)
		{
			close_all_hc(data->tab_hc, get_cmd_count(data->tab_dir));
			return (-1);
		}
	}
	if (line)
		write(hrdc_pipe[1], line, ft_strlen(line));
	if (is_quote == 0)
	{
		free(line);
		line = NULL;
	}
	write(hrdc_pipe[1], "\n", 1);
	return (0);
}

/*
 *  Function: here_doc
 *  -------------------------
 *  Handles the here_doc and the transfer of the data to the next command
 *
 *	argv: Parameters of the program
 *	hrdc_pipe: Pipe only for the here_doc
 *
 *  Returns: Success state
 */

int	here_doc(t_data *data, int is_quote, char *delimiter, int *hrdc_pipe)
{
	char	*line;

	line = NULL;
	if (!delimiter)
		delimiter = "";
	while (!isstr_equal(line, delimiter))
	{
		line = readline("> ");
		if ((g_ret_val & 130) == 130)
		{
			dup2(g_ret_val >> 4, 0);
			close(g_ret_val >> 4);
			g_ret_val = 130;
			return (g_ret_val);
		}
		if (check_eof(line, delimiter))
			break ;
		if (!isstr_equal(line, delimiter))
		{
			if (write_to_hc(data, is_quote, hrdc_pipe, line) == -1)
				return (-1);
		}
	}
	return (0);
}
