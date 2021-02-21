#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct listeChainee{
  int data;
  struct listeChainee *suc;
  struct listeChainee *prec;
}Liste;

void Echange(Liste *L1, Liste *L2){
  int d;
  d=L1->data;
  L1->data=L2->data;
  L2->data=d;
}

Liste *iMin(Liste *L){
  Liste *lMin=L->suc;
  while (L!=NULL){
    if (L->data<lMin->data){
      lMin=L;
    }
    L=L->suc;
  }
  return lMin;
}

Liste *Creation(int taille){
  Liste *L0, *TMP;
  srand(time(NULL));
  TMP=L0=(Liste *)malloc(sizeof(Liste));
  L0->prec=NULL;
  L0->data=rand();
  while (--taille){
    TMP->suc=(Liste *)malloc(sizeof(Liste));
    TMP->suc->prec=TMP;
    TMP=TMP->suc;
    TMP->data=rand();
  }
  TMP->suc=NULL;
  return L0;
}

void Affichage(Liste *L){
  int i=1;
  while (L!=NULL){
    printf("Valeur du maillon %d : %d\n", i, L->data);
    L=L->suc;
    i+=1;
  }
}

Liste *Insertion(Liste *L, Liste *M, int pos){
  Liste *TMP=L;
  if (TMP==NULL || M==NULL) return NULL;
  if (pos==1){
    M->prec=NULL;
    M->suc=L;
    TMP->prec=M;
    return M;
  }

  for (int i=0;i<pos-1;i++){
    TMP=TMP->suc;
  }
  if (!TMP->suc){
    M->suc=NULL;
    TMP->suc=M;
    M->prec=TMP;
    return L;
  }
  M->prec=TMP->prec;
  M->suc=TMP;
  TMP->prec->suc=M;
  TMP->prec=M;
  return L;
}

Liste *Suppression(Liste *L, int pos){
  Liste *TMP=L;
  if (TMP==NULL) return NULL;
  for (int i=0;i<pos-1;i++){
    TMP=TMP->suc;
  }
  if (TMP->suc && TMP->prec){
    TMP->prec->suc=TMP->suc;
    TMP->suc->prec=TMP->prec;
  }else if (!TMP->suc){
    TMP->prec->suc=NULL;
  }else if (!TMP->prec){
    TMP=TMP->suc;
    free(TMP->prec);
    TMP->prec=NULL;
    return TMP;
  }
  free(TMP);
  return L;
}

int main(int argc, char *argv[]){
  Liste *L, *val;
  int size, choix, pos, pos1, pos2;
  val=(Liste *)malloc(sizeof(Liste));
  printf("taille de la liste a créer\n");
  scanf("%d", &size);
  L=Creation(size);
  Affichage(L);
  while (1){
    printf("Que voulez-vous faire ?\n");
    printf("Fonction Insertion : 1\n");
    printf("Fonction Suppression : 2\n");
    printf("Affichage liste : 3\n");
    printf("Quitter : 4\n");
    scanf("%d", &choix);
    switch (choix){
      case 1:
        printf("valeur à ajouter :\n");
        scanf("%d", &val->data);
        printf("position où ajouter cette valeur :\n");
        scanf("%d", &pos);
        L=Insertion(L, val, pos);
        printf("réussi\n");
        break;
      case 2:
        printf("position du maillon à supprimer :\n");
        scanf("%d", &pos);
        L=Suppression(L, pos);
        printf("réussi\n");
        break;
      case 3:
        Affichage(L);
        printf("\n");
        break;
      case 4:
        printf("terminé\n");
        return 0;
    }
  }
}