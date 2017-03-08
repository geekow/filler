#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		i;
	int		j;
	int		z;
	char	*str[99];

	i = 1;
	j = 0;
	while (i)
		i = get_next_line(1, &str[i - 1]);
	j = open("./test.log", O_RDWR);
	z = i;
	while (i) {
		ft_putendl_fd(str[z - i--], j);
	}
	return (0);
}
