/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:09:09 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/18 17:56:24 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	ft_countwords(char const *s, char c)
{
	int	word_bool;
	int	word_count;

	word_bool = 0;
	word_count = 0;
	while (*s)
	{
		if (*s != c && !word_bool)
		{
			word_bool = 1;
			word_count++;
		}
		if (*s == c)
			word_bool = 0;
		s++;
	}
	return (word_count);
}

static void	free_split(char **word_split, unsigned int word_count)
{
	unsigned int	i;

	i = 0;
	while (i < word_count)
	{
		free(word_split[i]);
		i++;
	}
	free(word_split);
}

static char	*make_word(char const *s, char c)
{
	int		word_len;
	char	*word_res;

	word_len = 0;
	while (s[word_len] != c && s[word_len])
		word_len++;
	word_res = (char *) malloc(sizeof(char) * (word_len + 1));
	if (!word_res)
		return (NULL);
	ft_strlcpy(word_res, s, word_len + 1);
	return (word_res);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	word_count;
	char			**word_split;

	i = 0;
	word_count = ft_countwords(s, c);
	word_split = (char **) malloc (sizeof(char *) * (word_count + 1));
	if (!word_split || !s)
		return (NULL);
	while (i < word_count)
	{
		while (*s == c)
			s++;
		word_split[i] = make_word(s, c);
		if (!word_split[i])
		{
			free_split(word_split, i);
			return (NULL);
		}
		s += ft_strlen(word_split[i]);
		i++;
	}
	word_split[i] = NULL;
	return (word_split);
}

/* #include <stdio.h>

int main(void)
{
    char **result;
    int i;

    // Test 1: Basic split by space
    printf("Test 1: \"Hello World\" with space delimiter\n");
    result = ft_split("Hello World", ' ');
    i = 0;
    while (result[i])
    {
        printf("[%d]: %s\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    printf("\n");

    // Test 2: Multiple delimiters
    printf("Test 2: \"***Hello**World***\" with '*' delimiter\n");
    result = ft_split("***Hello**World***HI***I***AM***", '*');
    i = 0;
    while (result[i])
    {
        printf("[%d]: %s\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    printf("\n");
	
    // Test 2a: ONLY Multiple delimiters
    printf("Test 2a: \"********\" with '*' delimiter\n");
    result = ft_split("********", '*');
    i = 0;
    while (result[i])
    {
        printf("[%d]: %s\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    printf("\n");

    // Test 3: Empty string
    printf("Test 3: Empty string with space delimiter\n");
    result = ft_split("", ' ');
    i = 0;
    while (result[i])
    {
        printf("[%d]: %s\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    printf("\n");

    // Test 4: No delimiter in string
    printf("Test 4: \"NoDelimiterHere\" with ',' delimiter\n");
    result = ft_split("NoDelimiterHere", ',');
    i = 0;
    while (result[i])
    {
        printf("[%d]: %s\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    printf("\n");

    // Test 5: NULL string (should handle gracefully)
    printf("Test 5: NULL string\n");
    result = ft_split(NULL, ' ');
    if (result == NULL)
        printf("Correctly returned NULL for NULL input\n");
    else
    {
        i = 0;
        while (result[i])
        {
            printf("[%d]: %s\n", i, result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    
    return (0);
} */