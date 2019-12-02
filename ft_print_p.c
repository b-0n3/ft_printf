
#include "ft_printf.h"
char *ft_fill_ar_p(t_param par, t_flags *fl)
{
     char *to_p;
  int   i;
  int in;

  i = 0;
  to_p = (char * )malloc((par.s + par.z + par.ns + 1) * sizeof(char ));
    if (!to_p )
      return(NULL);
  if(fl->is_front_or_end == 0 )
  {
    while ((par.s)-- > 1)
      to_p[i++] = ' ';
    while ((par.z)--)
      to_p[i++]='0';
      to_p[i] = '\0';
        to_p = ft_strjoin(to_p, "0x");
    to_p = ft_strjoin(to_p, ft_base(par.dd,"0123456789abcdef"));

  }
  else 
  {
    while ((par.z)--)
      to_p[i++]='0';
    to_p[i] = '\0';
    to_p = ft_strjoin("0x",to_p);
    to_p = ft_strjoin(to_p , ft_base(par.dd,"0123456789abcdef"));
    i = ft_strlen(to_p);
     while ((par.s)-- > 1)
      to_p[i++] = ' ';
     to_p[i]= '\0';
     }
     
  return (to_p);
}

char *ft_print_p(va_list op, t_flags **fl)
{
     char *to_print;
    t_param par;

    if((*fl)->precision_arg == 1 || (*fl)->width_arg == 1)
      ft_handle_arg(op, &(*fl));
    ft_ini_para_hex(&par, op, &(*fl));
    to_print = ft_fill_ar_p(par, *fl);
    return (to_print);
}
