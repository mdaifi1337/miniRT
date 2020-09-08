#include "../includes/MiniRT.h"

int	ft_check_commas(char **tab)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while(tab[i])
	{
		c = 0;
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == ',')
				c++;
			j++;
		}
		if (c > 2)
		{
			write(1, "Check number of commas..!\n", 31);
			return (-1);
		}
		i++;
	}
	return (1);
}