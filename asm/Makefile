##
## EPITECH PROJECT, 2021
## tetris
## File description:
## makefile
##

MAIN		=	./src/main.c					\

SRC			=	$(addsuffix .c,					\
				$(addprefix src/,				\
				$(addprefix check_functions/,	\
				first_check_functions			\
				second_check_functions			\
				third_check_functions			\
				fourth_check_functions)			\
				$(addprefix handling_byte/,		\
				fill_size_param					\
				fill_params_array				\
				coding_byte)					\
				$(addprefix handling_file/,		\
				has_coding_byte					\
				label_handling					\
				write_label						\
				get_new_file_name				\
				handle_champions				\
				handle_header_assets			\
				handle_header)					\
				print_error						\
				error_handling					\
				error_value_params				\
				compile							\
				write_instruction))				\

SRC_TEST	=	$(addsuffix .c,					\
				$(addprefix tests/,				\
				test_project))					\

OBJ			=	$(SRC:.c=.o) $(MAIN:.c=.o)

OBJ_TEST	=	$(SRC:.c=.o) $(SRC_TEST:.c=.o)

CFLAGS		=	-Wall -Wextra

CPPFLAGS	+=	-I../includes

LDFLAGS		+=	-L../lib/my -lmy

LDFLAGS_TEST+=	--coverage -lcriterion

NAME		=	asm

TEST_NAME	=	unit_tests

LIBMY_PATH	=	../lib/my/libmy.a

LIB_PATH	=	../lib/my

all:	$(NAME)

$(LIBMY_PATH):
	$(MAKE) -C $(LIB_PATH)

$(NAME):	$(OBJ) $(LIBMY_PATH)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug_all: CFLAGS += -g3
debug_all: all

debug_re: CFLAGS += -g3
debug_re: re

clean:
	$(MAKE) clean -C $(LIB_PATH)
	$(RM) $(OBJ)
	$(RM) $(OBJ_TEST)

fclean: clean
	$(MAKE) fclean -C $(LIB_PATH)
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(TEST_NAME): $(OBJ_TEST) $(LIBMY_PATH)
	$(CC) -o $(TEST_NAME) $(OBJ_TEST) $(LDFLAGS) $(LDFLAGS_TEST)

test: $(TEST_NAME)

tests_run: test
	./$(TEST_NAME)

.PHONY:	all debug_all debug_re clean fclean re test
