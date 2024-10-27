#include "trouver_pers.h"
#include <stdio.h>
#include <stdlib.h>

int get_nbJours_mois(int m) {
    switch (m) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 28;
        default:
            return 31;
    }
}

int estBisextile(int a) {
    return (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
}

int estUneDate(Date date) {
    if (date.annee < 0) {
        return 0;
    }
    if (date.mois < 1 || date.mois > 12) {
        return 0;
    }
    if (date.jour < 1 || date.jour > get_nbJours_mois(date.mois)) {
        return 0;
    }
    return 1;
}

Date demanderDate() {
    Date date;
    printf("Saisissez une date avec des espaces entre (jour mois annee): \n");
    scanf("%d %d %d", &date.jour, &date.mois, &date.annee);
    while (!estUneDate(date)) {
        printf("Date invalide. Reeassayez: \n");
        scanf("%d %d %d", &date.jour, &date.mois, &date.annee);
    }
    return date;
}

Pers* trouverPers(ListePers* arbre) {
    Date dateRecherche = demanderDate();

    while (arbre != NULL) {
        if (estUneDate(arbre->pers->naissance) &&
            arbre->pers->naissance.jour == dateRecherche.jour &&
            arbre->pers->naissance.mois == dateRecherche.mois &&
            arbre->pers->naissance.annee == dateRecherche.annee) {
            return arbre->pers;
        }
        arbre = arbre->suivant;
    }
    return NULL;
}
