# Let's Practice

Bienvenue dans mon repository **Let's Practice** ! Ce dépôt rassemble des petits projets en C que je réalise pour m'entraîner : un jeu du **Plus ou Moins**, un **Jeu du pendu** en mode console et un exercice sur les **listes chaînées**. L'objectif est de pratiquer les bases du langage C : lecture de l'entrée standard, allocation mémoire, lecture de fichiers ligne par ligne, affichage dans le terminal et organisation d'un projet avec un Makefile.

## Sommaire

- [À propos](#à-propos)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Structure du projet](#structure-du-projet)
- [Contributions](#contributions)

## À propos

Chaque projet est écrit en C, sans bibliothèque externe, avec uniquement la bibliothèque standard et les appels système (`read`, `write`, `open`, `ioctl`). Certaines fonctions classiques sont recodées à la main et préfixées par `my_` (`my_calloc`, `my_strlen`, `my_strjoin`, `my_strdup`, `my_strchr`, `my_isalpha`).

Le **Plus ou Moins** se compile avec un Makefile qui produit une bibliothèque statique (`libPlus_ou_moins.a`) et l'exécutable `Game`. Le **Jeu du pendu** n'a pas de Makefile pour l'instant et se compile directement avec `gcc`.

## Fonctionnalités

### 1. Jeu du Plus ou Moins (`Plus_ou_moins/`)

- Titre en art ASCII affiché en couleur au lancement.
- Menu de choix du niveau :
  1. **Facile** : nombre mystère entre 1 et 100.
  2. **Moyen** : nombre mystère entre 1 et 1000.
  3. **Difficile** : nombre mystère entre 1 et 10000.
  4. **Quitter**.
- Nombre mystère tiré au hasard avec `srand(time(NULL))` et `rand()`.
- À chaque proposition, le jeu répond « C'est Plus » ou « C'est Moins ».
- Les entrées hors de l'intervalle du niveau sont refusées et redemandées.
- Le nombre de coups est affiché quand le nombre est trouvé, puis le menu revient.
- Textes colorés grâce aux séquences d'échappement ANSI.
- `Plus_ou_moins.c` contient une première version plus simple (niveau unique de 1 à 100, saisie avec `scanf`), compilée à part.

### 2. Jeu du pendu (`Jeu du pendu/`)

- Titre « HANGMAN » et menu en art ASCII, centrés selon la largeur du terminal (`ioctl` + `TIOCGWINSZ`).
- Menu à trois choix : **1. Start**, **2. Settings** (pas encore implémenté), **3. Exit**.
- Mot choisi au hasard parmi les 100 mots du fichier `mots_pendu.txt`, lu ligne par ligne avec `get_next_line`.
- Le mot est affiché masqué avec des `*`, puis chaque bonne lettre est révélée à toutes ses positions.
- Le joueur propose une lettre à la fois (minuscule ou majuscule) ; une entrée invalide affiche « entree incorect ».
- Chaque mauvaise lettre fait avancer le dessin du pendu (étapes définies dans `tab_ascii.c`).
- La partie se termine quand le mot est trouvé (« bravo ») ou à la 9ᵉ erreur (« perdu », avec le mot à trouver), puis Entrée ramène au menu.
- Les lettres du mot sont dessinées en grandes lettres ASCII.

La version la plus récente se trouve dans `Jeu du pendu/Jeu du pendu/`. Les fichiers directement dans `Jeu du pendu/` sont une version plus ancienne (menu et cadre de jeu seulement).

### 3. Exercice sur les listes chaînées (`Jeu du pendu/liste chaine exercice/`)

- Définition d'une structure de nœud (`T_node`) et d'une structure de liste (`Element`).
- `init` : crée une liste avec un premier élément.
- `create_node` : ajoute un nouvel élément en tête de liste.
- `display_list` : affiche la liste (`30 -> 20 -> 10 -> NULL`).

```sh
gcc -Wall -Wextra -Werror "Jeu du pendu/liste chaine exercice/ex_1.c" -o liste
./liste
```

## Installation

```sh
git clone https://github.com/AxelPj/let-s-practice.git
cd let-s-practice
```

### Plus ou Moins

```sh
cd Plus_ou_moins
make
```

Cette commande génère la bibliothèque `libPlus_ou_moins.a`, les fichiers objets dans `build/` et l'exécutable `Game`.

Autres règles disponibles :

```sh
make clean    # supprime les fichiers objets et le dossier build/
make fclean   # supprime les objets, la bibliothèque et l'exécutable
make re       # nettoie puis recompile tout
```

### Jeu du pendu

```sh
cd "Jeu du pendu/Jeu du pendu"
gcc -Wall -Wextra *.c -o pendu
```

## Utilisation

### Plus ou Moins

```sh
./Game
```

Exemple de partie :

```
Choisis ton niveau de difficulté :
1. Niveau Facile : Trouve un nombre entre 1 et 100
2. Niveau Moyen : Trouve un nombre entre 1 et 1000
3. Niveau Difficile : Trouve un nombre entre 1 et 10000
4. Pour quitter
Entrez le chiffre correspondant au niveau choisi : 1

Bienvenue dans le niveau 1
essaye de trouver le nombre mystere !
choisie ton nombre : 50
C'est Moins, réessaye :
25
C'est Plus, réessaye :
...
bravo tu a trouver le nombre mystere en 7 coup
```

Pour la première version :

```sh
gcc -Wall -Wextra Plus_ou_moins.c -o plus_ou_moins_v1
./plus_ou_moins_v1
```

### Jeu du pendu

Le programme doit être lancé depuis son dossier, car il ouvre `mots_pendu.txt` avec un chemin relatif :

```sh
cd "Jeu du pendu/Jeu du pendu"
./pendu
```

Tapez `1` puis Entrée pour commencer une partie, puis proposez une lettre à la fois. Tapez `3` dans le menu pour quitter.

### Réutiliser les fonctions `my_`

Les fonctions du pendu sont déclarées dans `pendu.h` :

```c
#include "pendu.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("mots_pendu.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("Premier mot : %sLongueur : %d\n", line, my_strlen(line));
    free(line);
    close(fd);
    return (0);
}
```

## Structure du projet

- `README.md` : ce fichier.
- `.gitignore` : exclut les fichiers compilés (`*.o`, `*.a`, `build/`, `*.gch`, `a.out`, `Game`).
- `Plus_ou_moins/Makefile` : règles `all`, `clean`, `fclean`, `re`.
- `Plus_ou_moins/Plus_ou_moins_v2.h` : en-tête avec les includes, `BUFFER_SIZE` et les prototypes.
- `Plus_ou_moins/Plus_ou_moins_v2.c` : fonction `main`, titre ASCII et menu de choix du niveau.
- `Plus_ou_moins/Plus_ou_moins_lvl.c` : déroulement des parties des niveaux 1, 2 et 3 (`my_lvl1`, `my_lvl2`, `my_lvl3`).
- `Plus_ou_moins/Plus_ou_moins_utils.c` : fonctions utilitaires `my_calloc` et `my_verifnb`.
- `Plus_ou_moins/Plus_ou_moins.c` : première version du jeu, autonome, avec `scanf`.
- `Plus_ou_moins/flemme.c` : petit programme qui affiche les nombres de 1 à 100.
- `Jeu du pendu/Jeu du pendu/main.c` : boucle principale et gestion du menu.
- `Jeu du pendu/Jeu du pendu/Hangman.c` : déroulement d'une partie (`jeu`) et affichage du mot en lettres ASCII (`menu_letter`).
- `Jeu du pendu/Jeu du pendu/game_utils.c` : tirage du mot, centrage du texte, effacement de l'écran, masquage et révélation des lettres.
- `Jeu du pendu/Jeu du pendu/Interface_menu.c` : affichage du titre, du menu et déplacement du curseur.
- `Jeu du pendu/Jeu du pendu/tab_ascii.c` : tableaux des lettres ASCII et des étapes du dessin du pendu.
- `Jeu du pendu/Jeu du pendu/get_next_line.c` : lecture d'un fichier ligne par ligne.
- `Jeu du pendu/Jeu du pendu/get_next_line_utils.c` : fonctions `my_calloc`, `my_strlen`, `my_strjoin`, `my_strdup`, `my_strchr` utilisées par `get_next_line`.
- `Jeu du pendu/Jeu du pendu/pendu.h` : couleurs, `BUFFER_SIZE` et prototypes du jeu.
- `Jeu du pendu/Jeu du pendu/menu_game.h` : déclarations des tableaux ASCII.
- `Jeu du pendu/Jeu du pendu/mots_pendu.txt` : liste des 100 mots à deviner.
- `Jeu du pendu/Jeu du pendu/.Alphabet_Ascii_art` : alphabet en art ASCII utilisé comme modèle.
- `Jeu du pendu/game.c`, `game_utils.c`, `Interface_menu.c`, `Interface_Jeu.c`, `get_next_line*.c`, `pendu.h` : ancienne version du pendu (menu et cadre de jeu).
- `Jeu du pendu/Plus_ou_moins/` : copie du dossier `Plus_ou_moins/`.
- `Jeu du pendu/liste chaine exercice/ex_1.c` : exercice sur les listes chaînées.

## Contributions

Les contributions sont les bienvenues ! Pour proposer une modification :

1. Forker ce repository.
2. Créer une branche : `git checkout -b feature/nouvelle-fonctionnalite`
3. Committer : `git commit -m "Ajout d'une nouvelle fonctionnalité"`
4. Pousser : `git push origin feature/nouvelle-fonctionnalite`
5. Ouvrir une Pull Request.

> ⚠️ **Le projet n'est pas terminé.** Le Jeu du pendu (menu « Settings », règles du jeu, Makefile) et l'exercice sur les listes chaînées sont encore en cours de développement.
