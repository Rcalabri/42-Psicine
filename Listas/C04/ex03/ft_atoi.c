/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalabri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:32:02 by rcalabri          #+#    #+#             */
/*   Updated: 2025/05/07 11:32:05 by rcalabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	return (&(str[i]));
}

char	*ft_skip_plus_or_minus(char *str, int *negative)
{
	int	i;
	int	minus_count;

	i = 0;
	minus_count = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			minus_count++;
		}
		i++;
	}
	if (minus_count % 2 == 0)
		*negative = 0;
	else
		*negative = 1;
	return (&(str[i]));
}

int	ft_atoi(char *str)
{
	int	i;
	int	negative;
	int	result;

	str = ft_skip_spaces(str);
	str = ft_skip_plus_or_minus(str, &negative);
	result = 0;
	i = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (negative == 1)
		result *= -1;
	return (result);
}

// int main(void)
// {
//     char *tests[] = {
//         "1234",
//         "   ---+--+1234ab567",
//         "0",
//         "-42",
//         "   +++--+7xyz",
//         NULL
//     };
//     for (int i = 0; tests[i]; i++)
//         printf("ft_atoi(\"%s\") = %d\n",
//                tests[i], ft_atoi(tests[i]));
//     return 0;
// }