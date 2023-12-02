/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:11:38 by kboulkri           #+#    #+#             */
/*   Updated: 2023/12/02 15:11:39 by kboulkri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"

int atoi_and_add(char *str)
{
    int i = 0;
    int result = 0;
    
    while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
        i++;
	}
    return (result);
}

char *final_char(char c, char d)
{
    char *final;
    char i;

    final = malloc(sizeof (char) * 3);
    final[i] = c;
    i++;
    final[i] = d;
    i++;
    final[i] = '\0';
    return (final);
}

int	ft_strncmp_last(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = ft_strlen(s1);
	if (size == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && (i < size - 1)
		&& (unsigned char)s1[i])
	{
		i--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && (i < size - 1)
		&& (unsigned char)s1[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char find_last(char *str)
{
       int i;

    i = ft_strlen(str);
    while (i >= 0)
    {
        if (str[i] >= '0' && str[i] <= '9')
            return (str[i]);
        else if (ft_strncmp(&str[i], "one", 3) == 0)
            return ('1');
        else if (ft_strncmp(&str[i], "two", 3) == 0)
            return ('2');
        else if (ft_strncmp(&str[i], "three", 5) == 0)
            return ('3');
        else if (ft_strncmp(&str[i], "four", 4) == 0)
            return ('4');
        else if (ft_strncmp(&str[i], "five", 4) == 0)
            return ('5');
        else if (ft_strncmp(&str[i], "six", 3) == 0)
            return ('6');
        else if (ft_strncmp(&str[i], "seven", 5) == 0)
            return ('7');
        else if (ft_strncmp(&str[i], "eight", 5) == 0)
            return ('8');
        else if (ft_strncmp(&str[i], "nine", 4) == 0)
            return ('9');
        else
            i--;
    }
    return ('F');
}

char find_first(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            return (str[i]);
        else if (ft_strncmp(&str[i], "one", 3) == 0)
            return ('1');
        else if (ft_strncmp(&str[i], "two", 3) == 0)
            return ('2');
        else if (ft_strncmp(&str[i], "three", 5) == 0)
            return ('3');
        else if (ft_strncmp(&str[i], "four", 4) == 0)
            return ('4');
        else if (ft_strncmp(&str[i], "five", 4) == 0)
            return ('5');
        else if (ft_strncmp(&str[i], "six", 3) == 0)
            return ('6');
        else if (ft_strncmp(&str[i], "seven", 5) == 0)
            return ('7');
        else if (ft_strncmp(&str[i], "eight", 5) == 0)
            return ('8');
        else if (ft_strncmp(&str[i], "nine", 4) == 0)
            return ('9');
        else
            i++;
    }
    return ('F');
}

int main (int argc, char **argv)
{
    int fd;
    char first;
    char last;
    char *before;
    char *line;
    int final_result = 0;
    int y = 0;
    
    line = NULL;
    fd = open(argv[1], O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        first = find_first(line);
        last = find_last(line);
        if ((first >= '0' && first <= '9') && (last >= '0' && last <= '9'))
        {    
            before = final_char(first, last);
            final_result += atoi_and_add(before);
        }
    }
    printf("%d", final_result);
}