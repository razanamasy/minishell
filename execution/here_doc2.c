/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:22:20 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 19:15:01 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_e_val(t_data *data, char *line, int *i, char **e_val)
{
	char	*e_var;
	char	*e_val_tmp;
	int		j;

	j = 1;
	while (ft_isalpha(line[j + *i]) && line[j + *i])
		j++;
	if (j == 0)
		return (-1);
	e_var = malloc(sizeof(char) * (j + 1));
	if (!e_var)
		return (-1);
	ft_strlcpy(e_var, line + *i + 1, j);
	e_val_tmp = ft_getenv_env(e_var, data);
	free(e_var);
	*i += j;
	*e_val = e_val_tmp;
	return (0);
}

int	get_e_val_size(t_data *data, char *line, int *i)
{
	char	*e_val;
	int		size;

	if (get_e_val(data, line, i, &e_val) == -1)
		return (-1);
	if (e_val)
		size = ft_strlen(e_val);
	else
		size = 0;
	return (size);
}

char	*alloc_new_line(t_data *data, char *line)
{
	int		size;
	int		i;
	char	*new_line;
	int		e_val_size;

	size = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && ft_isalpha(line[i + 1]))
		{
			e_val_size = get_e_val_size(data, line, &i);
			if (e_val_size == -1)
				return (NULL);
			size += e_val_size;
		}
		else
			size++;
		if (!(line[i] == '$' && ft_isalpha(line[i + 1])))
			i++;
	}
	new_line = malloc(sizeof(char) * (size + 1));
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*expand_var_in_line(char *e_val, int *k, char *new_line)
{
	int	j;

	j = 0;
	if (e_val)
	{
		while (e_val[j])
		{
			new_line[*k] = e_val[j];
			j++;
			*k = *k + 1;
		}
	}
	return (new_line);
}

int	expand_all_var_in_line(t_data *data, char **line)
{
	int		i;
	int		k;
	char	*e_val;
	char	*new_line;

	i = 0;
	k = 0;
	new_line = alloc_new_line(data, *line);
	if (!new_line)
		return (-1);
	while ((*line)[i])
	{
		if ((*line)[i] == '$' && (*line)[i] && ft_isalpha((*line)[i + 1]))
		{
			if (get_e_val(data, *line, &i, &e_val) == -1)
				return (-1);
			if (e_val)
				new_line = expand_var_in_line(e_val, &k, new_line);
		}
		else if ((*line)[i])
			new_line[k++] = (*line)[i++];
	}
	new_line[k] = '\0';
	*line = new_line;
	return (0);
}
