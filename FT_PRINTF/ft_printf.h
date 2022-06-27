/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:31:32 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/08/30 12:25:00 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <float.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_contains(const char *check, char c);
void	ft_removemaxfieldwidth(char *str);
void	ft_writexchar(int n, char c);
int		ft_isdigit0(int c);
int		ft_integers(int n, char *str, va_list *ap);
int		ft_intlenbase(int nb, int base);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_removefield(char *str);
int		ft_int(int nb, char *str, int min, int max);
int		ft_intlen(int nb, int max, char *str);
void	ft_putint(int nb);
char	*find_start_conversion(char *str, int *i);
int		ft_char(int c, char *str, va_list *ap);
int		ft_string(char *s, char *str, va_list *ap);
int		ft_displaystr(char *str, char *flags, int min, int max);
int		ft_unsigned(unsigned long long n, char *str, va_list *ap);
int		ft_uint(unsigned int nb, char *str, int min, int max);
void	ft_unsignedbase(unsigned int nb, char *base, int size);
int		ft_address(unsigned long long n, char *str, int min, int max);
int		ft_unsignedintlenbase(unsigned int nb, int base, int m, char *s);
int		ft_hexlower(unsigned int nb, char *str, int min, int max);
int		ft_hexupper(unsigned int nb, char *str, int min, int max);
int		ft_intwritten(int tern, int min, char *flags);
int		ft_writtenhex(int min, int tern, char *str);
int		ft_ptrint(long long int *n, int nb);
int		ft_nonvar_char(char c, char *str, va_list *ap);
void	ft_setminmaxchar(int *min, int *max, char *flags);
void	ft_va_argchar(int *m, int *a, va_list *ap, char *f);
int		ft_display_char(char c, char *flags, int min, int max);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);

#endif
