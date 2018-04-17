/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:09:25 by iporsenn          #+#    #+#             */
/*   Updated: 2017/11/24 13:09:27 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	char		**ft_malloc_array(const char *s, char c)
{
	char	**array;
	int		word;

	array = NULL;
	word = 0;
	word = count_word(s, c);
	if (!(array = (char **)ft_memalloc(sizeof(char*) * word + 1)))
		return (NULL);
	array[word] = NULL;
	return (array);
}

static	size_t		ft_count_letter(const char *s, int i, char c)
{
	size_t len;

	len = 0;
	if (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static	void		ft_fill_array(char **array, const char *s, char c)
{
	char	**tmp;
	int		start;
	int		i;

	start = 0;
	tmp = array;
	while (s[start])
	{
		if ((s[start] != c && s[start - 1] == c)
			|| (s[start] != c && start == 0))
		{
			*array = ft_strsub(s, (unsigned int)start,
								ft_count_letter(s, start, c));
			array++;
			start = start + (int)ft_count_letter(s, start, c);
		}
		else
			start++;
	}
	array = tmp;
	i = -1;
}

char				**ft_strsplit(const char *s, char c)
{
	char	**array;

	array = NULL;
	if (!s || !c)
		return (NULL);
	if (!(array = ft_malloc_array(s, c)))
		return (NULL);
	ft_fill_array(array, s, c);
	return (array);
}
