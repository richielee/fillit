#include "../includes/fillit.h"

char	**str_truncate(char *str)
{
	int		n;
	int		block;
	char	**arr;
	int		i;

	i = 0;
	n = ft_strlen(str);
	block = (n + 1) / 21;
	if (!(arr = (char**)malloc(sizeof(char*) * (block + 1))))
		return (NULL);
	while (i < block)
	{
		if (!(arr[i] = (char*)malloc(sizeof(char*) * 21)))
			return (NULL);
		ft_strncpy(arr[i], str + (21 * i), 20);
		arr[i][20] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}
