#include "ft_printf.h"

void  ft_handle_arg(va_list op, t_flags **fl)
{
  long arg;

  if((*fl)->width_arg != 0)
  {
    arg = va_arg(op, int);
    if(arg < 0)
    {
        (*fl)->is_front_or_end = 1;
        arg *= -1;
    }
    (*fl)->width = (int) arg;
  }
  if((*fl)->precision_arg != 0)
  {
    arg = va_arg(op, int);
    if(arg < 0)
        {
          (*fl)->precision = 0;
          return ;
        }
    (*fl)->precision = (int)arg;
  }

}
int ft_nb_size(long nb, int is_neg)
{
    int size;
    long bc;

    bc = nb;
    size = 0;

    if(is_neg == 1 || bc == 0)
        size++;
     while (bc > 0)
    {
      bc /= 10;
      size++;
    }
    return (size);
}

int check_neg(long long *tp)
{
    if(*tp < 0)
    {
        *tp *= -1;
        return (1);
    }
    return (0);
}
void ft_set(t_param **par, int s , int z)
{
    (**par).s = (s > 0 ? s : 0);
    (**par).z = (z > 0 ? z : 0);
}
void ft_fill(t_param **par, t_flags *fl)
{
    if(fl->is_zero == 1 && fl->is_front_or_end == 0)
    ft_set(&(*par),0, (fl->width -(*par)->ns));
    else if (fl->width > (*par)->ns && fl->precision == (*par)->ns && (*par)->tp !=0)
    ft_set(&(*par),(fl->width - (*par)->ns) , 0);
     else if (fl->width > fl->precision && fl->precision > (*par)->ns && (*par)->n == 1)
    ft_set(&(*par), (fl->width - fl->precision) -1, (fl->precision - (*par)->ns) + 1);
    else if(fl->width >= (fl->precision + 1) && fl->precision >= (*par)->ns && (*par)->tp ==0)
    ft_set(&(*par), (fl->width - fl->precision) , fl->precision - 1 );
    else if(fl->width > fl->precision && fl->precision >= (*par)->ns)
    ft_set(&(*par), (fl->width - fl->precision) , (fl->precision - (*par)->ns));
    else if(fl->width >= (fl->precision + 1) && fl->precision >= (*par)->ns)
    ft_set(&(*par), (fl->width - fl->precision) + 1 , (fl->precision - (*par)->ns));
     else if (fl->width < (*par)->ns && fl->precision > (*par)->ns && (*par)->n == 1)
    ft_set(&(*par),0 , (fl->precision - (*par)->ns) + 1);
     else if (fl->width < fl->precision && fl->precision > (*par)->ns && (*par)->n == 1)
    ft_set(&(*par),0 , (fl->precision - (*par)->ns) + 1);
    else if (fl->width <= fl->precision && fl->precision >= (*par)->ns )
    ft_set(&(*par),0, (fl->precision - (*par)->ns));
    else if (fl->width <= fl->precision && fl->precision <= (*par)->ns  )
    ft_set(&(*par),0, 0);
    else if (fl->width >= fl->precision && fl->precision <= (*par)->ns  )
    ft_set(&(*par),(fl->width -(*par)->ns) , 0);
     
     else if (fl->width > (*par)->ns && (*par)->tp ==0)
    ft_set(&(*par),(fl->width - fl->precision) - 1, fl->precision);
    

}
void ft_ini_para(t_param *par,va_list op,t_flags **fl)
{
   (*par).dd = 0;
    (*par).z = 0;
    (*par).s = 0;
    (*par).tp = va_arg(op,int);
    (*par).n = check_neg(&((*par).tp));
    (*par).ns = ft_nb_size((*par).tp, (*par).n);
        ft_fill(&(par),*fl);
}
char *ft_fill_ar(t_param par, t_flags *fl)
{
  char *to_p;
  int   i;
  int in;

  i = 0;
  if(fl->precision <= 0  && par.tp == 0 && fl->width == 0 && fl->has_pre == 1)
      return (ft_strdup(""));
  to_p = (char * )malloc((par.s + par.z + par.ns + 1) * sizeof(char ));
    if (!to_p )
      return(NULL);
  if(fl->is_front_or_end == 0 )
  {
    while ((par.s)--)
      to_p[i++] = ' ';
    if(par.n)
      to_p[i++] = '-';
    while ((par.z)--)
      to_p[i++]='0';
      to_p[i] = '\0';
    if(fl->precision <= 0 && par.tp ==0 && fl->width > 0 && fl->has_pre != 0)
   {
          to_p = ft_strjoin(to_p , " ");
          return (to_p);
    }
    to_p = ft_strjoin(to_p, ft_itoa(par.tp));

  }
  else 
  {
    if(par.n)
      to_p[i++] = '-';
    while ((par.z)--)
      to_p[i++]='0';
    to_p[i] = '\0';
    to_p = ft_strjoin(to_p , ft_itoa(par.tp));
    i = ft_strlen(to_p);
     while ((par.s)--)
      to_p[i++] = ' ';
     to_p[i]= '\0';
     }
     
  return (to_p);
}
char  *ft_print_int(va_list op, t_flags **fl)
{
    char *to_print;
    t_param par;
   
    if((*fl)->precision_arg == 1 || (*fl)->width_arg == 1)
      ft_handle_arg(op, &(*fl));
      
    ft_ini_para(&par, op, &(*fl));
    to_print = ft_fill_ar(par, *fl);
    return (to_print);
}