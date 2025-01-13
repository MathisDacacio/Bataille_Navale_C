# Bataille Navale

## Table des matières

1. [Description](#description)
2. [Fonctionnalités](#fonctionnalités)
3. [Instructions](#instructions)
4. [Structure du Code](#structure-du-code)
5. [Compilation et Exécution](#compilation-et-exécution)
   - [Pré-requis](#pré-requis)
   - [Instructions](#instructions-1)
   - [Exemple d'Exécution](#exemple-dexécution)

## Description

"Bataille Navale" est une implémentation simple du célèbre jeu de société dans lequel un joueur affronte un ordinateur. Le but du jeu est de couler tous les navires de l'adversaire avant que l'adversaire ne coule tous les navires du joueur. Les navires sont placés aléatoirement sur une grille de 5x5, et chaque joueur doit tenter de localiser et détruire les navires de l'autre en tirant sur des coordonnées spécifiques de la grille.

## Fonctionnalités

- Grille de jeu de 5x5 pour chaque joueur.
- Le joueur place ses navires et l'ordinateur place les siens de manière aléatoire.
- Le joueur peut tirer sur une case spécifique à chaque tour et l'ordinateur fait de même.
- Les tirs peuvent toucher (X) ou manquer (O).
- Le joueur gagne lorsque tous les navires de l'ordinateur sont coulés.
- L'ordinateur gagne lorsque tous les navires du joueur sont coulés.

## Instructions

1. **Lancement du jeu** : Exécutez le programme en C.
2. **Placement des navires** : Le joueur et l'ordinateur placent chacun 3 navires sur leur grille de manière aléatoire.
3. **Tour du joueur** : À chaque tour, le joueur entre des coordonnées (x y) pour tirer sur la grille de l'ordinateur.
4. **Tour de l'ordinateur** : L'ordinateur tire également sur une case aléatoire de la grille du joueur.
5. **Fin du jeu** : Le jeu se termine lorsque l'un des joueurs (humain ou ordinateur) a coulé tous les navires de l'adversaire.

## Structure du Code

- **initializeGrid** : Initialise la grille de jeu avec des cases d'eau (~).
- **placeShips** : Place les navires aléatoirement sur la grille.
- **printGrid** : Affiche la grille à l'écran, avec ou sans révéler les navires.
- **playerTurn** : Permet au joueur de tirer sur la grille de l'ordinateur.
- **computerTurn** : Permet à l'ordinateur de tirer sur la grille du joueur.
- **isGameOver** : Vérifie si le jeu est terminé en fonction de l'état des grilles.

## Compilation et Exécution

### Pré-requis
- Un compilateur C (par exemple, GCC).

### Instructions

1. Clonez ou téléchargez le projet.
2. Ouvrez un terminal et placez-vous dans le répertoire du projet.
3. Compilez le programme avec la commande suivante :

   ```bash
   gcc -o bataille_navale bataille_navale.c
4. Exécutez le programme : ./bataille_navale

### Exemple d'Exécution

=== Bataille Navale ===

Placement des navires du joueur...
Placement des navires de l'ordinateur...

Grille de l'ordinateur :
  0 1 2 3 4 
0 ~ ~ ~ ~ ~ 
1 ~ ~ ~ ~ ~ 
2 ~ ~ ~ ~ ~ 
3 ~ ~ ~ ~ ~ 
4 ~ ~ ~ ~ ~ 

Votre grille :
  0 1 2 3 4 
0 ~ ~ ~ ~ ~ 
1 ~ ~ ~ ~ ~ 
2 ~ ~ ~ ~ ~ 
3 ~ ~ ~ ~ ~ 
4 ~ ~ ~ ~ ~ 

Votre tour! Entrez les coordonnees (x y) pour tirer: 2 2
A l'eau!

Tour de l'ordinateur...
L'ordinateur a tire en (1, 1) et a manque.
...

Felicitations, vous avez gagne!
Fin du jeu. Merci d'avoir joue!

