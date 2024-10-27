#include <stdio.h>
#include <stdlib.h>
#include "getset.h"
#include "files.h"
#include "menus.c"
#include "trouver_pers.h"
#include "gestion.h"

int main() {
    ListePers* arbre = NULL;

    int choix;

    do {
        arbre = menuPrincipal(arbre);
        printf("\nAppuyez sur Entrée pour revenir au menu principal...");
        getchar();

        clearScreen();

    } while (1);

    arbre = viderArbre(arbre);

    return 0;
}
