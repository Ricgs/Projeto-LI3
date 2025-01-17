#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include "entidades/artistas.h"
#include "entidades/musicas.h"
#include "entidades/historicos.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "manager_dados/erros_help.h"
#include "manager_dados/manager_historicos.h"
#include "catalogos/list.h"
#include "utils/calculos.h"
#include "entidades/semana.h"
/*
// Função para comparar o tempo de músicas dos artistas
int compare_artists(const void *a, const void *b) {
    ARTISTA *artistaA = *(ARTISTA **)a;
    ARTISTA *artistaB = *(ARTISTA **)b;

    // Supondo que o ARTISTA tem um campo 'total_duration'
    return artistaB->total_duration - artistaA->total_duration;
}

// Função para processar os históricos e organizar os artistas
void processar_historicos(GHashTable *historicos, GHashTable *musicas, GHashTable *artistas, GHashTable *semanas) {
    GHashTableIter iter;
    gpointer key, value;

    GHashTable *semanas = g_hash_table_new(g_str_hash, g_str_equal);

    g_hash_table_iter_init(&iter, historicos);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        HISTORICO h = (HISTORICO)value;
        MUSICA m = (MUSICA)g_hash_table_lookup(musicas, h->music_id);
        if (m) {
            for (guint i = 0; i < m->artist_id->len; i++) {
                char *artist_id = g_array_index(m->artist_id, char *, i);
                ARTISTA a = (ARTISTA)g_hash_table_lookup(artistas, artist_id);
                if (a) {
                    // Atualiza o total de tempo do artista
                    a->total_duration += atoi(h->duration);
                    
                    // Adiciona o artista à semana correspondente
                    SEMANA s = (SEMANA)g_hash_table_lookup(semanas, h->timestamp);
                    if (!s) {
                        s = g_malloc(sizeof(struct semana));
                        s->semana = h->timestamp;
                        s->top_artistas = g_array_new(FALSE, FALSE, sizeof(ARTISTA));
                        g_hash_table_insert(semanas, s->semana, s);
                    }
                    g_array_append_val(s->top_artistas, a);
                }
            }
        }
    }

    // Organiza e mantém apenas os 10 melhores artistas por semana
    g_hash_table_iter_init(&iter, semanas);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        SEMANA s = (SEMANA)value;
        g_array_sort(s->top_artistas, compare_artists);
        if (s->top_artistas->len > 10) {
            g_array_set_size(s->top_artistas, 10);
        }
    }
}
*/