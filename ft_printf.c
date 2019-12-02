
#include "ft_printf.h"

t_flags  *ft_int_fla()
{
  t_flags *fl;
fl  = (t_flags *) malloc(sizeof(t_flags ));

  fl->is_front_or_end = 0;
  fl->is_zero = 0;
  fl->format = 'z';
  fl->width_arg = 0;
  fl->has_pre = 0;
  fl->precision_arg = 0;
  fl->width = 0;
  fl->precision = -1;
  return(fl);
}

void ft_print_arg(t_flags **fl, va_list op, int *len)
{
  char *to_print;
  
  to_print = NULL;
  //to_print = ft_strdup("");
  if((*fl)->format == 'i' || (*fl)->format == 'd')
     to_print =  ft_print_int( op, &(*fl));

  /*else if(fl->format == 'c')

  else if(fl->format == 's')
*/
  else if((*fl)->format == 'p')
  to_print = ft_print_p( op, &(*fl));
/* 
  else if(fl->format == 'u')
*/
  else if((*fl)->format == 'x')
      to_print =  ft_print_hex( op, &(*fl));
  else if((*fl)->format == 'X')
 to_print =  ft_print_hex2( op, &(*fl));
  /* else if(fl->format == '%')*/
  if(!to_print)
  {
    *len = -1;
    return;
  }
  else
  {
  *len += ft_strlen(to_print);
  ft_putstr_fd(to_print, 1);
  free(to_print);
  }
}

int   my_strchr(char *str, char c,char *set)
{
//  printf("search 21\n");
  while (ft_strchr(set, *str) == NULL)
  {
    //printf("search 23\n");
      if(*str == c)
        return (1);
      str += 1;
  }
//  printf("search 42\n");
  return(0);
}

void ft_handle_minus(char **str, t_flags **fl)
{
  while (**str == '-')
  *str += 1;
    (*fl)->is_front_or_end = 1;
  //printf("fdsfsdf \n ");
}

void ft_handle_zero(char **str, t_flags **fl)
{
  while (**str == '0')
      *str += 1;
    (*fl)->is_zero = 1;
}

void ft_handle_point(char **str, t_flags **fl)
{
    if(**str == '*')
    {
      *str += 2;
      if(**str == '*'|| ft_isdigit(**str))
      {
        if(ft_isdigit(**str))
        {
            (*fl)->precision = ft_atoi(&(*str));
            *str += 1;
        }
        else
          (*fl)->precision_arg = 1;
        *str += 1;
      }
      (*fl)->width_arg = 1;
    }
    else if(**str == '.')
    {
        *str += 1;
      if(**str == '*')
      {
        *str += 1;
        (*fl)->precision_arg = 1;
      }
      else if (ft_isdigit(**str))
          (*fl)->precision = ft_atoi(&(*str));
    }
}

/*void ft_handle_width_num(char **str, t_flags *fl)
{

}*/
int ft_check_flag(char **str, va_list op , int *len)
{
  t_flags *fl;
  char set[] = "cspdiuxX%";

  fl = ft_int_fla();
  *str += 1;
  if (**str == '-')
  ft_handle_minus(&(*str), &fl);
  else if (**str == '0')
    ft_handle_zero(&(*str), &fl);
  if((my_strchr(*str,'.',set) == 1 ))
  {
    fl->has_pre = 1;
    if(ft_isdigit(**str) == 1)
      fl->width = ft_atoi(&(*str));
    ft_handle_point(&(*str), &fl);
  }
  if(ft_isdigit(**str) == 1)
    fl->width = ft_atoi(&(*str));
  if(**str == '*')
  {
    fl->width_arg = 1;
    *str += 1;
  }
  if(ft_strchr(set ,**str) != 0 && **str != '\0')
  {
     fl->format = **str;
    *str += 1;
    ft_print_arg(&fl, op, &(*len));
  //printf("%d\n%d\n%c\n%d\n%d\n%d\n%d\n safi tsalat\n",fl->is_front_or_end,fl->is_zero,  fl->format,  fl->width_arg ,  fl->precision_arg ,  fl->width ,  fl->precision);


  }
  //printf("%d\n%d\n%c\n%d\n%d\n%d\n%d\n safi tsalat\n",fl->is_front_or_end,fl->is_zero,  fl->format,  fl->width_arg ,  fl->precision_arg ,  fl->width ,  fl->precision);
 free(fl);
return (1);
}

int ft_printf(const char *str, ...)
{
  va_list op;
  int len;
  int i;
  char *stream;

  stream = (char *)str;
  i = 0;
  len = 0;
  va_start(op,str);
  while (*stream)
  {
    if(*stream == '%')
    {
      ft_check_flag(&stream, op, &len);
      continue;
    }

    write(1,stream,1);

    stream++;
    len++;
  }
  va_end(op);
  return(len);
}

//  int main() {
//    ft_printf("%-4p&\n",(void *)100);
//    printf("%-4p&\n",(void *)100);
//   return 0;


//  }