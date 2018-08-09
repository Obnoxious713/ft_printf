/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:54:10 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 15:54:11 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/libftprintf.h"
#include "../libft/libft.h"

char            *parse_input(char *input)
{
    char        **args;
    int         i;
    int         y;

    args = (char**)ft_memalloc(sizeof(char*));
    y = -1;
    while (args[++y])
    {
        *args = (char*)ft_memalloc(sizeof(char));
        i = -1;
        while (args[y][++i] && input[i] != ',')
            args[y][i] = input[i];
    }
    return(*args);
}
