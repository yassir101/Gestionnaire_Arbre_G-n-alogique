#include "famille.h"
#include "famille.c"
#include <stdio.h>
#include <stdlib.h>


int main()
{
  int choix;
  Personne *famille = NULL;

  do {
    printf("_______________Gestionnaire d'arbre genealogique_______________\n");
    printf("Choisissez une option :\n");

    printf("1. Ajouter une personne\n");
    printf("2. Marier deux personnes\n");
    printf("3. Ajouter un enfant\n");
    printf("4. Afficher la famille de haut en bas\n");
    printf("5. Sauvegarder la genealogie\n");
    printf("6. Charger une genealogie\n");
    printf("0. Quitter\n");
    scanf("%d", &choix);

    switch (choix) {
      case 0:
        break;
      case 1:
        ajouterPersonne(&famille);
        break;
      case 2:
        marier(&famille);
        break;
      case 3:
        ajouterEnfant(&famille);
        break;
      case 4:
        afficherFamille(&famille);
        break;
      case 5:
        sauvegarderGeneralogie(&famille, "generalogie.txt");
        break;
      case 6:
        chargerGeneralogie(&famille, "generalogie.txt");
        break;
      default:
        printf("Option invalide\n");
        break;
    }

    printf("Appuyez sur Entree pour continuer...");
    getchar();
    getchar();

    // Effacer l'écran
    system("cls");

  } while (choix != 0);
  libererMemoire(&famille);

  return 0;
}
