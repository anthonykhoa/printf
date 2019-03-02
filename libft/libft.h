/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 08:16:01 by anttran           #+#    #+#             */
/*   Updated: 2019/03/01 16:34:27 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
int					ft_isdigit(int c);
void				*ft_memalloc(size_t size);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
int					hidden_c(const char *s1, const char *s2, int s, int e);
int					hidden_c2(const char *s1, const char *s2, int s, int e);
unsigned long long	ft_atoull(const char *str);
char				*ft_lltoa(long long n);
char				*ft_maxtoa(intmax_t n);
char				*ft_umaxtoa(uintmax_t n);
int					find_c(const char *str, char c);
int					strequ(const char *s1, const char *s2);
void				remove_c(char str[], char c);
char				*fill_str(uintmax_t n, char c);
char				*insert_c(char *s1, char c, unsigned long long n);
char				*rem_c(char *str, char c);
int					hidden_c3(const char *s1, const char *s2);
char				*replace_c(char *s1, char c, unsigned long long n);
char				*sub_str(char *str, char *sub, unsigned long long i);
char				*rev_str(const char *str);
char				*base16x(uintmax_t n);
char				*base16xl(uintmax_t n);
char				*base8(uintmax_t n);
char				*push_str(char *str, char *sub);
char				*potato(long double n);
long double			ft_pow(long double base, long double ex);
char				*str_chop(char *str, int n);
int					hidden_c4(const char *s1, const char *s2, int s, int e);
char				*str_chop2(char *str, int n);
char				*round_potato(long double n);
long double			potato_magic(long double n, char *first, size_t len);

#endif
