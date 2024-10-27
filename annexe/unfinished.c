#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Personne {
    char nom[MAX_NAME_LENGTH];
    char prenom[MAX_NAME_LENGTH];
    int age;
    struct Personne *conjoint;
    struct Personne *enfant;
    struct Personne *parent;
    struct Personne *frereSoeur;
    struct Personne *grandParent;
} Personne;

void ajouterFrereSoeur(Personne *personne, Personne *frereSoeur) {
    if (personne == NULL || frereSoeur == NULL) {
        return;
    }

    while (personne->frereSoeur != NULL) {
        personne = personne->frereSoeur;
    }

    personne->frereSoeur = frereSoeur;
}

void ajouterGrandParent(Personne *personne, Personne *grandParent) {
    if (personne == NULL || grandParent == NULL) {
        return;
    }

    if (personne->parent != NULL) {
        personne->parent->parent = grandParent;
    }
}

void supprimerPersonne(Personne **famille, Personne *personneASupprimer) {
    if (*famille == NULL || personneASupprimer == NULL) {
        return;
    }

    Personne *actuel = *famille;
    Personne *precedent = NULL;

    while (actuel != NULL && actuel != personneASupprimer) {
        precedent = actuel;
        actuel = actuel->enfant;
    }

    if (actuel == NULL) {
        return;
    }

    if (precedent == NULL) {
        *famille = actuel->enfant;
    } else {
        precedent->enfant = actuel->enfant;
    }

    free(actuel);
}

typedef struct Relation {
    enum {
        PARENT_ENFANT,
        FRERE_SOEUR,
        EPOUX_EPOUSE,
        AUTRE
    } type;
    Personne *personne1;
    Personne *personne2;
} Relation;

void afficherRelation(Relation relation) {
    switch (relation.type) {
        case PARENT_ENFANT:
            printf("%s %s est parent de %s %s\n", relation.personne1->prenom, relation.personne1->nom,
                   relation.personne2->prenom, relation.personne2->nom);
            break;
        case FRERE_SOEUR:
            printf("%s %s est frere/soeur de %s %s\n", relation.personne1->prenom, relation.personne1->nom,
                   relation.personne2->prenom, relation.personne2->nom);
            break;
        case EPOUX_EPOUSE:
            printf("%s %s est mari(e) avec %s %s\n", relation.personne1->prenom, relation.personne1->nom,
                   relation.personne2->prenom, relation.personne2->nom);
            break;
        case AUTRE:
            printf("Autre relation entre %s %s et %s %s\n", relation.personne1->prenom, relation.personne1->nom,
                   relation.personne2->prenom, relation.personne2->nom);
            break;
        default:
            printf("Type de relation inconnu\n");
    }
}

