# Let's Practice

**Let's Practice** est un dépôt où je développe divers projets personnels pour améliorer mes compétences en programmation, principalement en C. Actuellement, il contient un jeu de terminal simple, mais je prévois d'ajouter d'autres projets à mesure que je progresse.

## Projet actuel : **Plus ou Moins**

Le projet actuel est un jeu intitulé **Plus ou Moins**. C'est un jeu interactif en terminal où l'ordinateur choisit un nombre entre 1 et 100, et le joueur doit deviner ce nombre. À chaque tentative, le jeu indique si le nombre est trop élevé, trop bas, ou juste. L'objectif est de deviner le nombre en aussi peu de tentatives que possible.

### Fonctionnalités du jeu :
- L'ordinateur génère un nombre aléatoire entre 1 et 100.
- Le joueur doit entrer un nombre pour essayer de deviner celui choisi par l'ordinateur.
- À chaque tentative, le jeu indique si le nombre est trop élevé ou trop bas.
- Le jeu continue jusqu'à ce que le joueur trouve le bon nombre.

### Prérequis
- **Un compilateur C** (comme GCC).
- **Un terminal** (pour exécuter le programme).

### Installation
1. Clone ce dépôt sur ton ordinateur :
    ```bash
    git clone https://github.com/ton-utilisateur/let-s-practice.git
    ```
2. Navigue vers le répertoire du projet :
    ```bash
    cd let-s-practice
    ```
3. Compile le programme avec GCC :
    ```bash
    gcc -o plus_ou_moins plus_ou_moins.c
    ```
4. Exécute le jeu :
    ```bash
    ./plus_ou_moins
    ```

### Comment jouer
1. Lorsque le jeu démarre, l'ordinateur choisira un nombre entre 1 et 100.
2. Entrez votre première tentative.
3. L'ordinateur vous dira si le nombre est trop élevé, trop bas, ou correct.
4. Continuez à deviner jusqu'à ce que vous trouviez le bon nombre !

### Exemple d'exécution :
```text
Bienvenue dans le jeu "Plus ou Moins" !
L'ordinateur a choisi un nombre entre 1 et 100.
Devine ce nombre !

Entrez un nombre : 50
Trop haut ! Essaye encore.

Entrez un nombre : 25
Trop bas ! Essaye encore.

Entrez un nombre : 37
Félicitations, vous avez deviné le bon nombre !
