/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:36:00 by mbennis           #+#    #+#             */
/*   Updated: 2018/11/26 19:34:46 by mbennis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_count_words(char const *s, char c)
{
	size_t			counter;

	counter = 0;
	while (*(char*)s == c)
		s++;
	while (*s)
	{
		if (*(char*)s == c)
		{
			while (*(char*)s == c)
				s++;
			counter++;
		}
		else
			s++;
	}
	if (*(char*)(s - 1) == c)
	{
		counter--;
	}
	return (++counter);
}

static size_t		ft_word_length(char *str, char c)
{
	size_t			i;

	i = 0;
	while (*str != c && *str)
	{
		i++;
		str++;
	}
	return (i);
}

static char			*ft_fill_words(char **str, char c)
{
	char			*temp;
	char			*word;
	size_t			i;
	unsigned int	len;

	len = 0;
	temp = *str;
	while (*temp == c)
	{
		temp++;
		len++;
	}
	i = ft_word_length(temp, c);
	if ((word = (char*)malloc(sizeof(**str) * (i + 1))))
	{
		*str = *str + len + i;
		len = 0;
		while (len < i)
			word[len++] = *temp++;
		word[len] = '\0';
		return (word);
	}
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**words;
	size_t			i;
	unsigned int	k;
	char			*temp;

	if (s == NULL)
		return (NULL);
	i = ft_count_words(s, c);
	if ((words = (char**)malloc(sizeof(s) * (i + 1))))
	{
		k = 0;
		temp = (char*)s;
		while (k < i)
		{
			words[k] = ft_fill_words(&temp, c);
			k++;
		}
		words[k] = 0;
		return (words);
	}
	return (NULL);
}
