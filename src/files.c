#include "files.h"
#include <stdio.h>
#include <stdlib.h>

char* saisirNomFichier() {
    char* nomFichier = (char*)malloc(50 * sizeof(char));
    printf("Saisissez le nom du fichier: \n");
    scanf("%s", nomFichier);
    return nomFichier;
}

ListePers* numero(ListePers* arbre) {
    int n = 1;
    ListePers* temp = arbre;

    while (temp != NULL) {
        temp->pers->n = n++;
        temp = temp->suivant;
    }

    return arbre;
}

void sauvegarderArbreFichier(ListePers* arbre, char* nomFich) {
    FILE* fichier = fopen(nomFich, "w");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }

    while (arbre != NULL) {
        fprintf(fichier, "%s;%s;%d/%d/%d;%d/%d/%d;%s;%s;%s\n", arbre->pers->nom, arbre->pers->prenom,
                arbre->pers->naissance.jour, arbre->pers->naissance.mois, arbre->pers->naissance.annee,
                arbre->pers->deces.jour, arbre->pers->deces.mois, arbre->pers->deces.annee,
                (arbre->pers->pere != NULL) ? arbre->pers->pere->nom : "",
                (arbre->pers->mere != NULL) ? arbre->pers->mere->nom : "",
                (arbre->pers->conjoint != NULL) ? arbre->pers->conjoint->nom : "");

        arbre = arbre->suivant;
    }

    fclose(fichier);
}

Pers* retrouverPersavecNumero(ListePers* arbre, int n) {
    while (arbre != NULL) {
        if (arbre->pers->n == n) {
            return arbre->pers;
        }
        arbre = arbre->suivant;
    }
    return NULL;
}

ListePers* retrouverLiens(ListePers* arbre) {
    while (arbre != NULL) {
        arbre->pers->pere = retrouverPersavecNumero(arbre, arbre->pers->np);
        arbre->pers->mere = retrouverPersavecNumero(arbre, arbre->pers->nm);
        arbre->pers->conjoint = retrouverPersavecNumero(arbre, arbre->pers->nc);

        arbre = arbre->suivant;
    }

    return arbre;
}

ListePers* chargerArbre(char* nomFich) {
    FILE* fichier = fopen(nomFich, "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier \n");
        exit(EXIT_FAILURE);
    }

    ListePers* arbre = NULL;
    Pers personne;

    while (fscanf(fichier, "%49[^;];%49[^;];%d/%d/%d;%d/%d/%d;%d;%d;%d;%49[^;];%49[^;];%49[^;\n]\n",
                  personne.nom, personne.prenom,
                  &personne.naissance.jour, &personne.naissance.mois, &personne.naissance.annee,
                  &personne.deces.jour, &personne.deces.mois, &personne.deces.annee,
                  &personne.n, &personne.np, &personne.nm,
                  personne.pere->nom, personne.mere->nom, personne.conjoint->nom) != EOF) {

        personne.pere = NULL;
        personne.mere = NULL;
        personne.conjoint = NULL;

        arbre = fix_pers_liste_creer(arbre, &personne);
    }

    fclose(fichier);
    return arbre;
}
