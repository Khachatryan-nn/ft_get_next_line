/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:57:43 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/22 20:42:34 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	that_next_line(int fd, char *buffer, char **line, char **backup, int i)
{
	int	len;

	i = 0;
	printf("this function was called and backup contains(before):%s!\n", *backup);
	len = ft_strlen(*backup);
	len += read(fd, buffer, BUFFER_SIZE);
//	printf("this function read file: buffer = %s\n", buffer);
	*backup = ft_strjoin(*backup, buffer);
	free(buffer);
	buffer = 0;
	printf("this function allocated memory for backup and gived him right value. backup = %s len = %d\n", *backup, len);
	while (i < len && *backup[i] != '\n' && *backup[i] != '\0')
		i++;
//	printf("this function coutned symbols before reaching to \\n or \\0: i = %d len = %d\n", i, len);
	if ((*backup[i] != '\n' || *backup[i] != '\0') && i == len)
	{
		free(buffer);
		buffer = 0;
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		that_next_line(fd, buffer, line, backup, i);
		return 0;
	}
	*line = ft_substr(*backup, 0, i);
//	printf("this function reaches to \\n or \\0 and received a new string: %s\n", line);
	buffer = ft_substr(*backup, i + 1, ft_strlen(*backup) - i - 1);
//	printf("this function makes copy of backup: %s\n", backup);
	free(*backup);
//	printf("this function free backup\n");
	*backup = ft_substr(buffer, 0, ft_strlen(buffer));
	printf("this function creates new backup with excess symbols:%s\n",* backup);
	free(buffer);
	buffer = 0;
	return 1;
}


char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	backup = ft_strdup("");
	that_next_line(fd, buffer, &line, &backup, i);
	return (line);
}

int	main(void)
{
	int	fd1 = open("text.txt", O_RDONLY);
	printf("								result of function:%s\n", get_next_line(fd1));
	printf("								result of function:%s\n", get_next_line(fd1));
	printf("								result of function:%s\n", get_next_line(fd1));
}

#if 0

in first -> read first BUFFER_SIZE symbols from file
if there any \0 or \n then return new string and save excess part of string in backup
if there aren't any \0 or \n then save all string in our backup and read from file BUFFER_SIZE symbols
then repeat the same
in the end save in backup only extra symbols that current string doesn't contain


Latin is such a beautiful language
But I prefer to learn French
Because I'm in love with France
And with Paris also!

For the genereting static variable's new value we can use strjoin, because this function creates new string that contains 2 gived to him strings
First string gonna be our Backup string, and second one will be our new string that we planing to join

In first we need to create backup string that contains string that we have read. After that we need to check if is there any \0 \n symbols. In case of that we return new string,
else we saving backup and reading new string, do strjoin with backup, and continue.

Latin is such a -> there isn't any \0 or \n
we need to continue reading from file and save all we have read in static variable
 beautiful lang -> there is also haven't \0 \n
need to continue reading from file and save all we have read in the same static variable
auge\nBut I pre -> there we have new line
--- We need to create new line that contains "Latin is such a beautiful langugae\n" and return him
--- Also we need to save "But I pre" in another static variable, because we need to use for the next GNL reading request
#endif

#if 0
[There
is
new
lines!
]
--	>	buffer	->	[There\nis\nnew\nlines!\n\n]
--	>	line	->	[There\n\0]
--	>	backup	->	[is\nnew\nlines!\n\n]
#endif

#if 0
[There
is
new
lines!
]
--	>	buffer	->	[Ther]
--	>	line	->	[Ther]
--	>	backup	->	[Ther]
#endif

#if 0
[There
is
new
lines!
]
--	>	buffer	->	[There\nis\nnew\nlines!\n\n]
--	>	line	->	[There\n\0]
--	>	backup	->	[is\nnew\nlines!\n\n]
#endif