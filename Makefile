##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC_PREFIX=		src/

SRC_FILES=		help.c				\
				check_error_cl.c	\
				myftp.c				\
				init.c				\
				cmd.c				\
				cmd_follow.c		\
				main.c

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

NAME=			myftp

HEAD=			-Iinclude

CFLAGS=		$(HEAD) -W -Wall -Wextra -fPIC

CC=			gcc

RM=			rm -f

OBJ=			$(SRC:.c=.o)

$(NAME):	$(OBJ)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled $(NAME)"
	@$(CC) $(OBJ) -o $(NAME)

%.o:	%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(NAME)

re:		fclean all

.PHONY: re fclean clean all