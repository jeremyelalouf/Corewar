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

int sec_has_coding_byte(uint8_t instruction)
{
    if (instruction != 1 && instruction != 9 &&
    instruction != 12 && instruction != 15)
        return 1;
    return 0;
}

int get_instruction_size(struct instruction *instruction)
{
    int size = 0;
    int nbr_params = get_parameters_size(instruction);

    for (int i = 0; i != nbr_params; ++i)
        size += instruction->params[i].size;
    return size + 1 + sec_has_coding_byte(instruction->instruction);
}

int has_coding_byte(uint8_t instruction)
{
    if (instruction != 1 && instruction != 9 &&
    instruction != 12 && instruction != 15)
        return 1;
    return 0;
}

static int handle_label(
    char *command,
    struct instruction *instruction,
    struct label_referenced *labels)
{
    char **array = my_str_to_word_array(command, " ,\t\n");
    int offset = 0;

    if (array == NULL)
        return ERR;
    if (my_char_in_str(array[0], LABEL_CHAR) == TRUE) {
        labels->def = realloc(labels->def, sizeof(*labels->def) *
            (labels->def_size + 1));
        if (labels->def == NULL)
            return ERR;
        labels->def[labels->def_size].label_name = my_strdup(array[0]);
        labels->def[labels->def_size].label_name[my_strlen(array[0]) - 1] = '\0';
        labels->def[labels->def_size].label_pos = instruction->index;
        labels->def_size += 1;
        array += 1;
    }
    for (int i = 0; array[i] != NULL; ++i) {
        if (my_char_in_str(array[i], LABEL_CHAR) == TRUE) {
            labels->call = realloc(labels->call, sizeof(*labels->call) *
                (labels->call_size + 1));
            if (labels->call == NULL)
                return ERR;
            labels->call[labels->call_size].label_name = my_strdup(array[i]);
            labels->call[labels->call_size].label_index = i + has_coding_byte(instruction->instruction);
            labels->call[labels->call_size].label_pos = instruction->index;
            labels->call[labels->call_size].size_to_write = instruction->params[i - 1].size;
            labels->call_size += 1;
        }
    }
    return SUCC;
}

int label_is_good(struct label_referenced *labels, struct label *label)
{
    for (int i = 0; i != labels->def_size; ++i) {
        if (my_strstr(label->label_name, labels->def[i].label_name) != NULL) {
            return labels->def[i].label_pos;
        }
    }
    return 0;
}

int write_labels(int compile_filed_fd, struct toolbox *toolbox, int params_debute)
{
    uint64_t tmp = 0;
    int return_value = 0;

    for (int i = 0; i != toolbox->labels.call_size; ++i) {
        return_value = label_is_good(&toolbox->labels,
            &toolbox->labels.call[i]);
        if (return_value != 0) {
            if (toolbox->labels.call[i].size_to_write == 2)
                tmp = return_value - toolbox->labels.call[i].label_pos;
            my_bswap(&tmp, toolbox->labels.call[i].size_to_write);
            lseek(compile_filed_fd, params_debute +
                toolbox->labels.call[i].label_index +
                toolbox->labels.call[i].label_pos, SEEK_SET);
            write(compile_filed_fd, &tmp,
                toolbox->labels.call[i].size_to_write);
        }
    }
    return SUCC;
}

int write_champions(int compile_filed_fd, FILE *old_file_fd, int params_debute)
{
    char *line = NULL;
    size_t size = 0;
    int i = 0;
    struct toolbox toolbox = {
        .instructions = NULL,
        .labels.call = NULL,
        .labels.call_size = 0,
        .labels.def = NULL,
        .labels.def_size = 0,
    };
    int pos = 0;

    while (getline(&line, &size, old_file_fd) != -1) {
        if (my_strlen(line) < 2)
            continue;
        toolbox.instructions = realloc(toolbox.instructions,
            (i + 1) * sizeof(struct instruction));
        if (toolbox.instructions == NULL)
            return ERR;
        call_check_function(compile_filed_fd, line,
            &toolbox.instructions[i]);
        toolbox.instructions[i].index = pos;
        handle_label(line, &toolbox.instructions[i], &toolbox.labels);
        pos += get_instruction_size(&toolbox.instructions[i]);
        ++i;
    }
    write_labels(compile_filed_fd, &toolbox, params_debute);
    return SUCC;
}
