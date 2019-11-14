#include "vecteur.h"
#include <stdlib.h>
#include <stdio.h>

vecteur allouer_vecteur(int taille) {
  if(taille > 0){
    double * donnes = malloc(taille * sizeof(double));
    vecteur v = { taille, donnes };
    return v;
  } else {
    vecteur v = { -1, NULL };
    return v;
  }
}

void liberer_vecteur(vecteur v) {
  free(v.donnees);
}

int est_vecteur_invalide(vecteur v) {
    return (v.taille == -1 ? 1 : 0);
}

double *acces_vecteur(vecteur v, int i) {
    if(est_vecteur_invalide(v) == 0 && i < v.taille){
      return &v.donnees[i];
    } else {
      return NULL;
    }

}

int taille_vecteur(vecteur v) {
    return v.taille;
}
