#include "determiner_lien.h"
#include <stdlib.h>
#include <string.h>

static char* obtenirLien(Pers* ancetre, Pers* personne) {
    if (ancetre == personne) {
        return "Personne selectionnee";
    } else if (ancetre->conjoint == personne) {
        return "Conjoint(e)";
    } else if (ancetre->pere == personne) {
        return "Pere";
    } else if (ancetre->mere == personne) {
        return "Mere";
    } else {
        return "Pas de lien";
    }
}

char* determinerLien(ListePers* arbre, Pers* pers1, Pers* pers2) {
    char* lien = "Inconnu";

    while (arbre != NULL) {
        if (arbre->pers == pers1 || arbre->pers == pers2) {
            lien = obtenirLien(arbre->pers, (arbre->pers == pers1) ? pers2 : pers1);
            break;
        }
        arbre = arbre->suivant;
    }

    return lien;
}
