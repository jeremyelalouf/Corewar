/*
** EPITECH PROJECT, 2022
** project
** File description:
** test-project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"
#include "corewar.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(error_handling, test_error_handling_one, .init = redirect_all_std)
{
    char *av[] = {"./project", NULL};

    cr_assert_eq(error_handling(1, av), SUCC);
}
