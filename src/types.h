#ifndef TYPES_H
#define TYPES_H

struct Pers;

typedef struct ListePers {
    struct Pers *pers;
    struct ListePers *suivant;
} ListePers;

typedef struct Date {
    int jour, mois, annee;
} Date;

typedef struct Pers {
    char nom[50];
    char prenom[50];
    Date naissance;
    Date deces;
    struct Pers *pere;
    struct Pers *mere;
    struct Pers *conjoint;
    struct ListePers *enfants;
    int vivant;
    int n, np, nm, nc;
} Pers;

#endif  // TYPES_H
