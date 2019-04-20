#include <ft_malloc.h>

void	*ft_malloc(size_t size)
{
	if (size < 1)
	{
		return (void*)NULL;
	}
	
	
	return (void*)size;
}
