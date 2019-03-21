/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:41:28 by anttran           #+#    #+#             */
/*   Updated: 2019/02/28 11:18:59 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

typedef struct			s_attr
{
	char				flags[6];
	unsigned long long	width;
	unsigned long long	prec;
	long long			sp;
	char				lms[3];
	char				conv[2];
}						t_attr;

typedef struct			s_color
{
	char				*key;
	char				*value;
}						t_color;

int						g_fd;

int						ft_printf(const char *f, ...);
int						ft_fprintf(int fd, const char *f, ...);
t_attr					set_attr(const char *f, int i);
int						di(va_list ap, const char *f, int i);
int						oux(va_list ap, const char *f, int i);
char					*oux_whash(char *s, t_attr attr, size_t l);
char					*dubz_signs(char *s, t_attr attr, long double i);
int						dubz(va_list ap, const char *f, int i);
int						csp(va_list ap, const char *f, int i);

#endif
