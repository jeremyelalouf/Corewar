/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** handle_champions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "my.h"
#include "corewar.h"
#include "check_functions.h"

static int call_check_function(
    int compile_filed_fd,
    char *command,
    struct instruction *instruction)
{
    char **array = my_str_to_word_array(command, " ,\t\n");
    int return_value = 0;
    int array_offset = 1;

    if (array == NULL)
        return ERR;
    if (my_char_in_str(array[0], LABEL_CHAR) == TRUE)
        array_offset += 1;
    for (int i = 0; i != sizeof(INSTRUCTION_TAB) / sizeof(*INSTRUCTION_TAB);
        ++i) {
        if (my_strcmp(array[array_offset - 1], INSTRUCTION_TAB[i].instruction)
            == 0)
            return_value = INSTRUCTION_TAB[i].function(instruction,
                array + array_offset, compile_filed_fd);
        if (return_value == ERR)
            return ERR;
    }
    return SUCC;
}

int write_champions(int compile_filed_fd, FILE *old_file_fd, int params_debute)
{
    char *line = NULL;
    size_t size = 0;
    int i = 0;
    struct toolbox toolbox = {.instructions = NULL, .labels.call = NULL,
        .labels.call_size = 0, .labels.def = NULL, .labels.def_size = 0,};

    while (getline(&line, &size, old_file_fd) != -1) {
        if (my_strlen(line) < 2)
            continue;
        toolbox.instructions = realloc(toolbox.instructions,
            (i + 1) * sizeof(struct instruction));
        if (toolbox.instructions == NULL)
            return ERR;
        call_check_function(compile_filed_fd, line,
            &toolbox.instructions[i]);
        label_handling(&toolbox, line, i);
        ++i;
    }
    write_labels(compile_filed_fd, &toolbox, params_debute);
    return SUCC;
}
