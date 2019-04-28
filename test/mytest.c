#include <stdio.h>
#include <ft_malloc.h>
#include <string.h>
# include <stdlib.h>
#include <unistd.h>

// int main(void)
// {
//     ft_putstr("Alloc\n");
//     const size_t size_TINY = 5;
//     const size_t size_to_end = 4027;
//     const size_t size_SMALL = 4096;
//     const size_t size_LARGE = 8192;
//     char *ptr;

//     ptr = (char*)malloc(size_TINY * sizeof(char));
//     ptr = (char*)malloc(size_to_end);
//     // printf("Stop alloc\n");

//     for (int i = 0; i < size_TINY; i++)
//     {
//         ptr[i] = 65 + i;
//     }
//     ptr[size_TINY] = '\0';
//     // printf("Length: %zu\n", strlen(ptr));

//     int *int_TINY = (int*)malloc(3700);
//     int *int_TINY0 = (int*)malloc(100);
//     int *int_TINY1 = (int*)malloc(size_TINY);
//     int *int_TINY3 = (int*)malloc(size_TINY);
//     int *int_TINY2 = (int*)malloc(size_TINY);

//     int *int_SMALL = (int*)malloc(size_SMALL);
//     int *int_SMALL1 = (int*)malloc(size_SMALL);
//     int *int_SMALL2 = (int*)malloc(size_SMALL);
//     int *int_SMALL3 = (int*)malloc(size_SMALL);

//     int *int_LARGE3 = (int*)malloc(size_LARGE);
//     int *int_LARGE2 = (int*)malloc(size_LARGE);

//     int *ptr1 = (int*)malloc(getpagesize() * 17);
//     int *ptr2 = (int*)malloc(getpagesize() * 17);

//     // printf("Result: %s\n", ptr);

//     ft_putstr("Alloc end\n");
//     return 0;
// }


//////////// test 0
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


////////////// test1
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

// show_alloc_mem();
// return (0);
// }


//////////////// test2
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
// int *ptr1 = (int*)malloc(getpagesize() * 17);
// free(ptr1);
// // show_alloc_mem();
// return (0);
// }



//////////////// test3
// #define M (1024 * 1024)

// // void print(char *s) 
// // {
// //     write(1, s, strlen(s));
// // }
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
// show_alloc_mem();
// return (0);
// }



/////////////// test3a
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


////////////// test4
// void print(char *s)
// {
//     write(1, s, strlen(s));
// }
// int main()
// {
//     char *addr;
// addr = malloc(16);
// free(NULL);
// free((void *)addr + 5);
// if (realloc((void *)addr + 5, 10) == NULL)
// print("Bonjour\n");
// }


////////////// test5
int main()
{
    malloc(1024);
malloc(1024 * 32);
malloc(1024 * 1024);
malloc(1024 * 1024 * 16);
malloc(1024 * 1024 * 128);
show_alloc_mem();
return (0);
}