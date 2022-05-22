/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** handle_champions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#include "my.h"
#include "corewar.h"
#include "check_functions.h"

static int call_check_function(
    int compile_filed_fd,
    char *command,
    struct instruction *instruction)
{
    char **array = my_str_to_word_array(command, " ,\t\n");
    int array_offset = 1;

    if (array == NULL)
        return ERR;
    if (my_char_in_str(array[0], LABEL_CHAR) == TRUE)
        array_offset += 1;
    for (int i = 0; i != sizeof(INSTRUCTION_TAB) / sizeof(*INSTRUCTION_TAB);
        ++i) {
        if (my_strcmp(array[array_offset - 1], INSTRUCTION_TAB[i].instruction)
            == 0)
            return INSTRUCTION_TAB[i].function(instruction,
                array + array_offset, compile_filed_fd);
    }
    return ERR;
}

static int write_champions_loop(struct toolbox *toolbox, int compile_filed_fd,
    FILE *old_file_fd, char *solo_label)
{
    char *line = NULL;
    size_t size = 0;
    int i = 0;
    int pos = 0;

    while (getline(&line, &size, old_file_fd) != -1) {
        if (unusable_line(line) == TRUE ||
            there_is_solo_label(line, &solo_label) == TRUE)
            continue;
        toolbox->instructions = realloc(toolbox->instructions,
            (i + 1) * sizeof(struct instruction));
        if (toolbox->instructions == NULL)
            return ERR;
        if (call_check_function(compile_filed_fd, line,
            &toolbox->instructions[i]) == ERR)
            return ERR;
        label_handling(toolbox, line, i, &pos, &solo_label);
        ++i;
    }
    return i;
}

static void write_prog_size(int compile_filed_fd, struct toolbox *toolbox,
    int nbr_instruction)
{
    int prog_size = 0;

    for (int i = 0; i != nbr_instruction; ++i) {
        for (int count = 0; count != get_parameters_size(
            &toolbox->instructions[i]); ++count) {
                prog_size += toolbox->instructions[i].params[count].size;
        }
        prog_size += 2;
        if (has_coding_byte(toolbox->instructions[i].instruction) == 0)
            --prog_size;
    }
    my_bswap(&prog_size, sizeof(uint8_t));
    lseek(compile_filed_fd, offsetof(header_t, prog_size) +
        sizeof(int) - sizeof(uint8_t), SEEK_SET);
    write(compile_filed_fd, &prog_size, sizeof(uint8_t));
}

int write_champions(int compile_filed_fd, FILE *old_file_fd, int params_debute)
{
    int return_value = 0;
    char *solo_label = NULL;
    struct toolbox toolbox = {.instructions = NULL, .labels.call = NULL,
        .labels.call_size = 0, .labels.def = NULL, .labels.def_size = 0};

    return_value = write_champions_loop(&toolbox, compile_filed_fd,
        old_file_fd, solo_label);
    if (return_value == ERR)
        return ERR;
    if (write_labels(compile_filed_fd, &toolbox, params_debute) == ERR)
        return ERR;
    write_prog_size(compile_filed_fd, &toolbox, return_value);
    return SUCC;
}
