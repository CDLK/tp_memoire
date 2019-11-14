#include "matrice_lineaire.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
  if(l > 0 && c > 0){
    double *donnes = malloc(sizeof(double*)*l*c);
    matrice m = { l, c, donnes };
    return m;
  } else {
    matrice m = { -1, -1, NULL };
    return m;
  }
}

void liberer_matrice(matrice m) {
  free(m.donnees);
}

int est_matrice_invalide(matrice m) {
  return ((m.l == -1 && m.c == -1) ? 1 : 0);
}

double *acces_matrice(matrice m, int i, int j) {
  if(est_matrice_invalide(m)==0 && i < m.l && j < m.c){
    return &m.donnees[i*m.c+j];
  } else {
    return NULL;
  }
}

int nb_lignes_matrice(matrice m){
  return m.l;
}

int nb_colonnes_matrice(matrice m){
  return m.c;
}
