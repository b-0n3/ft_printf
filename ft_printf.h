#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define  MN(X,Y) X - Y


typedef struct  s_flags{
  int           is_front_or_end;
  
  int           is_zero;
  char          format;
  int           width_arg;
  int           has_pre;
  int           precision_arg;
  int           width;
  int           precision;
}               t_flags;


typedef struct s_param{
  int s; //nb_space
  int z; //nb_zero
  int n;//is_neg
  long ns;//nb_size
  long long  tp;//nb
  size_t dd;
}               t_param;
int ft_printf(const char *str, ...);
void ft_ini_para_hex(t_param *par,va_list op,t_flags **fl);
char *ft_base(size_t nb,char *base);
int nb_size(size_t nb);
char    *ft_strrev(char *str);
void ft_fill_hex(t_param **par, t_flags *fl);
void ft_set(t_param **par, int s , int z);
char  *ft_print_int(va_list op, t_flags **fl);
void  ft_handle_arg(va_list op, t_flags **fl);
char  *ft_print_hex2(va_list op, t_flags **fl);
char  *ft_print_hex(va_list op, t_flags **fl);
char *ft_print_p(va_list op, t_flags **fl);

#endif
