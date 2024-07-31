/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:03:43 by mla-mona          #+#    #+#             */
/*   Updated: 2024/07/31 19:07:29 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static char	*new_line(char *str)
{
	int		i;
	char	*nline;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0' || str[1] == '\0')
		return (NULL);
	nline = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (*nline == '\0')
	{
		free(nline);
		nline = NULL;
	}
	str[i + 1] = '\0';
	return (nline);
}

char	*get_line(int fd, char *str, char *newline)
{
	int		ret;
	char	*char_tmp;

	ret = 1;
	while (ret != '\0')
	{
		ret = read(fd, str, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		else if (ret == 0)
			break ;
		str[ret] = '\0';
		if (!newline)
			newline = ft_strdup("");
		char_tmp = newline;
		newline = ft_strjoin(char_tmp, str);
		free(char_tmp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = get_line(fd, buf, str);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	str = new_line(line);
	return (line);
}
