#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <dirent.h>

#include "interface/frontend/menu_ajuda.h"

void menu_ajuda(int x, int y, int ncols, int nrows, int branco, int branco_preto)
{
    /// Preenche as bordas
    for (int i = 0; i < nrows; i++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(i, 0, ' ');       // Esquerda
        mvaddch(i, ncols - 1, ' ');  // Direita
        attroff(COLOR_PAIR(branco));
    }
    for (int j = 0; j < ncols; j++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(0, j, ' ');       // Superior
        mvaddch(nrows - 1, j, ' ');  // Inferior
        attroff(COLOR_PAIR(branco));
    }

    // Mensagem no canto superior esquerdo
    const char *mensagemSuperior = "Voltar 'V'";
    attron(COLOR_PAIR(branco_preto));
    mvprintw(1, 1, "%s", mensagemSuperior);
    attroff(COLOR_PAIR(branco_preto));

    // Mensagem no centro da tela
    const char *mensagem = "Qual a query em que precisa de ajuda?";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 12, x - 3, "%s", mensagem);
    attroff(COLOR_PAIR(branco_preto));

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 7, x - 8, "Query 1 '1'");
    attroff(COLOR_PAIR(branco_preto));

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y -2, x - 8, "Query 2 '2'");
    attroff(COLOR_PAIR(branco_preto));

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y + 3, x - 8, "Query 3 '3'");
    attroff(COLOR_PAIR(branco_preto));

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 7, x + 30, "Query 4 '4'");
    attroff(COLOR_PAIR(branco_preto));

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 2, x + 30, "Query 5 '5'");
    attroff(COLOR_PAIR(branco_preto));

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y + 3, x + 30, "Query 6 '6'");
    attroff(COLOR_PAIR(branco_preto));
}

void menu_query1(int x, int y, int ncols, int nrows, int branco, int branco_preto)
{
    /// Preenche as bordas
    for (int i = 0; i < nrows; i++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(i, 0, ' ');       // Esquerda
        mvaddch(i, ncols - 1, ' ');  // Direita
        attroff(COLOR_PAIR(branco));
    }
    for (int j = 0; j < ncols; j++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(0, j, ' ');       // Superior
        mvaddch(nrows - 1, j, ' ');  // Inferior
        attroff(COLOR_PAIR(branco));
    }

    // Mensagem no canto superior esquerdo
    const char *mensagemSuperior = "Voltar 'V'";
    attron(COLOR_PAIR(branco_preto));
    mvprintw(1, 1, "%s", mensagemSuperior);
    attroff(COLOR_PAIR(branco_preto));

    // Mensagem no centro da tela
    const char *mensagem = "Q1 - Listar o resumo de um utilizador ou artista, consoante o identificador recebido por argumento.";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 6, x, "%s", mensagem);
    mvprintw(y - 4, x, "A query recebe como argumento o identificador único de um utilizador ou artista, sendo garantido");
    mvprintw(y - 3, x, "que não existem identificadores repetidos entre as diferentes entidades. Deverá ser retornada uma");
    mvprintw(y - 2, x, "linha vazia caso o id não conste do sistema. Nos casos em que conste, a query deverá retornar as");
    mvprintw(y - 1, x, "seguintes informações:");
    mvprintw(y + 2, x, "- Utilizador");
    mvprintw(y + 3, x, "email;first_name;last_name;age;country");
    mvprintw(y + 5, x, "- Artista");
    mvprintw(y + 6, x, "name;type;country;num_albums_individual;total_recipe");
    attroff(COLOR_PAIR(branco_preto));
}

void menu_query2(int x, int y, int ncols, int nrows, int branco, int branco_preto)
{
    /// Preenche as bordas
    for (int i = 0; i < nrows; i++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(i, 0, ' ');       // Esquerda
        mvaddch(i, ncols - 1, ' ');  // Direita
        attroff(COLOR_PAIR(branco));
    }
    for (int j = 0; j < ncols; j++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(0, j, ' ');       // Superior
        mvaddch(nrows - 1, j, ' ');  // Inferior
        attroff(COLOR_PAIR(branco));
    }

    // Mensagem no canto superior esquerdo
    const char *mensagemSuperior = "Voltar 'V'";
    attron(COLOR_PAIR(branco_preto));
    mvprintw(1, 1, "%s", mensagemSuperior);
    attroff(COLOR_PAIR(branco_preto));

    // Mensagem no centro da tela
    const char *mensagem = "Q2: Quais são os top N artistas com maior discografia?";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 4, x, "%s", mensagem);
    mvprintw(y - 2, x, "A query recebe como argumento o número de artistas que devem constar do output, podendo ainda");
    mvprintw(y - 1, x, "receber (ou não) um filtro opcional, o filtro de país, sendo que quando presente só devem ser considerados");
    mvprintw(y, x, "artistas desse país. Deverá escrever para o ficheiro de resultado os campos que constam do exemplo");
    mvprintw(y + 1, x, "abaixo. O tamanho da discografia dos artistas é calculado pela soma da duração das suas músicas. Artistas");
    mvprintw(y + 2, x, "coletivos e individuais devem ser tratados de forma separada, ignorando relações que existam entre eles.");
    mvprintw(y + 3, x, "Em caso de empate, os artistas devem ser ordenados por ordem crescente de id (i.e., ids mais pequenos");
    mvprintw(y + 4, x, "devem surgir primeiro).");
    attroff(COLOR_PAIR(branco_preto));
}

void menu_query3(int x, int y, int ncols, int nrows, int branco, int branco_preto)
{
    /// Preenche as bordas
    for (int i = 0; i < nrows; i++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(i, 0, ' ');       // Esquerda
        mvaddch(i, ncols - 1, ' ');  // Direita
        attroff(COLOR_PAIR(branco));
    }
    for (int j = 0; j < ncols; j++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(0, j, ' ');       // Superior
        mvaddch(nrows - 1, j, ' ');  // Inferior
        attroff(COLOR_PAIR(branco));
    }

    // Mensagem no canto superior esquerdo
    const char *mensagemSuperior = "Voltar 'V'";
    attron(COLOR_PAIR(branco_preto));
    mvprintw(1, 1, "%s", mensagemSuperior);
    attroff(COLOR_PAIR(branco_preto));

    // Mensagem no centro da tela
    const char *mensagem = "Q3: Quais são os géneros de música mais populares numa determinada faixa etária?";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 4, x, "%s", mensagem);
    mvprintw(y - 2, x, "A query recebe como argumento as idades mínima e máxima da faixa etária dos utilizadores a consi-");
    mvprintw(y - 1, x, "derar. Deve produzir como output uma lista ordenada de géneros por ordem decrescente de popularidade");
    mvprintw(y, x, "e o número total de likes associados. Considere que a popularidade de um género é determinada a partir");
    mvprintw(y + 1, x, "dos géneros das liked musics dos utilizadores que se encontram nessa faixa etária. Por exemplo, se músi-");
    mvprintw(y + 2, x, "cas do género A tiverem 10 likes e músicas do género B apenas tiverem 8, considera-se o género A mais");
    mvprintw(y + 3, x, "popular. Em caso de empate prevalece a ordem alfabética.");
    attroff(COLOR_PAIR(branco_preto));
}

void menu_query4(int x, int y, int ncols, int nrows, int branco, int branco_preto)
{
    /// Preenche as bordas
    for (int i = 0; i < nrows; i++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(i, 0, ' ');       // Esquerda
        mvaddch(i, ncols - 1, ' ');  // Direita
        attroff(COLOR_PAIR(branco));
    }
    for (int j = 0; j < ncols; j++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(0, j, ' ');       // Superior
        mvaddch(nrows - 1, j, ' ');  // Inferior
        attroff(COLOR_PAIR(branco));
    }

    // Mensagem no canto superior esquerdo
    const char *mensagemSuperior = "Voltar 'V'";
    attron(COLOR_PAIR(branco_preto));
    mvprintw(1, 1, "%s", mensagemSuperior);
    attroff(COLOR_PAIR(branco_preto));

    // Mensagem no centro da tela
    const char *mensagem = "Q4: Qual é o artista que esteve no top 10 mais vezes?";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 1, x, "%s", mensagem);
    mvprintw(y + 1, x, "Opcionalmente, a query pode receber um filtro que imponha o intervalo de datas a considerar.");
    mvprintw(y + 2, x, "Nesse caso apenas deverão ser tidos em conta os top 10 compreendidos entre esse intervalo de");
    mvprintw(y + 3, x, "tempo. Considere que o top 10 é calculado semanalmente e é determinado pelo maior tempo de");
    mvprintw(y + 4, x, "reprodução efetivo, ou seja, o tempo de reprodução registado no histórico de atividade, e não o");
    mvprintw(y + 5, x, "tempo de duração de uma música. Considere ainda que uma semana tem início no domingo e");
    mvprintw(y + 6, x, "termina no sábado seguinte. Se o intervalo de tempo captar uma semana de forma parcial, seja");
    mvprintw(y + 7, x, "no início ou no fim, o top10 dessa(s) semana(s) também deve ser considerado. Artistas coletivos e");
    mvprintw(y + 8, x, "individuais devem ser tratados de forma separada, ignorando relações que existam entre eles. Em");
    mvprintw(y + 9, x, "caso de empate, prevalece o artista com id mais baixo.");
    attroff(COLOR_PAIR(branco_preto));
}

void menu_query5(int x, int y, int ncols, int nrows, int branco, int branco_preto)
{
    /// Preenche as bordas
    for (int i = 0; i < nrows; i++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(i, 0, ' ');       // Esquerda
        mvaddch(i, ncols - 1, ' ');  // Direita
        attroff(COLOR_PAIR(branco));
    }
    for (int j = 0; j < ncols; j++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(0, j, ' ');       // Superior
        mvaddch(nrows - 1, j, ' ');  // Inferior
        attroff(COLOR_PAIR(branco));
    }

    // Mensagem no canto superior esquerdo
    const char *mensagemSuperior = "Voltar 'V'";
    attron(COLOR_PAIR(branco_preto));
    mvprintw(1, 1, "%s", mensagemSuperior);
    attroff(COLOR_PAIR(branco_preto));

    // Mensagem no centro da tela
    const char *mensagem = "Q5: Recomendação de utilizadores com gostos parecidos";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 2, x, "%s", mensagem);
    mvprintw(y, x, "Construa uma matriz em que cada linha corresponde a um utilizador e cada coluna corresponde a");
    mvprintw(y + 1, x, "um género de música. O valor de cada célula na matriz deverá corresponder ao número de vezes");
    mvprintw(y + 2, x, "que o utilizador ouviu músicas com esse género.");
    mvprintw(y + 3, x, "De seguida faça uso da biblioteca fornecida pela equipa docente para gerar um conjunto de utiliza-");
    mvprintw(y + 4, x, "dores com gostos parecidos ao de um dado utilizador, utilizando a função que se apresenta abaixo.");
    mvprintw(y + 5, x, "Consulte a interface da biblioteca (.h) para obter mais detalhes sobre a função.");
    mvprintw(y + 6, x, "A query inclui dois argumentos: o id do utilizador para o qual deve ser gerada a lista de utilizadores");
    mvprintw(y + 7, x, "semelhantes e o número de utilizadores a retornar. Para valorização extra, os alunos poderão tentar");
    mvprintw(y + 8, x, "implementar a sua própria biblioteca de recomendações, com a mesma interface da biblioteca");
    mvprintw(y + 9, x, "fornecida pelos docentes. Esta componente terá uma valorização de até 0.5 valores, e fará parte");
    mvprintw(y + 10, x, "dos dois valores destinados ao componente ”Estruturas/Performance/Recomendador”, tal como");
    mvprintw(y + 11, x, "descrito na Secção 2.");
    attroff(COLOR_PAIR(branco_preto));
}

void menu_query6(int x, int y, int ncols, int nrows, int branco, int branco_preto)
{
    /// Preenche as bordas
    for (int i = 0; i < nrows; i++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(i, 0, ' ');       // Esquerda
        mvaddch(i, ncols - 1, ' ');  // Direita
        attroff(COLOR_PAIR(branco));
    }
    for (int j = 0; j < ncols; j++) 
    {
        attron(COLOR_PAIR(branco));
        mvaddch(0, j, ' ');       // Superior
        mvaddch(nrows - 1, j, ' ');  // Inferior
        attroff(COLOR_PAIR(branco));
    }

    // Mensagem no canto superior esquerdo
    const char *mensagemSuperior = "Voltar 'V'";
    attron(COLOR_PAIR(branco_preto));
    mvprintw(1, 1, "%s", mensagemSuperior);
    attroff(COLOR_PAIR(branco_preto));

    // Mensagem no centro da tela
    const char *mensagem = "Q6: Resumo anual para um utilizador";
    int mensagemLength = strlen(mensagem);
    x = (ncols - mensagemLength) / 2;
    y = nrows / 2 - 1;

    attron(COLOR_PAIR(branco_preto));
    mvprintw(y - 5, x, "%s", mensagem);
    mvprintw(y - 3, x, "A query recebe dois argumentos: o id do utilizador para o qual queremos obter um resumo de");
    mvprintw(y - 2, x, "estatísticas anuais; e o ano ao qual essas estatísticas se referem. Pode ainda ser passado um argu-");
    mvprintw(y - 1, x, "mento opcional numérico, N, sendo que em tal caso devem-se imprimir em linhas consecutivas os");
    mvprintw(y, x, "N artistas mais ouvidos pelo utilizador nesse ano, em função do tempo de reprodução.");
    mvprintw(y + 1, x, "A análise deve incluir o tempo total de audição do utilizador (no formato hh:mm:ss), o número de");
    mvprintw(y + 2, x, "músicas ouvidas (cada música deve ser contabilizada apenas uma vez), o artista mais ouvido (com");
    mvprintw(y + 3, x, "desempate por id mais baixo), o dia em que reproduziu mais músicas (incluindo músicas repetidas,");
    mvprintw(y + 4, x, "com desempate por data mais recente, em formato de data), o género de música mais ouvido (com");
    mvprintw(y + 5, x, "desempate por ordem alfabética), o seu álbum favorito (com desempate por ordem alfabética) e a");
    mvprintw(y + 6, x, "hora do dia em que costuma ouvir mais música (representado por dois dígitos, no intervalo [00-");
    mvprintw(y + 7, x, "23], e com desempate por hora mais cedo no dia). À exceção do número de músicas ouvidas e do");
    mvprintw(y + 8, x, "dia em que o utilizador reproduziu mais músicas, todos os campos deverão ser determinados com");
    mvprintw(y + 9, x, "base em tempo acumulado de reprodução.");
    mvprintw(y + 10, x, "Para cada um dos N artistas deve apresentar o nome do artista, o número de músicas distintas");
    mvprintw(y + 11, x, "ouvidas desse artista e o tempo total de audição. Caso o utilizador tenha ouvido menos do que N");
    mvprintw(y + 12, x, "artistas, só deverão ser imprimidos os artistas que efetivamente ouviu.");
    mvprintw(y + 13, x, "Caso o utilizador não possua nenhum registo de atividade nesse ano, o output deverá ser vazio, ou");
    mvprintw(y + 14, x, "seja, barra n.");
    attroff(COLOR_PAIR(branco_preto));
}
