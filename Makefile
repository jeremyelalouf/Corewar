##
## EPITECH PROJECT, 2021
## tetris
## File description:
## makefile
##

NAME			=	NAME

TEST_NAME		=	TEST

ASM_PATH		=	./asm/

COREWAR_PATH	=	./corewar/

all:	$(NAME)

$(NAME):
	$(MAKE) -C $(ASM_PATH)
	$(MAKE) -C $(COREWAR_PATH)

clean:
	$(MAKE) clean -C $(ASM_PATH)
	$(MAKE) clean -C $(COREWAR_PATH)

fclean: clean
	$(MAKE) fclean -C $(ASM_PATH)
	$(MAKE) fclean -C $(COREWAR_PATH)

re:
	$(MAKE) fclean
	$(MAKE) all

$(TEST_NAME):
	$(MAKE) test -C $(ASM_PATH)
	$(MAKE) test -C $(COREWAR_PATH)

test: $(TEST_NAME)

tests_run: test
	$(MAKE) tests_run -C $(ASM_PATH)
	$(MAKE) tests_run -C $(COREWAR_PATH)

.PHONY:	all clean fclean re test tests_run
