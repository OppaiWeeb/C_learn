// déclaration des fonctions externes
#include <stdio.h> // nécessaire pour printf
#include <stdlib.h> // nécessaire pour malloc, free, et strtol
#include <math.h> // nécessaire pour NAN

// DEFINITION D'UN TYPE BOOLEEN : un unsigned char qui encode Vrai par 1 et Faux par 0
typedef unsigned char Booleen; // après cette ligne Booleen est un nouveau type équivalent
                               // à unsigned char
Booleen Vrai=1; // Encodage de Vrai par 1
Booleen Faux=0; // Encodage de Faux par 0
Booleen Non(Booleen b) // fonction NOT (utilisée dans EstDans())
{
  return b==Vrai ? Faux : Vrai; // Note: emploi de l'opérateur ternaire
                                // x ? y : z <=> si x alors y sinon z
}

// DEFINITION D'UN TYPE ELEMENT : un float
typedef float Element; // après cette ligne Element est un nouveau type équivalent à float
Element element_invalide=NAN; // Encodage de l'element_invalide par NAN=Not a Number (voir math.h)
Booleen EstInvalide(Element E)
{
   return isnan(E);
}

void AfficherElement(Element E)
{
  if (EstInvalide(E))
    printf("INVALID\n");
  else
    printf("%f\n", E);
}

// DEFINITION DES SORTES POUR LA LISTE CHAINEE
// La cellule
struct Cellule
{
  Element data;
  struct Cellule *next;
};
typedef struct Cellule Cellule;

// la liste
typedef Cellule *Liste;
Liste liste_vide=(Liste)NULL;

// OPERATIONS SUR LA SORTE (A COMPLETER)
int CreerInt(char c)
{
  return (int)c;
}

Liste Creer(Element E, Liste L)
{
  if (EstInvalide(E)) return liste_vide;

  Liste ret=malloc(sizeof(Cellule)); // allocation de la mémoire pour stocker une cellule (Liste=Cellule*)
  ret->data = E;  // rappel: le type Liste est un pointeur, donc ret->data <=> (*ret).data
  ret->next = L;  // idem que pour data
  return ret;
}

Booleen EstVide(Liste L)
{
  if (L == liste_vide) return Vrai;

  return Faux; // le else est inutile car le if provoque un return.
               // Ce genre de code, même s'il est moins clair qu'un else, permet d'aider le
               // compilateur à vérifier qu'il y a systématiquement un return dans la fonction
}

Element Contenu(Liste L)
{
  if (EstVide(L)) return element_invalide;

  return L->data;
}

Liste Succ(Liste L)
{
  if (EstVide(L)) return liste_vide;
  return L->next;
}

Liste Detruire(Liste L)
{
  if (EstVide(L)) return liste_vide;
  Liste tmpL; // tmpL: Liste
  tmpL=Succ(L); // tmpL <- Succ(L)  // stockage de la suite de la liste, qui sera renvoyée par la fonction
  free(L);
  return tmpL;
}