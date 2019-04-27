#include <stdio.h>
#include <ft_malloc.h>

int main(void)
{
    const size_t size_TINY = 5;
    const size_t size_SMALL = 300;
    const size_t size_LARGE = 8192;
    char *ptr;

    // printf("Alloc\n");
    ptr = (char*)malloc((size_TINY + 1) * sizeof(char));

    int i;
    for (i = 0; i < size_TINY; i++)
    {
        ptr[i] = 65 + i;
    }
    ptr[size_TINY] = 0;
    // printf("Length: %zu\n", strlen(ptr));

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

    // printf("Result: %s\n", ptr);

    // free(int_LARGE2);
    // free(int_LARGE3);
    // free(int_SMALL);
    // free(int_SMALL3);
    // free(ptr);

    return 0;
}

// test0.c
// int main()
// {
//     int i; char *addr;

// i = 0;
// while (i < 1024)
// {
//     i++;
// }
// return (0);
// }


// test1
// int main()
// {
//     int i;
// char *addr;

// i = 0;
// while (i < 1024)
// {
//     addr = (char*)malloc(1024);
// addr[0] = 42;
// i++;
// }
// return (0);
// }


// test1_free
// int main()
// {
//     int i;
// char *addr;

// i = 0;
// while (i < 1024)
// {
//     addr = (char*)malloc(1024);
// addr[0] = 42;
// free(addr);
// i++;
// }
// return (0);
// }


// test3 realloc
// #define M (1024 * 1024)
// void print(char *s) 
// {
//     write(1, s, strlen(s));
// }

// int main()
// {
//     char *addr1;
// char *addr3;

// addr1 = (char*)malloc(16*M);
// strcpy(addr1, "Bonjour\n");
// print(addr1);
// addr3 = (char*)realloc(addr1, 128*M);
// addr3[127*M] = 42;
// print(addr3);
// return (0);
// }

// test3a realloc
// #define M (1024 * 1024)
// void print(char *s) 
// {
//     write(1, s, strlen(s));
// }
// int main()
// {
//     char *addr1;
// char *addr2;
// char *addr3;

// addr1 = (char*)malloc(16*M);
// strcpy(addr1, "Bonjour\n");
// print(addr1);
// addr2 = (char*)malloc(16*M);
// addr3 = (char*)realloc(addr1, 128*M);
// addr3[127*M] = 42; print(addr3);
// return (0);
// }
