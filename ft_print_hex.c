
#include "ft_printf.h"
char    *ft_strrev(char *str)
{
    int        length;
    int        j;
    int        i;
    char    temp;

    length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    i = 0;
    j = length - 1;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return (str);
}

int nb_size(size_t nb)
{
  int size;
  
  size = 0;
  if (nb == 0)
    return (1);
  while (nb > 0)
  {
    size++;
    nb /= 16;
  }
  return (size);
}

char *ft_base(size_t nb, char *base)
{
  char   *to;
  int i;
  
  i = 0;
  
  to = (char *)malloc((nb_size(nb) + 1) * sizeof(char));
  if (nb == 0)
  to [i++] = '0';
  while(nb > 10)
  {
    to[i++] = base[nb % 16];
    nb /= 16;
  }
  if(nb < 10 && nb > 0)
    to[i++] = base[nb];
  to[i] = '\0';
  to = ft_strrev(to);
  return (to);
}






void ft_fill_hex(t_param **par, t_flags *fl)
{
    if(fl->is_zero == 1)
    ft_set(&(*par),0, (fl->width -(*par)->ns));
    else if (fl->width > (*par)->ns && fl->precision == (*par)->ns )
    ft_set(&(*par),(fl->width - (*par)->ns) , 0);
     else if (fl->width > fl->precision && fl->precision > (*par)->ns )
    ft_set(&(*par), (fl->width - fl->precision) -1, (fl->precision - (*par)->ns) + 1);
    else if(fl->width >= (fl->precision + 1) && fl->precision >= (*par)->ns )
    ft_set(&(*par), (fl->width - fl->precision) , fl->precision - 1 );
    else if(fl->width > fl->precision && fl->precision >= (*par)->ns)
    ft_set(&(*par), (fl->width - fl->precision) , (fl->precision - (*par)->ns));
    else if(fl->width >= (fl->precision + 1) && fl->precision >= (*par)->ns)
    ft_set(&(*par), (fl->width - fl->precision) + 1 , (fl->precision - (*par)->ns));
     else if (fl->width < (*par)->ns && fl->precision > (*par)->ns)
    ft_set(&(*par),0 , (fl->precision - (*par)->ns) + 1);
     else if (fl->width < fl->precision && fl->precision > (*par)->ns )
    ft_set(&(*par),0 , (fl->precision - (*par)->ns) + 1);
    else if (fl->width <= fl->precision && fl->precision >= (*par)->ns )
    ft_set(&(*par),0, (fl->precision - (*par)->ns));
    else if (fl->width <= fl->precision && fl->precision <= (*par)->ns  )
    ft_set(&(*par),0, 0);
    else if (fl->width >= fl->precision && fl->precision <= (*par)->ns  )
    ft_set(&(*par),(fl->width -(*par)->ns) , 0);
     else if (fl->width > (*par)->ns)
    ft_set(&(*par),(fl->width - fl->precision) - 1, fl->precision);
    

}
void ft_ini_para_hex(t_param *par,va_list op,t_flags **fl)
{
    (*par).z = 0;
    (*par).s = 0;
    (*par).dd = va_arg(op, size_t);
    (*par).n = 0;
    (*par).ns = nb_size((*par).dd) + 1;
        ft_fill_hex(&(par),*fl);
}

char *ft_fill_ar_hex(t_param par, t_flags *fl)
{
  char *to_p;
  int   i;
  int in;

  i = 0;
  if(fl->precision <= 0  && par.dd == 0 && fl->width == 0 && fl->has_pre == 1)
      return (ft_strdup(""));
  to_p = (char * )malloc((par.s + par.z + par.ns + 1) * sizeof(char ));
    if (!to_p )
      return(NULL);
  if(fl->is_front_or_end == 0 )
  {
    while ((par.s)-- )
      to_p[i++] = ' ';
    while ((par.z)--)
      to_p[i++]='0';
      to_p[i] = '\0';
    to_p = ft_strjoin(to_p, ft_base(par.dd,"0123456789abcdef"));

  }
  else 
  {
    while ((par.z)--)
      to_p[i++]='0';
    to_p[i] = '\0';
    to_p = ft_strjoin(to_p , ft_base(par.dd,"0123456789abcdef"));
    i = ft_strlen(to_p);
     while ((par.s)-- )
      to_p[i++] = ' ';
     to_p[i]= '\0';
     }
     
  return (to_p);
}
char *ft_fill_ar_hex2(t_param par, t_flags *fl)
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
    while ((par.s)--)
      to_p[i++] = ' ';
    while ((par.z)--)
      to_p[i++]='0';
      to_p[i] = '\0';
    to_p = ft_strjoin(to_p, ft_base(par.dd,"0123456789ABCDEF"));

  }
  else 
  {
    while ((par.z)--)
      to_p[i++]='0';
    to_p[i] = '\0';
    to_p = ft_strjoin(to_p , ft_base(par.dd,"0123456789ABCDEF"));
    i = ft_strlen(to_p);
     while ((par.s)--)
      to_p[i++] = ' ';
     to_p[i]= '\0';
     }
     
  return (to_p);
}
char  *ft_print_hex(va_list op, t_flags **fl)
{
    char *to_print;
    t_param par;

    if((*fl)->precision_arg == 1 || (*fl)->width_arg == 1)
      ft_handle_arg(op, &(*fl));
    ft_ini_para_hex(&par, op, &(*fl));
    to_print = ft_fill_ar_hex(par, *fl);
    return (to_print);
}

char  *ft_print_hex2(va_list op, t_flags **fl)
{
    char *to_print;
    t_param par;

    if((*fl)->precision_arg == 1 || (*fl)->width_arg == 1)
      ft_handle_arg(op, &(*fl));
    ft_ini_para_hex(&par, op, &(*fl));
    to_print = ft_fill_ar_hex2(par, *fl);
    return (to_print);
}