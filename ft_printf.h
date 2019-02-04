#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

extern int	g_c;
extern char	*g_nums;
extern char	*g_lms;
extern char	*g_convs;
extern char	*g_prec;
extern char	*g_all;
extern char	*g_csp;
extern char	*g_f;
extern char	*g_di;
extern char	*g_ox;
extern char	*g_oux;
extern char	*g_dioux;
extern char	*g_flags0;
extern char	*g_0;
extern char	*g_uf;
extern char	*g_cp;

typedef struct			s_attr
{
	char				flags[6];
	unsigned long long	width;
	unsigned long long	prec;
	char				lms[3];
	char				conv[2];
}						t_attr;

int						ft_printf(const char *f, ...);
int						set_attr(const char *f, t_attr *attr, int i);
int						di(va_list ap, t_attr *attr);
int						oux(va_list ap, t_attr *attr);

#endif
