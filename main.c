#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define SHIP_COUNT 3

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '~'; // ~ represents water
        }
    }
}

void placeShips(char grid[GRID_SIZE][GRID_SIZE], int shipCount) {
    srand(time(NULL));
    int placedShips = 0;

    while (placedShips < shipCount) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;

        if (grid[x][y] == '~') { // Place ship only if cell is empty
            grid[x][y] = 'S'; // S represents a ship
            placedShips++;
        }
    }
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE], int revealShips) {
    printf("  ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'S' && !revealShips) {
                printf("~ "); // Hide ships if revealShips is false
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int isGameOver(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'S') {
                return 0; // Game is not over if any ship is still present
            }
        }
    }
    return 1; // Game is over
}

void playerTurn(char grid[GRID_SIZE][GRID_SIZE]) {
    int x, y;
    printf("\nVotre tour! Entrez les coordonnees (x y) pour tirer: ");
    scanf("%d %d", &y, &x);

    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        printf("Coordonnees invalides. Reessayez.\n");
        playerTurn(grid);
        return;
    }

    if (grid[x][y] == 'S') {
        printf("Touche!\n");
        grid[x][y] = 'X'; // X represents a hit
    } else if (grid[x][y] == '~') {
        printf("A l'eau!\n");
        grid[x][y] = 'O'; // O represents a miss
    } else {
        printf("Vous avez deja tire ici. Reessayez.\n");
        playerTurn(grid);
    }
}

void computerTurn(char grid[GRID_SIZE][GRID_SIZE]) {
    int x, y;
    printf("\nTour de l'ordinateur...\n");

    do {
        x = rand() % GRID_SIZE;
        y = rand() % GRID_SIZE;
    } while (grid[x][y] == 'X' || grid[x][y] == 'O');

    if (grid[x][y] == 'S') {
        printf("L'ordinateur a touche un de vos navires en (%d, %d)!\n", x, y);
        grid[x][y] = 'X';
    } else {
        printf("L'ordinateur a tire en (%d, %d) et a manque.\n", x, y);
        grid[x][y] = 'O';
    }
}

int main() {
    char playerGrid[GRID_SIZE][GRID_SIZE];
    char computerGrid[GRID_SIZE][GRID_SIZE];

    initializeGrid(playerGrid);
    initializeGrid(computerGrid);

    printf("=== Bataille Navale ===\n\n");

    printf("Placement des navires du joueur...\n");
    placeShips(playerGrid, SHIP_COUNT);

    printf("Placement des navires de l'ordinateur...\n");
    placeShips(computerGrid, SHIP_COUNT);

    while (1) {
        printf("\nGrille de l'ordinateur :\n");
        printGrid(computerGrid, 0); // Do not reveal ships

        printf("\nVotre grille :\n");
        printGrid(playerGrid, 1); // Reveal ships

        playerTurn(computerGrid);
        if (isGameOver(computerGrid)) {
            printf("\nFelicitations, vous avez gagne!\n");
            break;
        }

        computerTurn(playerGrid);
        if (isGameOver(playerGrid)) {
            printf("\nDommage, l'ordinateur a gagne.\n");
            break;
        }
    }

    printf("\nFin du jeu. Merci d'avoir joue!\n");
    return 0;
}
