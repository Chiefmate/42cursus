/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:51:24 by hyunhole          #+#    #+#             */
/*   Updated: 2021/11/20 15:51:24 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strchr(const char *s, int c)
{
    char    *ret;
    int     idx;

    ret = (void *)0;
    idx = 0;
    while (s[idx])
    {
        if (s[idx] == c)
        {
            ret = (char *)s + idx;
            break;
        }
        idx++;
    }
    return (ret);
}

//  ft_strlen() 사용
char    *ft_strrchr(const char *s, int c)
{
    char    *ret;
    int     idx;

    ret = (void *)0;
    idx = ft_strlen(s);
    while (idx >= 0)
    {
        if (s[idx] == c)
        {
            ret = (char *)s + idx;
            break;
        }
        idx--;
    }
    return (ret);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int     ret;
    size_t  idx;

    idx = 0;
    while (idx < n && s1[idx] && s1[idx] != s2[idx])
        idx++;
    ret = s1[idx] - s2[idx];
    return (ret);
}

//ft_strlen() 사용

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    char    *ret;
    size_t  idx;
    size_t  temp;

    if (*little == '\0')
        return (big);
    ret = (void *)0;
    idx = 0;
    while (idx < len)
    {
        temp = 0;
        while (big[temp] == little[temp])
            temp++;
        if (temp && little[temp] == '\0')
        {
            ret = big + 1 - temp;
            break;
        }
        idx++;
    }
    return (ret);
}

//  ft_isdigit() 사용
int ft_atoi(const char *s)
{
    int         n;
    int         neg_sign;

    n = 0;
    neg_sign = 0;
    while (*s == ' ' || *s == '\f' || *s == '\n' || \
    *s == '\r' || *s == '\t' || *s == '\v')
        s++;
    switch (*s)
    {
        case '-':
            neg_sign = 1;
        case '+':
            s++;
    }
    while (ft_isdigit(*s))
        n = 10 * n - (*s++ - '0');
    if (neg_sign)
        return (n);
    return (-n);
}