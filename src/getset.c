#include "types.h"
#include "getset.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

char* get_nom_pers(Pers *pers) {
    return pers->nom;
}

char* get_prenom_pers(Pers *pers) {
    return pers->prenom;
}

int get_jNaissance_pers(Pers *pers) {
    return pers->naissance.jour;
}

int get_mNaissance_pers(Pers *pers) {
    return pers->naissance.mois;
}

int get_aNaissance_pers(Pers *pers) {
    return pers->naissance.annee;
}

Date get_dateNaissance_pers(Pers *pers) {
    return pers->naissance;
}

int get_jDeces_pers(Pers *pers) {
    return pers->deces.jour;
}

int get_mDeces_pers(Pers *pers) {
    return pers->deces.mois;
}

int get_aDeces_pers(Pers *pers) {
    return pers->deces.annee;
}

int get_jour_date(Date date) {
    return date.jour;
}

int get_mois_date(Date date) {
    return date.mois;
}

int get_annee_date(Date date) {
    return date.annee;
}

Pers* get_pere_pers(Pers *pers) {
    return pers->pere;
}

Pers* get_mere_pers(Pers *pers) {
    return pers->mere;
}

int get_nbEnfants_pers(Pers *pers) {
    return pers->n;
}

Pers* get_iemeEnfant_pers(Pers *pers, int i) {
    ListePers* listeEnfants = pers->enfants;

    while (listeEnfants != NULL && i > 0) {
        listeEnfants = listeEnfants->suivant;
        i--;
    }

    if (listeEnfants != NULL) {
        return listeEnfants->pers;
    }

    return NULL;
}

ListePers* get_enfants_pers(Pers *pers) {
    return pers->enfants;
}

int get_vivant_pers(Pers *pers) {
    return pers->vivant;
}

Pers* get_pers_liste(ListePers *arbre) {
    return arbre->pers;
}

ListePers* get_suiv_liste(ListePers *arbre) {
    return arbre->suivant;
}

int get_n_pers(Pers *pers) {
    return pers->n;
}

int get_np_pers(Pers *pers) {
    return pers->np;
}

int get_nm_pers(Pers *pers) {
    return pers->nm;
}

int get_nc_pers(Pers *pers) {
    return pers->nc;
}

void set_nom_pers(Pers *pers, const char *nom) {
    strncpy(pers->nom, nom, sizeof(pers->nom) - 1);
    pers->nom[sizeof(pers->nom) - 1] = '\0';
}

void set_prenom_pers(Pers *pers, const char *prenom) {
    strncpy(pers->prenom, prenom, sizeof(pers->prenom) - 1);
    pers->prenom[sizeof(pers->prenom) - 1] = '\0';
}

void set_jNaissance_pers(Pers *pers, int jour) {
    pers->naissance.jour = jour;
}

void set_mNaissance_pers(Pers *pers, int mois) {
    pers->naissance.mois = mois;
}

void set_aNaissance_pers(Pers *pers, int annee) {
    pers->naissance.annee = annee;
}

void set_dateNaissance_pers(Pers *pers, Date date) {
    pers->naissance = date;
}

void set_jDeces_pers(Pers *pers, int jour) {
    pers->deces.jour = jour;
}

void set_mDeces_pers(Pers *pers, int mois) {
    pers->deces.mois = mois;
}

void set_aDeces_pers(Pers *pers, int annee) {
    pers->deces.annee = annee;
}

void set_pere_pers(Pers *pers, Pers *pere) {
    pers->pere = pere;
}

void set_mere_pers(Pers *pers, Pers *mere) {
    pers->mere = mere;
}

void set_nbEnfants_pers(Pers *pers, int nbEnfants) {
    pers->n = nbEnfants;
}

void set_iemeEnfant_pers(Pers *pers, int i, Pers *enfant) {
    if (i >= 0) {
        ListePers *nouveauMaillon = listeVide();
        nouveauMaillon->pers = enfant;

        if (i == 0) {
            nouveauMaillon->suivant = pers->enfants;
            pers->enfants = nouveauMaillon;
        } else {
            ListePers *precedent = pers->enfants;
            while (precedent != NULL && i > 1) {
                precedent = precedent->suivant;
                i--;
            }

            if (precedent != NULL) {
                nouveauMaillon->suivant = precedent->suivant;
                precedent->suivant = nouveauMaillon;
            } else {
                free(nouveauMaillon);
            }
        }
    }
}

void set_enfants_pers(Pers *pers, ListePers *enfants) {
    pers->enfants = enfants;
}

void set_vivant_pers(Pers *pers, int vivant) {
    pers->vivant = vivant;
}

void set_pers_liste(ListePers *arbre, Pers *pers) {
    arbre->pers = pers;
}

void set_suiv_liste(ListePers *arbre, ListePers *suivant) {
    arbre->suivant = suivant;
}

void set_n_pers(Pers *pers, int n) {
    pers->n = n;
}

void set_np_pers(Pers *pers, int np) {
    pers->np = np;
}

void set_nm_pers(Pers *pers, int nm) {
    pers->nm = nm;
}

void set_nc_pers(Pers *pers, int nc) {
    pers->nc = nc;
}

Pers* personneVide() {
    Pers* nouvellePersonne = (Pers*)malloc(sizeof(Pers));
    if (nouvellePersonne != NULL) {
        memset(nouvellePersonne, 0, sizeof(Pers));
        nouvellePersonne->enfants = NULL;
    }
    return nouvellePersonne;
}

ListePers* listeVide() {
    ListePers* nouvelleListe = (ListePers*)malloc(sizeof(ListePers));
    if (nouvelleListe != NULL) {
        memset(nouvelleListe, 0, sizeof(ListePers));
    }
    return nouvelleListe;
}

ListePers* sup_maillon_liste(ListePers* arbre, Pers* intru) {
    if (arbre == NULL) {
        return NULL;
    }

    ListePers* courant = arbre;
    ListePers* precedent = NULL;

    while (courant != NULL && courant->pers != intru) {
        precedent = courant;
        courant = courant->suivant;
    }

    if (courant == NULL) {
        return arbre;
    }

    if (precedent == NULL) {
        arbre = courant->suivant;
    } else {
        precedent->suivant = courant->suivant;
    }

    free(courant);
    return arbre;
}

ListePers* fusion_listes_sansDouble(ListePers* l1, ListePers* l2) {
    if (l1 == NULL) {
        return l2;
    }

    ListePers* courant = l1;

    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }

    courant->suivant = l2;

    return l1;
}

ListePers* fix_maillon_liste(ListePers* arbre) {
    ListePers* temp = arbre;
    ListePers* suivant = NULL;

    while (temp != NULL) {
        suivant = temp->suivant;
        free(temp);
        temp = suivant;
    }

    return NULL;
}

ListePers* fix_pers_liste_creer(ListePers* arbre, Pers* pers) {
    ListePers* nouveauMaillon = (ListePers*)malloc(sizeof(ListePers));
    if (nouveauMaillon == NULL) {
        perror("Erreur");
        exit(EXIT_FAILURE);
    }

    nouveauMaillon->pers = pers;
    nouveauMaillon->suivant = arbre;

    return nouveauMaillon;
}






