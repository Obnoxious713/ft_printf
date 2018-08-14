/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:57:34 by jfleisch          #+#    #+#             */
/*   Updated: 2018/08/08 14:57:36 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/*
** ------ LIBRARIES ------
*/
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
** ------ TYPEDEFS ------
*/
typedef struct	s_flag
{
	int			l_1;
	int			l_2;
	int			h_1;
	int			h_2;
	int			j;
	int			z;
	int			loc;
}				t_flag;

typedef struct	s_b_a
{
	int			size;
	int			just_size;
	int			perc;
	int			before_size;
	int			after_size;
	int			before_len;
	int			after_len;
	int			precision;
	int			space;
}				t_b_a;

typedef struct	s_form
{
	int			s;
	int			S1;
	int			p;
	int			d;
	int			D1;
	int			i;
	int			o;
	int			O1;
	int			u;
	int			U1;
	int			x;
	int			X1;
	int			c;
	int			C1;
	int			len;
}				t_form;

typedef struct	s_print
{
	int			cap;
	int			plus;
	int			minus;
	int			sharp;
	int			zed;
	int			l_1;
	int			l_2;
	int			h_1;
	int			h_2;
	int			j;
	int			z;
	int			loc;
	int			size;
	int			just_size;
	int			perc;
	int			before_size;
	int			after_size;
	int			before_len;
	int			after_len;
	int			precision;
	int			space;
	// t_flag		*flag;
	// t_b_a		*print;
}				t_print;

/*
** ------ FUNCTIONS ------
*/
int             ft_printf(const char *format, ...);
void			def_val(t_print *print, t_form *form);
void 			def_val2(t_print *print);
int				parser(const char *format, t_print *print, t_form *form, va_list vl);
int				get_loc(const char *format, int i, t_print *print);
int			parse_flag(const char *format, int i, t_print *print);
int			parse_just(const char *format, int i, t_form *form, t_print *print);
int			parse_size(const char *format, int i, t_print *print);
int			parse_form2(const char *format, int i, t_form *form);
int			parse_form(const char *format, int i, t_form *form);

// man3 stdarg && printf
#endif
