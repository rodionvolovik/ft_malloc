SRC		= test0.c test1.c test2.c test3.c test3a.c test4.c test5.c
OBJECT	= $(SRC:%.c=%.o)

all: $(OBJECT)
	@echo "Tests compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
