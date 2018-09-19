
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