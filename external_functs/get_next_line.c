/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:55:35 by arde-jes          #+#    #+#             */
/*   Updated: 2025/01/27 18:32:34 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(char *buffer, int fd)
{
	char		*stash;
	ssize_t		bytes;

	stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, stash, BUFFER_SIZE);
		if (bytes == -1)
			return (free(stash), free(buffer), NULL);
		if (bytes == 0)
			return (free(stash), buffer);
		stash[bytes] = '\0';
		buffer = ft_strjoin(buffer, stash);
		if (!buffer)
		{
			free(stash);
			return (NULL);
		}
	}
	free(stash);
	return (buffer);
}

char	*ft_extract_line(char *buffer)
{
	char	*line;
	int		ct;

	ct = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[ct] != '\n' && buffer[ct] != '\0')
		ct++;
	line = (char *)malloc((ct + 2) * sizeof(char));
	ct = 0;
	while (buffer[ct] != '\n' && buffer[ct] != '\0')
	{
		line[ct] = buffer[ct];
		ct++;
	}
	if (buffer[ct] == '\n')
		line[ct++] = '\n';
	line[ct] = '\0';
	return (line);
}

char	*ft_update_buffer(char *buffer)
{
	int		ct;
	char	*extra_buffer;
	int		len;
	int		newct;

	ct = 0;
	newct = 0;
	while (buffer[ct] != '\0' && buffer[ct] != '\n')
		ct++;
	len = ft_strlen(buffer);
	if (buffer[ct] == '\n')
		ct++;
	extra_buffer = (char *)malloc((len - ct + 1) * sizeof(char));
	if (!extra_buffer)
	{
		free(extra_buffer);
		return (NULL);
	}
	while (buffer[ct] != '\0')
		extra_buffer[newct++] = buffer[ct++];
	extra_buffer[newct] = '\0';
	free(buffer);
	return (extra_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_read_file(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	buffer = ft_update_buffer(buffer);
	return (line);
}
/*
int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return(0);
}*/
