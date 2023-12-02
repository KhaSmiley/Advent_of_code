/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsmiley <xsmiley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:10:25 by xsmiley           #+#    #+#             */
/*   Updated: 2023/12/02 14:58:00 by xsmiley          ###   ########.fr       */
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

char find_last(char *str)
{
    int i = ft_strlen(str);
    int result = 0;
    
    while(1)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {    
            return (str[i]);
        }
        i--;
    }
}

char find_first(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            return (str[i]);
        }
        i++;
    }
}

int main (int argc, char *argv[])
{
    int fd;
    int result;
    char *before;
    char first;
    char last;
    char *line;
    int final_result = 0;
    
    fd = open(argv[1], O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        first = find_first(line);
        last = find_last(line);
        before = final_char(first, last);
        final_result += atoi_and_add(before);
    }
    printf("%d", final_result);
    close (fd);
}