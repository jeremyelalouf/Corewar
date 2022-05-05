/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_file_in_str
*/

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *my_file_in_str(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat stats;
    char *buffer;

    if (fd == -1)
        return (NULL);
    if (stat(filepath, &stats) == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (buffer == NULL)
        return (NULL);
    if (read(fd, buffer, stats.st_size) == -1)
        return (NULL);
    buffer[stats.st_size] = '\0';
    return (buffer);
}
