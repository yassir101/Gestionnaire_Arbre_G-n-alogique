#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion.h"

Pers* creerPers() {
    Pers* nouvellePersonne = (Pers*)malloc(sizeof(Pers));
    if (nouvellePersonne != NULL) {
        strcpy(nouvellePersonne->nom, "");
        strcpy(nouvellePersonne->prenom, "");
        nouvellePersonne->naissance.jour = 0;
        nouvellePersonne->naissance.mois = 0;
        nouvellePersonne->naissance.annee = 0;
        nouvellePersonne->deces.jour = 0;
        nouvellePersonne->deces.mois = 0;
        nouvellePersonne->deces.annee = 0;
        nouvellePersonne->pere = NULL;
        nouvellePersonne->mere = NULL;
        nouvellePersonne->conjoint = NULL;
        nouvellePersonne->enfants = NULL;
        nouvellePersonne->vivant = 1;
        nouvellePersonne->n = 0;
        nouvellePersonne->np = 0;
        nouvellePersonne->nm = 0;
        nouvellePersonne->nc = 0;
    }
    return nouvellePersonne;
}

ListePers* ajouterPersonne(ListePers* arbre) {
    Pers* nouvellePersonne = creerPers();

    if (nouvellePersonne != NULL) {
        ListePers* nouveauMaillon = (ListePers*)malloc(sizeof(ListePers));

        if (nouveauMaillon != NULL) {
            nouveauMaillon->pers = nouvellePersonne;
            nouveauMaillon->suivant = arbre;
            arbre = nouveauMaillon;
        } else {
            free(nouvellePersonne);
            printf("Erreur d'allocation mémoire pour le maillon.\n");
        }
    } else {
        printf("Erreur de création de la nouvelle personne.\n");
    }

    return arbre;
}



void supprimerFiliationPers(Pers* pers){
    if (pers->pere != NULL) {
        ListePers* enfantsPere = pers->pere->enfants;
        ListePers* maillonEnfant = enfantsPere;
        ListePers* maillonPrecedent = NULL;

        while (maillonEnfant != NULL && maillonEnfant->pers != pers) {
            maillonPrecedent = maillonEnfant;
            maillonEnfant = maillonEnfant->suivant;
        }

        if (maillonEnfant != NULL) {
            if (maillonPrecedent != NULL) {
                maillonPrecedent->suivant = maillonEnfant->suivant;
            } else {
                pers->pere->enfants = maillonEnfant->suivant;
            }
            free(maillonEnfant);
        }
        pers->pere = NULL;
    }

    if (pers->mere != NULL) {
        ListePers* enfantsMere = pers->mere->enfants;
        ListePers* maillonEnfant = enfantsMere;
        ListePers* maillonPrecedent = NULL;

        while (maillonEnfant != NULL && maillonEnfant->pers != pers) {
            maillonPrecedent = maillonEnfant;
            maillonEnfant = maillonEnfant->suivant;
        }

        if (maillonEnfant != NULL) {
            if (maillonPrecedent != NULL) {
                maillonPrecedent->suivant = maillonEnfant->suivant;
            } else {
                pers->mere->enfants = maillonEnfant->suivant;
            }
            free(maillonEnfant);
        }
        pers->mere = NULL;
    }

    if (pers->enfants != NULL) {
        ListePers* maillonEnfant = pers->enfants;

        while (maillonEnfant != NULL) {
            maillonEnfant->pers->pere = NULL;
            maillonEnfant->pers->mere = NULL;

            ListePers* maillonSuivant = maillonEnfant->suivant;
            free(maillonEnfant);
            maillonEnfant = maillonSuivant;
        }
        pers->enfants = NULL;
    }
}

ListePers* supprimerPers(ListePers* arbre)
{
    if (arbre != NULL) {
        Pers* personneASupprimer = arbre->pers;
        supprimerFiliationPers(personneASupprimer);
        free(personneASupprimer);
        ListePers* maillonASupprimer = arbre;
        arbre = arbre->suivant;
        free(maillonASupprimer);
    }
    return arbre;
}


ListePers* viderArbre(ListePers* arbre) {
    while (arbre != NULL) {
        arbre = supprimerPers(arbre);
    }
    return arbre;
}
