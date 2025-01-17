#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>


void write_result(int numlinha, int mode, char *result) {

    char query_path[60];
    sprintf(query_path, "resultados/command%d_output.txt", numlinha);

    char *query_ficheiro = strdup(query_path);
    FILE *ficheiro = fopen(query_ficheiro, "w");
    if (ficheiro == NULL) {
        perror("Erro ao abrir o arquivo de erros");
        free(query_ficheiro);
        free(result); // Free result if an error occurs
        return;
    }

    if (result == NULL) {
        fprintf(ficheiro, "\n");
        fclose(ficheiro);
        free(query_ficheiro);
        return;
    }

    // Processa o result linha por linha
    const char *current = result;
    while (*current) {
        const char *line_end = strchr(current, '\n');
        if (!line_end) {
            line_end = current + strlen(current); // Última linha sem '\n'
        }

        size_t line_length = line_end - current;
        char *line = malloc((line_length + 1) * sizeof(char));
        strncpy(line, current, line_length);
        line[line_length] = '\0';

        // Substitui '|' por '=' ou ';' dependendo do modo
        for (char *p = line; *p; p++) {
            if (*p == ';' && mode == 1) {
                *p = '=';
            }
        }

        fprintf(ficheiro, "%s\n", line);
        free(line);

        if (*line_end == '\n') {
            current = line_end + 1;
        } else {
            break; // Final da string
        }
    }

    free(query_ficheiro);
    fclose(ficheiro);
    free(result);
    return;
}
