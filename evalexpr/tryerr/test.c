#include <stdlib.h>

#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

int	my_strlen(char *str)
{
    int	i;
    
    i = 0;
    while (str[i])
        ++i;
    return (i);
}

void	ft_putnbr(int nbr)
{
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
    }
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    else
        ft_putchar(nbr + '0');
}

int     operator(int lhs, int rhs, char op)
{
    if (op == '+')
        return (lhs + rhs);
    else if (op == '-')
        return (lhs - rhs);
    else if (op == '*')
        return (lhs * rhs);
    else if (op == '/')
        return (lhs / rhs);
    else if (op == '%')
        return (lhs % rhs);
    else
        return (0);
}


char	*suppr_spaces(char *str)
{
    int	i;
    int	j;
    char	*str2;
    
    i = 0;
    j = 0;
    str2 = malloc(my_strlen(str) + 1);
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            str2[j] = str[i];
            j = j + 1;
        }
        i = i + 1;
    }
    str2[j] = '\0';
    return (str2);
}

int	parse_num(char **ps)
{
    int   nbr;
    int   signe;
    
    nbr = 0;
    signe = 1;
    if ((*ps)[0] == '+' || (*ps)[0] == '-')
    {
        if ((*ps)[0] == '-')
            signe = -1;
        *ps = *ps + 1;
    }
    if ((*ps)[0] == '(')
    {
        *ps = *ps + 1;
        nbr = eval_expr_0(ps);
        if ((*ps)[0] == ')')
            *ps = *ps + 1;
        return (signe * nbr);
    }
    while('0' <= (*ps)[0] && (*ps)[0] <= '9')
    {
        nbr = (nbr * 10) + (*ps)[0] - '0';
        *ps = *ps + 1;
    }
    return (signe * nbr);
}

int	eval_expr_0(char **ps)
{
    int	lhs;
    int	rhs;
    char	op;
    
    lhs = parse_num(ps);
    while ((*ps)[0] != '\0' && (*ps)[0] != ')')
    {
        op = (*ps)[0];
        *ps = *ps + 1;
        if (op == '+' || op == '-')
            rhs = eval_expr_1(ps);
        else
            rhs = parse_num(ps);
        lhs = operator(lhs, rhs, op);
    }
    return (lhs);
}

int	eval_expr_1(char **ps) //Precedence
{
    int	lhs;
    int	rhs;
    char	op;
    
    lhs = parse_num(ps);
    while ((*ps)[0] == '*' || (*ps)[0] == '/' || (*ps)[0] == '%')
    {
        op = (*ps)[0];
        *ps = *ps + 1;
        rhs = parse_num(ps);
        lhs = operator(lhs, rhs, op);
    }
    return (lhs);
}

int	eval_expr(char *str)
{
    str = suppr_spaces(str);
    if (str[0] == '\0')
        return (0);
    return (eval_expr_0(&str));
}

int	main(int ac, char **av)
{
    if (ac > 1)
    {
        ft_putnbr(eval_expr(av[1]));
        ft_putchar('\n');
    }
    return (0);
}