##
## EPITECH COREWAR, 2022
## base_projet
## File description:
## Makefile
##

EXT_CRI		=		*.gcno *.gcda

EXTENSION	=		.c

SRCT		=		tests/tests_project.c	\
					$(addsuffix .c, $(addprefix src/,		\
					parsing_arg/get_adress_champion				\
					parsing_arg/get_prog_number					\
					parsing_arg/parsing_argument				\
					parsing_arg/set_random_adress_and_number	\
					parsing_champ/parsing_file					\
					mem_func/set_adress_in_memory				\
					mem_func/mem_func							\
					mem_func/mem_reading						\
					mnemonic_func/one_five						\
					op))	\


SRC			=		$(addsuffix .c, $(addprefix src/,			\
					parsing_arg/get_adress_champion				\
					parsing_arg/get_prog_number					\
					parsing_arg/parsing_argument				\
					parsing_arg/set_random_adress_and_number	\
					parsing_champ/parsing_file					\
					mem_func/set_adress_in_memory				\
					mem_func/mem_func							\
					mem_func/mem_reading						\
					mnemonic_func/one_five						\
					mnemonic_func/six_ten						\
					mnemonic_func/eleven_sixteen				\
					op											\
					main))										\


OBJ			=		$(SRC:$(EXTENSION)=.o)

OBJT		=		$(SRCT:$(EXTENSION)=.o)

CPPFLAGS	=		-Wall -Wextra

CFLAGS		=		-I./includes

LDFLAGS		=		-L ./lib/my -lmy

TEST_FLAG	=		-lcriterion --coverage

CC			=		gcc

MKU			=		mkdir $(NAME_DIR)

MV			=		mv

NAME		=		corewar

NAME_CRI	=		units_tests

NAME_DIR	=		unwanted

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
	@echo -e "\e[92;5m----- COREWAR START -----\e[0m"

clean:
	$(RM) $(OBJ)
	@echo -e "\e[35m----- COREWAR CLEANED -----\033[0m"

fclean: clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME)
	$(RM) $(NAME_CRI)
	$(RM) -r $(NAME_DIR)
	$(RM) $(OBJT)
	$(RM) $(EXT_CRI)

re:		fclean all

units_tests:	fclean $(OBJT)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME_CRI) $(SRCT) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TEST_FLAG) -L./lib/my -lmy
	$(MKU)
	$(MV) *.gcno $(NAME_DIR)

tests_run:		units_tests
	./$(NAME_CRI)
	$(MV) *.gcda $(NAME_DIR)

debug: CFLAGS += -g3
debug: re

asan: CFLAGS += -fsanitize=address
asan: re

.PHONY: all re clean fclean units_tests tests_run debug
