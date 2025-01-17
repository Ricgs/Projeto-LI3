#include <glib.h>
#include <stdio.h>
#include <string.h>
#include "utils/calculos.h"
#include <ctype.h>
#include <ncurses.h>



int convert_duracao_to_seconds(const char *duracao) {
    int minutes, seconds, horas;
    sscanf(duracao, "%d:%d:%d", &horas, &minutes, &seconds);
    return horas * 3600 + minutes * 60 + seconds;
}


int is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

void s_to_h(int seg, char *buffer) {
    int horas = seg / 3600;           
    int minutos = (seg % 3600) / 60;  
    int segundos = seg % 60;           

    sprintf(buffer, "%02d:%02d:%02d", horas, minutos, segundos);
}

char *remove_aspas(char *str) {
    if (str == NULL) return NULL;

    size_t len = strlen(str);

    if (len > 0 && str[0] == '"') {     // Verifica e remove a aspa inicial
        memmove(str, str + 1, len);     // Move os caracteres para a esquerda
        len--;                          // Atualiza o comprimento
    }

    if (len > 0 && str[len - 1] == '"') {   // Verifica e remove a aspa final
        str[len - 1] = '\0';                // Define o terminador nulo
    }

    return str;
}

void parse_A_U(GArray *array, char *str)
{
    char *clean_str = strdup(str);
    char *ap = clean_str;
    clean_str[strlen(clean_str) - 1] = '\0';
    clean_str++;

    char *token = strsep(&clean_str, ", ");
    while (token != NULL) 
    {
        if (token[0] == '\'') token++;
        if (token[strlen(token) - 1] == '\'') token[strlen(token) - 1] = '\0';
        if (strlen(token) > 0) {
            char *id = strdup(token);
            g_array_append_val(array, id);
        }
        token = strsep(&clean_str, ", ");
    }
    free(ap);
}

void parse_artist_id(GArray *array, char *str)
{
    char *clean_str = strdup(str);
    char *ap = clean_str;

    if(clean_str[0] == '[')
    {
        clean_str[strlen(clean_str) - 1] = '\0';
        clean_str++;

        char *token = strsep(&clean_str, ", ");
        while (token != NULL) 
        {
            if (token[0] == '\'') token++;
            if (token[strlen(token) - 1] == '\'') token[strlen(token) - 1] = '\0';

            if (strlen(token) > 0) 
            {
                char *id = strdup(token);
                g_array_append_val(array, id);
            }
            token = strsep(&clean_str, ", ");
        }
    } 
    else 
    {
        char *id = strdup(clean_str);
        g_array_append_val(array, id);
    }
    free(ap);
}

//limpa tudo o que está no ecrã
void fundo_preto(int ncols, int nrows, int preto)
{
    for (int linha = 0; linha < LINES; linha++) 
    {
        for (int coluna = 0; coluna < COLS; coluna++) 
        {
            attron(COLOR_PAIR(preto));
            mvaddch(linha, coluna, ' ');
            attroff(COLOR_PAIR(preto));
        }
    }

    refresh();
}

//Verifica o formato das queries introduzidas
int verificarFormato(char *input) 
{
    int queryId;
    int count = 0;

    // Verifique se o input possui a estrutura desejada
    if (sscanf(input, "%dS", &queryId) == 1 && queryId >= 1 && queryId <= 6)
    {
        count++;
    } 
    else if(sscanf(input, "%d ", &queryId) == 1 && queryId >= 1 && queryId <= 6)
    {
        count++;
    }

    if(count == 0) return 1;
    else return 0;


}