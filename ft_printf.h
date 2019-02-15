/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:41:28 by anttran           #+#    #+#             */
/*   Updated: 2019/02/13 11:42:26 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct			s_attr
{
	char				flags[6];
	unsigned long long	width;
	unsigned long long	prec;
	char				lms[3];
	char				conv[2];
}						t_attr;

typedef struct			s_color
{
	char				*key;
	char				*value;
}						t_color;

int						ft_printf(const char *f, ...);
int						set_attr(const char *f, t_attr *attr, int i);
int						di(va_list ap, t_attr *attr);
int						oux(va_list ap, t_attr *attr);
int						dubz(va_list ap, t_attr *attr);

#endif
