#include "shell.h"

/**
 * getstr - function to read a string from  the cli
 * @str: a string pointer
 *
 * Return: return 1 in success and -1 in failure
 */

int getstr(char *str)
{
        char **line;
        size_t siz = 0;

        signal(SIGINT, sigintHandler);
        line = malloc(24);
        if (!line)
        {
                return (-1);
        }

        if ((getline(line, &siz, stdin)) == -1)
        {
                return (-1);
        }

        line[0][siz] = '\0';

        strcopy(line[0], str);

        if (line[0][siz - 2] == '\\')
        {
                do {
                        str[strleng(str) - 1] = ' ';
                        siz = 0;
                        printprompt(1);

                        if ((getline(line, &siz, stdin)) == -1)
                        {
                                return (-1);
                        }
                        line[0][siz] = '\0';

                        strmix(line[0], str);
                } while (line[0][siz - 2] == '\\');
        }

        free(line);
        return (1);
}

/**
 * strcopy - a function to copy to strings
 * @src: the string to be copied
 * @dest: the destination of the copied string
 *
 * Return: returns nothing (void)
 */
        void strcopy(char *src, char *dest)
{
        int i = 0;
        int j = 0;
        if (!dest)
        {
                j = 0;
        }
        while (src[i] != '\0' && src[i] != '\n')
        {
                dest[j++] = src[i++];
        }
        dest[j] = '\0';
}
