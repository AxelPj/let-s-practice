# Nom de la bibliothèque statique
NAME = libPlus_ou_moins.a

# Nom de l'exécutable
EXEC = Game

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Dossier des objets
OBJ_DIR = build
SRC = 	Plus_ou_moins_v2.c \
		Plus_ou_moins_lvl.c \
		Plus_ou_moins_utils.c

# Fichiers objets compilés
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Créer le dossier build si nécessaire
$(shell mkdir -p $(OBJ_DIR))

# Cible par défaut : créer la bibliothèque et l'exécutable
all: $(NAME) $(EXEC)

# Règle pour créer la bibliothèque statique
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

# Règle pour compiler les fichiers .c en .o dans le dossier build
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cible pour créer l'exécutable en liant avec la bibliothèque statique
$(EXEC): $(OBJ) $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) -L. -lPlus_ou_moins

# Nettoyage des fichiers objets
clean:
	@rm -f $(OBJ) $(EXEC) $(NAME)
	$(shell rm -rf $(OBJ_DIR))

# Nettoyage complet : objets et bibliothèque
fclean: clean
	@rm -f $(NAME) $(EXEC)

# Rebuild : nettoyage et compilation complète
re: fclean all