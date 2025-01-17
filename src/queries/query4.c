#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>
#include "entidades/artistas.h"
#include "entidades/utilizadores.h"
#include "entidades/musicas.h"
#include "catalogos/catalogo_artistas.h"
#include "catalogos/catalogo_utilizadores.h"
#include "catalogos/catalogo_historicos.h"
#include "queries/query1.h"
#include "manager_dados/parser.h"
#include "manager_dados/validacao_entidades.h"
#include "modos_execucao/modo_batch.h"
#include "manager_dados/manager_semana.h"
