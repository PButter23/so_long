/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:31 by arde-jes          #+#    #+#             */
/*   Updated: 2025/01/27 18:33:44 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
	{
		return (NULL);
	}
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *buffer)
{
	size_t	len;

	len = 0;
	while (buffer && buffer[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *buffer, char *stash)
{
	char	*str;
	char	*original_buffer;
	size_t	ct;

	ct = 0;
	if (!buffer && !stash)
		return (NULL);
	if (!stash)
		stash = (char *)ft_calloc(1, sizeof(char));
	original_buffer = buffer;
	if (ft_strlen(buffer) + ft_strlen(stash) == 0)
	{
		free(buffer);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(buffer) + ft_strlen(stash) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (buffer && *buffer)
		str[ct++] = *buffer++;
	while (*stash && stash)
		str[ct++] = *stash++;
	str[ct] = '\0';
	free(original_buffer);
	return (str);
}
