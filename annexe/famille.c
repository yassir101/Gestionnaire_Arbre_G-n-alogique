#include "famille.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition des fonctions
void sauvegarderGeneralogie(Personne **famille, const char *nomFichier)
{
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", nomFichier);
        return;
    }

    Personne *actuel = *famille;
    while (actuel != NULL) {
        fprintf(fichier, "Nom: %s, Prenom: %s, Age: %d\n", actuel->nom, actuel->prenom, actuel->age);

        if (actuel->conjoint != NULL) {
            fprintf(fichier, "Conjoint: %s %s, Age: %d\n", actuel->conjoint->nom, actuel->conjoint->prenom, actuel->conjoint->age);
        } else {
            fprintf(fichier, "Conjoint: NULL\n");
        }

        if (actuel->enfant != NULL) {
            fprintf(fichier, "Enfants:\n");
            Personne *enfantActuel = actuel->enfant;
            while (enfantActuel != NULL) {
                fprintf(fichier, "- Nom: %s, Prenom: %s\n", enfantActuel->nom, enfantActuel->prenom);
                enfantActuel = enfantActuel->enfant;
            }
        } else {
            fprintf(fichier, "Enfants: NULL\n");
        }

        actuel = actuel->enfant;
    }

    fclose(fichier);
    printf("La genealogie a ete sauvegardee dans %s\n", nomFichier);
}


void chargerGeneralogie(Personne ** famille, const char *nomFichier)
{
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
    printf("Impossible d'ouvrir le fichier %s\n", nomFichier);
    return;
    }

    libererMemoire(famille);

    char nom[MAX_NAME_LENGTH];
    char prenom[MAX_NAME_LENGTH];
    int age;
    char nomConjoint[MAX_NAME_LENGTH];
    char prenomConjoint[MAX_NAME_LENGTH];
    int ageConjoint;

    while (fscanf(fichier, "%s %s %d", nom, prenom, &age) == 2) {
    Personne *nouvellePersonne = (Personne *) malloc(sizeof(Personne));
    strcpy(nouvellePersonne->nom, nom);
    strcpy(nouvellePersonne->prenom, prenom);
    nouvellePersonne->age = age;

    fscanf(fichier, "%s %s %d", nomConjoint, prenomConjoint, &ageConjoint);
    if (strcmp(nomConjoint, "NULL") == 0) {
      nouvellePersonne->conjoint = NULL;
    } else {
      Personne *conjoint = (Personne *) malloc(sizeof(Personne));
      strcpy(conjoint->nom, nomConjoint);
      strcpy(conjoint->prenom, prenomConjoint);
      nouvellePersonne->age = ageConjoint;
      conjoint->conjoint = nouvellePersonne;
      conjoint->enfant = NULL;
      nouvellePersonne->conjoint = conjoint;
    }

    nouvellePersonne->enfant = *famille;
    *famille = nouvellePersonne;
    }

    fclose(fichier);
    printf("La genealogie a ete chargee depuis %s\n", nomFichier);
}

void libererMemoire(Personne ** famille)
{
  Personne *actuel = *famille;
  while (actuel != NULL) {
    Personne *personneSuivante = actuel->enfant;

    free(actuel);

    actuel = personneSuivante;
  }

  *famille = NULL;
}

void ajouterPersonne(Personne **famille)
{
    char nom[MAX_NAME_LENGTH];
    char prenom[MAX_NAME_LENGTH];
    int age;

    getchar();

    printf("Entrez le nom de famille de la personne :\n");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';

    printf("Entrez le prenom de la personne :\n");
    fgets(prenom, sizeof(prenom), stdin);
    prenom[strcspn(prenom, "\n")] = '\0';

    // Verifier si le nom est dejà pris
    if (*famille != NULL) {
    Personne *current = *famille;
    while (current != NULL) {
      if (strcmp(current->nom, nom) == 0 && strcmp(current->prenom, prenom) == 0) {
        printf("Le nom est dejà pris\n");
        return;
      }
      current = current->enfant;
    }
    }

    printf("Entrez l'age de la personne :\n");
    scanf("%d", &age);

    // Creer une nouvelle personne
    Personne *nouvellePersonne = (Personne *)malloc(sizeof(Personne));
    strcpy(nouvellePersonne->nom, nom);
    strcpy(nouvellePersonne->prenom, prenom);
    nouvellePersonne->age = age;
    nouvellePersonne->conjoint = NULL;
    nouvellePersonne->enfant = NULL;

    // Ajouter la nouvelle personne a la famille
    if (*famille == NULL) {
    *famille = nouvellePersonne;
    } else {
    Personne *current = *famille;
    while (current->enfant != NULL) {
      current = current->enfant;
    }
    current->enfant = nouvellePersonne;
    }

    // Demander si la personne doit être declaree comme chef de famille
    char choix;
    printf("Voulez-vous declarer %s %s comme chef de famille ? (o/n)\n", nom, prenom);
    scanf(" %c", &choix);
    if (choix == 'o' || choix == 'O') {
    *famille = nouvellePersonne;
    printf("%s est maintenant le chef de famille\n", nom);
    }
}

void marier(Personne **famille)
{
    char nom1[MAX_NAME_LENGTH], prenom1[MAX_NAME_LENGTH], nom2[MAX_NAME_LENGTH], prenom2[MAX_NAME_LENGTH];
    printf("Entrez le prenom de la premiere personne :\n");
    scanf("%s", prenom1);
    getchar();

    printf("Entrez le nom de famille de la premiere personne :\n");
    scanf("%s", nom1);
    getchar();

    printf("Entrez le prenom de la deuxieme personne :\n");
    scanf("%s", prenom2);
    getchar();

    printf("Entrez le nom de famille de la deuxieme personne :\n");
    scanf("%s", nom2);
    getchar();

    // Trouver la premiere personne
    Personne *personne1 = *famille;
    while (personne1 != NULL && (strcmp(personne1->nom, nom1) != 0 || strcmp(personne1->prenom, prenom1) != 0))
    personne1 = personne1->enfant;

    // Trouver la deuxieme personne
    Personne *personne2 = *famille;
    while (personne2 != NULL && (strcmp(personne2->nom, nom2) != 0 || strcmp(personne2->prenom, prenom2) != 0))
    personne2 = personne2->enfant;

    // Verifier si les deux personnes ont ete trouvees
    if (personne1 == NULL || personne2 == NULL) {
    printf("L'une des personnes n'existe pas\n");
    return;
    }
    // Verifier si l'une d'entre elles est deja mariee
    if (personne1->conjoint != NULL || personne2->conjoint != NULL) {
    printf("Mariage invalide\n");
    return;
    }
    // Trouver le chef commun
    Personne *chefCommun = *famille;
    while (chefCommun != NULL && chefCommun->enfant != personne1 && chefCommun->enfant != personne2)
    chefCommun = chefCommun->enfant;

    if (chefCommun == NULL) {
    printf("Mariage invalide\n");
    return;
    }
    // Verifier si l'un d'entre eux est age de moins de 18 ans
    if (personne1->age < 18 || personne2->age < 18) {
    printf("Mariae invalide\n");
    return;
    }

    // Mettre a jour les pointeurs conjoint
    personne1->conjoint = personne2;
    personne2->conjoint = personne1;

    printf("%s %s et %s %s sont maintenant maries\n", prenom1, nom1, prenom2, nom2);
}

void ajouterEnfant(Personne **famille)
{
    getchar();
    char nomPere[MAX_NAME_LENGTH], prenomPere[MAX_NAME_LENGTH];
    char nomMere[MAX_NAME_LENGTH], prenomMere[MAX_NAME_LENGTH];
    char prenomEnfant[MAX_NAME_LENGTH];
    int ageEnfant;

    printf("Entrez le prenom du pere :\n");
    fgets(prenomPere, sizeof(prenomPere), stdin);
    prenomPere[strcspn(prenomPere, "\n")] = '\0';

    printf("Entrez le nom du pere :\n");
    fgets(nomPere, sizeof(nomPere), stdin);
    nomPere[strcspn(nomPere, "\n")] = '\0';

    printf("Entrez le prenom de la mere :\n");
    fgets(prenomMere, sizeof(prenomMere), stdin);
    prenomMere[strcspn(prenomMere, "\n")] = '\0';

    printf("Entrez le nom de la mere :\n");
    fgets(nomMere, sizeof(nomMere), stdin);
    nomMere[strcspn(nomMere, "\n")] = '\0';

    printf("Entrez le prenom de l'enfant :\n");
    fgets(prenomEnfant, sizeof(prenomEnfant), stdin);
    prenomEnfant[strcspn(prenomEnfant, "\n")] = '\0';

    printf("Entrez l'age de l'enfant :\n");
    scanf("%d", &ageEnfant);
    getchar();  // Pour consommer le caractère de nouvelle ligne restant dans le flux d'entree

    // Trouver le père
    Personne *pere = *famille;
    while (pere != NULL && (strcmp(pere->nom, nomPere) != 0 || strcmp(pere->prenom, prenomPere) != 0))
        pere = pere->enfant;

    // Trouver la mère
    Personne *mere = *famille;
    while (mere != NULL && (strcmp(mere->nom, nomMere) != 0 || strcmp(mere->prenom, prenomMere) != 0))
        mere = mere->enfant;

    // Verifier si les deux parents ont ete trouves
    if (pere == NULL || mere == NULL) {
        printf("L'un des parents n'existe pas\n");
        return;
    }

    // Creer un nouvel enfant
    Personne *nouvelEnfant = (Personne *)malloc(sizeof(Personne));
    strcpy(nouvelEnfant->nom, nomPere);  // Le nom de famille de l'enfant est celui du père
    strcpy(nouvelEnfant->prenom, prenomEnfant);
    nouvelEnfant->age = ageEnfant;
    nouvelEnfant->conjoint = NULL;
    nouvelEnfant->enfant = NULL;

    // Ajouter l'enfant aux parents
    nouvelEnfant->parent = pere;
    nouvelEnfant->enfant = pere->enfant;
    pere->enfant = nouvelEnfant;

    nouvelEnfant->parent = mere;
    nouvelEnfant->enfant = mere->enfant;
    mere->enfant = nouvelEnfant;

    printf("%s est l'enfant de %s %s et %s %s\n", prenomEnfant, prenomPere, nomPere, prenomMere, nomMere);
}

void afficherFamille(Personne **famille)
{
    char nom[MAX_NAME_LENGTH], prenom[MAX_NAME_LENGTH];

    printf("Entrez le prenom de la personne :\n");
    scanf("%s", prenom);
    getchar();

    printf("Entrez le nom de famille de la personne :\n");
    scanf("%s", nom);
    getchar();

    // Recherche de la personne dans la famille
    Personne *actuel = *famille;
    while (actuel != NULL && (strcmp(actuel->nom, nom) != 0 || strcmp(actuel->prenom, prenom) != 0)) {
        actuel = actuel->enfant;
    }

    if (actuel == NULL) {
        printf("La personne n'existe pas dans la famille\n");
        return;
    }

    // Affichage des informations de la personne et sa famille
    printf("Nom: %s, Prenom: %s, Age: %d\n", actuel->nom, actuel->prenom, actuel->age);

    if (actuel->conjoint != NULL) {
        printf("Conjoint: %s %s, Age: %d\n", actuel->conjoint->prenom, actuel->conjoint->nom, actuel->conjoint->age);
    }

    if (actuel->enfant != NULL) {
        printf("Enfants:\n");
        Personne *enfantActuel = actuel->enfant;
        while (enfantActuel != NULL) {
            printf("- %s %s, Age: %d \n", enfantActuel->prenom, enfantActuel->nom, enfantActuel->age);
            enfantActuel = enfantActuel->enfant;
        }
    }
}
