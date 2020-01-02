/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:27:58 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 15:17:21 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags{
	int			is_front_or_end; is there - 
	int			is_zero; is there  0
	char		format; 
	int			wi_arg; is there  *
	int			has_pre; is there .
	int			prec_arg; is there *
	int			wi; width
	int			prec; precesion
	int			is_m; is * value on precesion negative
}				t_flags;

typedef struct	s_param{
	int			s; n of ' '
	int			z; n o '0'
	int			n; is negative
	long		ns; number size
	long long	tp; number
	size_t		dd; number 
}				t_param;

typedef struct	s_string{
	int			s;
	int			z;
	long		ns;
	char		*tp;
}				t_string;

int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strdup(const char *s);
char			*ft_itoa(long n);
int				ft_isdigit(int c);
int				ft_atoi(char **str);
int				ft_printf(const char *str, ...);
char			*ft_fill_zer(t_flags *fl);
void			ft_handle_zero(char **str, t_flags **fl);
void			ft_handle_minus(char **str, t_flags **fl);
char			*ft_fill_zero2(t_param par);
char			*ft_fill_h2(t_param par);
char			*ft_fill_zero(t_param par, t_flags *fl);
void			ft_handle_arg_string(va_list op, t_flags **fl);
void			ft_ini_para_p(t_param *par, va_list op, t_flags **fl);
char			*print_others(t_flags **fl, va_list op);
void			ft_fill_str(t_string **par, t_flags *fl);
void			ft_print_arg(t_flags **fl, va_list op, int *len);
void			ft_ini(t_string *par, va_list op, t_flags **fl);
int				ft_check_zero(char *tp, int len);
t_flags			*ft_int_fla(void);
char			*ft_fill_str_ha(t_string par, t_flags *fl);
char			*ft_print_pr(va_list op, t_flags **fl);
void			ft_ini_para_hex(t_param *par, va_list op, t_flags **fl);
int				my_strchr_me(char *str, char c, char *set);
char			*ft_base(size_t nb, char *base);
int				nb_size(size_t nb);
char			*ft_strrev(char *str);
void			ft_fill_hex(t_param **par, t_flags *fl);
void			ft_set(t_param **par, int s, int z);
char			*ft_print_int(va_list op, t_flags **fl);
void			ft_handle_arg(va_list op, t_flags **fl);
char			*ft_print_hex2(va_list op, t_flags **fl);
char			*ft_print_hex(va_list op, t_flags **fl);
char			*ft_print_p(va_list op, t_flags **fl);
void			ft_fill(t_param **par, t_flags *fl);
int				check_neg(long long *tp);
int				ft_nb_size(long nb, int is_neg);
char			*ft_fill_ar(t_param par, t_flags *fl);
char			*ft_print_un(va_list op, t_flags **fl);
char			*ft_print_char(va_list op, t_flags **fl);
char			*ft_print_string(va_list op, t_flags **fl);
int				my_strchr_me(char *str, char c, char *set);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);

#endif
