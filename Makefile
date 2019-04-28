ifeq ($(HOSTTYPE),)
    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

# Compile variables
CC              = gcc
CFLAGS          = -Wall -Wextra -Werror -Wno-unused -Wno-unused-command-line-argument

# Target variables
LIB_MALLOC_LINK = libft_malloc.so
LIB_MALLOC 		= libft_malloc_$(HOSTTYPE).so

# Libft variables
LIBFT_PATH      = lib/libft
LIBFT           = $(LIBFT_PATH)/libft.a
LIBFT_INCLUDE	= -I./$(LIBFT_PATH)/includes
LIBFT_FLAGS		= -L./$(LIBFT)

# Source files varibles
SRC_PATH        = src
SRC             = $(addprefix $(SRC_PATH)/, free.c malloc.c realloc.c show_alloc_mem.c)

# Object files variables
OBJECT_PATH		= obj
OBJECT			= $(SRC:$(SRC_PATH)/%.c=$(OBJECT_PATH)/%.o)

# Include variables
INCLUDE_PATH	= include
INCLUDE         = ft_malloc.h
INCLUDE_FLAGS   = -I./$(INCLUDE_PATH)

all: $(LIBFT) $(LIB_MALLOC_LINK)

$(LIB_MALLOC_LINK): $(LIB_MALLOC)
	@echo  "\x1b[01;32m[Libft_malloc link created]\x1b[0m"
	@ln -s $^ $@

$(LIB_MALLOC): $(OBJECT)
	@echo  "\x1b[01;32m[Libft_malloc compiled]\x1b[0m"
	@$(CC) -shared $^ -o $@ $(LIBFT) -lpthread

$(OBJECT): | $(OBJECT_PATH)

$(OBJECT_PATH):
	@mkdir -p $(OBJECT_PATH)

$(OBJECT_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@$(CC) -fPIC $(CFLAGS) -c $< -o $@ $(INCLUDE_FLAGS) $(LIBFT_INCLUDE) $(LIBFT_FLAGS) -lpthread

$(LIBFT) :
	@make -C $(LIBFT_PATH)

clean :
	@rm -f $(OBJECT)
	@rm -rf $(LIB_MALLOC_LINK)
	@make clean -C $(LIBFT_PATH)

fclean :
	@rm -f $(LIB_MALLOC_LINK)
	@rm -f $(LIB_MALLOC)
	@rm -rf $(OBJECT_PATH)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[01;31m[Libraries deleted]\x1b[0m"
	@echo "\033[01;31m[Temporary folders deleted]\x1b[0m"

re : fclean all

.PHONY: clean fclean re
