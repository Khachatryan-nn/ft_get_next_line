/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:16:07 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/27 16:46:27 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*find_next_line(int fd, char *buffer, char *backup)
{
	int		len;
	char	*temp;

	len = 1;
	while (len)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
			return (0);
		else if (len == 0)
			break ;
		if (!backup)
			backup = ft_strdup("");
		buffer[len] = '\0';
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (backup);
}

static char	*del_excess_part(char *line)
{
	size_t	i;
	size_t	len;
	char	*new_backup;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	len = ft_strlen(line) - i;
	new_backup = ft_substr(line, i + 1, len);
	if (*new_backup == '\0')
	{
		free(new_backup);
		new_backup = NULL;
	}
	line[i + 1] = '\0';
	return (new_backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = find_next_line(fd, buf, backup[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup[fd] = del_excess_part(line);
	return (line);
}
