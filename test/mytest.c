#include <stdio.h>
#include <ft_malloc.h>

int main(void)
{
    const size_t size_TINY = 5;
    const size_t size_SMALL = 300;
    const size_t size_LARGE = 8192;
    char *ptr;

    printf("Alloc\n");
    ptr = (char*)malloc(size_TINY * sizeof(char));
    printf("Stop alloc\n");

    for (int i = 0; i < size_TINY; i++)
    {
        ptr[i] = 65 + i;
    }
    printf("Length: %zu\n", strlen(ptr));

    int *int_TINY = (int*)malloc(size_TINY);
    int *int_TINY1 = (int*)malloc(size_TINY);
    int *int_TINY3 = (int*)malloc(size_TINY);
    int *int_TINY2 = (int*)malloc(size_TINY);

    int *int_SMALL = (int*)malloc(size_SMALL);
    int *int_SMALL1 = (int*)malloc(size_SMALL);
    int *int_SMALL2 = (int*)malloc(size_SMALL);
    int *int_SMALL3 = (int*)malloc(size_SMALL);

    int *int_LARGE3 = (int*)malloc(size_LARGE);
    int *int_LARGE2 = (int*)malloc(size_LARGE);

    printf("Result: %s\n", ptr);

    return 0;
}

