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

// FONCTIONS VUES EN TD
void Afficher(Liste L){
  Liste tmpL=L;
  while (EstVide(tmpL) == Faux){
    AfficherElement(Contenu(tmpL));
    tmpL=Succ(tmpL);
  }
}

unsigned int Longueur(Liste L){
  Liste tmpL=L;
  int n=0;
  while (EstVide(tmpL) == Faux){ //Tant que tmpL n'est pas vide on incrémente un compteur
    n+=1;
    tmpL=Succ(tmpL);
  }
  return n;
}

Liste Rechercher(Liste L, Element E){
  Liste tmpL=L;
  while (EstVide(tmpL) == Faux && Contenu(tmpL) != E){ //On regarde chaque cellule et on arrête quand on l'a trouvée ou quand on l'a parcouru entièrement
    tmpL=Succ(tmpL);
  }
  return tmpL;
}

Booleen EstDans(Liste L, Element E){
  return Non(EstVide(Rechercher(L,E)));
}

Liste Supprimer(Liste L, int r){
  /* si la liste est vide ou qu'on lui retire le 1er element la liste renvoyée sera vide*/
  if (r == 0 || EstVide(L) == Vrai){
    return Detruire(L);
  }
  /* Sinon, recherche de la cellule précédent celle que l'on doit supprimer*/
  int i=0;
  Liste tmpL=L;
  /* si tmpL est une liste_vide dans ce cas Succ renvoie liste_vide, 
  donc rien n'est fait par le Tant que et pour la mise à jour de Succ, L est alors une liste vide*/
  while (EstVide(Succ(tmpL)) == Faux && i < r-1){
    tmpL=Succ(tmpL);
    i+=1;
  }
  /* On détruit la cellule suivant celle trouvée et met à jour le Succ de la
  cellule détruite. Ceci fonctionne même si Succ(tmpL) = liste_vide */
  tmpL->next=Detruire(Succ(tmpL));
  /* On renvoie la tête de la Liste. */
  return L;
}

Liste Ajouter(Liste L, Element E, int r){
  /* E est element_invalide: on ne fait rien. */
  if (E == element_invalide){
    return L;
  }
  /* ajout en tête de Liste. */
  if (r == 0){
    return Creer(E, L);
  }
  /* recherche de la cellule de range r-1 */
  int i=0;
  Liste tmpL=L;
  while (EstVide(Succ(tmpL)) == Faux && i < r-1){
    tmpL=Succ(tmpL);
    i+=1;
  }
  tmpL->next=Creer(E, Succ(tmpL)); //On colle la liste
  /* On renvoie la tête de la Liste. */
  return L;
}

Liste Inverser(Liste L){
  Liste Linv=liste_vide, tmpL=L;
  while (EstVide(tmpL) == Faux){ //On met le 1er élément dans une liste puis le 2ème élément devant le premier etc
    Linv=Creer(Contenu(tmpL), Linv);
    tmpL=Succ(tmpL);
  }
  return Linv;
}

Liste Copier(Liste L){
  /* Si L est liste_vide. En effet, Contenu renvoie element_invalide et Creer renvoie liste_vide, qui est le résultat attendu */
  Liste Lcopie=Creer(Contenu(L), liste_vide);
  /* si L est liste_vide Succ renvoie liste_vide donc la ligne marche */
  Liste tmpL=Succ(L);
  /* La variable tmpC va recueillir la référence vers la dernière cellule ajoutée en fin de Liste. */
  Liste tmpC=Lcopie;
  /* si L est liste_vide, Lcopie sera inchangée et la fonction renverra liste_vide */
  while (EstVide(tmpL) == Faux){ //On copie chaque cellule une par une jusqu'à que la liste soit vide
    tmpC->next=Creer(Contenu(tmpL), liste_vide);
    tmpC=Succ(tmpC);
    tmpL=Succ(tmpL);
  }
  return Lcopie;
}

Liste Vider(Liste L){
  while (EstVide(L) == Faux){ //On détruit chaque cellule une par une jusqu'à que la liste soit vide
    L=Detruire(L);
  }
  return L;
}

// EXEMPLE DE MAIN
int main(int argc, char *argv[])
{
  // création et affichage

  int i;
  Liste L=liste_vide;
  for (i=1; i<argc; i++)
    {
      Element E=strtof(argv[i],0); // strtof permet de traduire une chaîne de caractères en float
      L = Ajouter(L,E,0); // gère le cas où E est invalide
    }

  printf("Création et ajouts. Longueur: %d\n",Longueur(L));
  Afficher(L);
  
  return 0;
}