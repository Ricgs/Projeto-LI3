CC = gcc
CFLAGS = -g -lncurses -O2 -Wall $(INCLUDES) `pkg-config --cflags --libs glib-2.0`

BIN_DIR = bin
BLD_DIR = build
INC_DIR = include
SRC_DIR = src

# Adiciona dinamicamente todos os subdiretórios dentro de include/
INCLUDES = $(shell find $(INC_DIR) -type d | sed 's/^/-I /')

SRC = $(shell find $(SRC_DIR) -type f -name '*.c') main.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(BLD_DIR)/%.o,$(SRC))

PROGRAM = programa-principal
PROGRAM_TEST = programa-testes

.DEFAULT_GOAL = build

build: setup $(PROGRAM) $(PROGRAM_TEST)

$(PROGRAM): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

$(PROGRAM_TEST): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) -DTEST_MODE

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c -I $(INC_DIR) -o $@ $< $(CFLAGS)

.PHONY: setup
setup:
	@mkdir -p $(BLD_DIR)

.PHONY: clean
clean:
	@-rm -r $(BLD_DIR)
	@-rm -f $(PROGRAM) $(PROGRAM_TEST)
