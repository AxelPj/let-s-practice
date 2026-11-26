# Nom de l'exécutable
NAME = pendu

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Dossiers
SRC_DIR = src
OBJ_DIR = build

# Fichiers sources
SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/game/Hangman.c \
		$(SRC_DIR)/game/game_utils.c \
		$(SRC_DIR)/ui/Interface_menu.c \
		$(SRC_DIR)/ui/tab_ascii.c \
		$(SRC_DIR)/utils/get_next_line.c \
		$(SRC_DIR)/utils/get_next_line_utils.c

# En-têtes
HEADERS = include/pendu.h include/menu_game.h

# Fichiers objets compilés (build/ reproduit l'arborescence de src/)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Cible par défaut
all: $(NAME)

# Édition de liens
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compilation des .c en .o dans le dossier build
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compiler puis lancer le jeu (depuis ce dossier, pour trouver data/)
run: all
	./$(NAME)

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJ_DIR)

# Nettoyage complet
fclean: clean
	@rm -f $(NAME)

# Rebuild complet
re: fclean all

.PHONY: all run clean fclean re
