/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:01:46 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/28 16:18:34 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strnjoin(char *s1, char const *s2, size_t n_s2)
{
	char	*new_str;
	int		i;
	size_t	s1_size;

	s1_size = ft_strlen(s1);
	new_str = malloc(sizeof(char) * (s1_size + n_s2 + 1));
	if (!(new_str) || !s1 || !s2)
		return (0);
	i = 0;
	while (i < (int)s1_size)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str += i;
	i = 0;
	while (i < (int)n_s2)
	{
		new_str[i] = s2[i];
		i++;
	}
	new_str -= s1_size;
	new_str[s1_size + n_s2] = '\0';
	free(s1);
	return (new_str);
}

int	ft_free_sec_split(char **halfsplit)
{
	if (!(halfsplit[1]))
	{
		free(halfsplit[0]);
		free(halfsplit);
		return (0);
	}
	return (1);
}

char	**ft_halfsplit(char s[BUFFER_SIZE], char c)
{
	int		firsthalf_size;
	char	**halfsplit;

	firsthalf_size = 0;
	halfsplit = malloc(sizeof(*halfsplit) * 2);
	if (!(halfsplit))
		return (0);
	while (s[firsthalf_size] && s[firsthalf_size] != c)
		firsthalf_size++;
	halfsplit[0] = malloc(sizeof(**halfsplit) * (firsthalf_size + 1));
	if (!(halfsplit[0]))
	{
		free(halfsplit);
		return (0);
	}
	*halfsplit[0] = 'a';
	ft_strlcpy(halfsplit[0], s, firsthalf_size + 1);
	if (s[firsthalf_size] == c)
		s++;
	s += firsthalf_size;
	halfsplit[1] = malloc(sizeof(**halfsplit) * (ft_strlen(s) + 1));
	if (!ft_free_sec_split(halfsplit))
		return (0);
	ft_strlcpy(halfsplit[1], s, ft_strlen(s) + 1);
	return (halfsplit);
}

int	ft_getlinefrom_temp(char *temp, char buffer[BUFFER_SIZE], char **line)
{
	char	**halfsplit;
	int		secondhalf_size;

	halfsplit = ft_halfsplit(temp, '\n');
	free(temp);
	secondhalf_size = (int)ft_strlen(halfsplit[1]);
	if (secondhalf_size != BUFFER_SIZE)
		ft_bzero(buffer, BUFFER_SIZE);
	ft_memcpy(buffer, halfsplit[1], secondhalf_size);
	*line = ft_strdup(halfsplit[0]);
	free(halfsplit[0]);
	free(halfsplit[1]);
	free(halfsplit);
	return (secondhalf_size);
}

int	ft_get_next_line(int fd, char **line)
{
	static char	buffer[256][BUFFER_SIZE + 1];
	int			read_res;
	char		*temp;
	int			secondhalf_size;

	if (fd < 0 || fd == 2 || BUFFER_SIZE < 0 || !line)
		return (-1);
	read_res = 1;
	temp = ft_strdup("");
	if (ft_strlen(buffer[fd]))
		temp = ft_strnjoin(temp, buffer[fd], ft_strlen(buffer[fd]));
	while (!ft_strchr(buffer[fd], '\n') && read_res)
	{
		read_res = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_res == -1)
		{
			free(temp);
			return (-1);
		}
		temp = ft_strnjoin(temp, buffer[fd], read_res);
	}
	secondhalf_size = ft_getlinefrom_temp(temp, buffer[fd], line);
	if (!read_res && !secondhalf_size)
		return (0);
	return (1);
}
