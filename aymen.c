#include<stdio.h>
#include<stdlib.h>

typedef struct Element Element;
struct Element{
  int nomber;
  Element *suivant;

};

typedef struct Pile Pile;
struct Pile{
  Element *sommet;
};

Pile *initialiser(){
  Pile *pile=malloc(sizeof(*pile));
  pile->sommet=NULL;

  return pile;
}

void empiler(Pile *pile,int nvNomber){
  Element *nouveau=malloc(sizeof(*nouveau));
  if(pile->sommet!=NULL){
    nouveau->nomber=nvNomber;
    nouveau->suivant=pile->sommet;
    pile->sommet=nouveau;
  }else{
    nouveau->nomber=nvNomber;
    nouveau->suivant=NULL;
    pile->sommet=nouveau;
  }
}

int depiler(Pile *pile){
  int nomberDepile=0;
  Element *elementDepile=pile->sommet;
  if(pile->sommet !=NULL){
    nomberDepile=elementDepile->nomber;
    pile->sommet = elementDepile->suivant;
    free(elementDepile);
  }
  return nomberDepile;
}

int min(Pile *pile){
  int valmin;
  Element *p1=pile->sommet;
  if(pile->sommet !=NULL){
    
    valmin=p1->nomber;
  }while(p1->suivant !=NULL){
    p1=p1->suivant;
    if(p1->nomber<valmin){valmin=p1->nomber;
    }
    return valmin;
  }
}

void renverser(Pile *pile){
  Pile *maPile2= initialiser();
  while(pile->sommet!=NULL){
    empiler(maPile2,depiler(pile));
  }
  afficherPile(maPile2);

  while(maPile2->sommet!=NULL){
  empiler(pile,depiler(maPile2));   
  }
}

void pair_impair(Pile *pile){
  Pile *Pilepair=initialiser();
  Pile *Pileimpair=initialiser();
  while(pile->sommet=!NULL){
    int v=pile->sommet->nomber;
    if(v%2==0){
      empiler(Pilepair,v);
    }
    else{
        empiler(Pileimpair,v);
    }
    pile->sommet=pile->sommet->suivant;
  }
  afficherPile(Pilepair);
  afficherPile(Pileimpair);
}

void afficherPile(Pile *pile){
  Element *actuel=pile->sommet;
  while(actuel != NULL){
    printf("%d\n",actuel->nomber);
    actuel=actuel->suivant;
  }
  printf(" \n");
}
int main(){
  Pile *maPile=initialiser();

  empiler(maPile,4);
    empiler(maPile,8);
      empiler(maPile,15);
        empiler(maPile,16);
          empiler(maPile,23);
        empiler(maPile,42);

        printf('\n Etat de la pile:\n');
        afficherPile(maPile);
        printf("\n La valurminimal est: %d\n");
                printf("\nLinver de ma pile est:\n");
                renverser(maPile);

                        printf(" Je depile %d\n",depiler(maPile));
                                printf("Je depile %d\n",depiler(maPile));

                printf("\nEtat de la pile;\n");
                afficherPile(maPile);
                pair_impair(maPile);


                return 0;





}