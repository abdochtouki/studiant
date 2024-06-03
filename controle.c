#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
int j;
int m;
int a;
}date;
typedef struct{
char Nom[30];
char Prenom[30];
date *date_in;
struct inscrit *next;
}inscrit;
//comparer deux date 
int comparer_date(date* d1,date* d2){
     int m;
     if(d1->a==d2->a && d1->m==d2->m){
       m=d1->j-d2->j;
     }
    else if(d1->a==d2->a)
     {
    m=d1->m-d2->m;
    }
    else
     m=d1->a-d2->a;      
      return m;
   }
//comparer deux inscrit 
int comparer_inscrit(inscrit* i1,inscrit* i2){

    return comparer_date(i1->date_in,i2->date_in);
   
}


//affichage 
void afficher_date(date* d) {
    printf(" ,annee %d  ,mois %d  ,jour  %d \n",d->a,d->m,d->j);
}
void afficher_inscrit(inscrit* i){

printf("Nom %s  Prenom %s  ",i->Nom,i->Prenom);
afficher_date(i->date_in);
}

date* creer_date()
{
     date* d=(date*)malloc(sizeof(date));
     if(d==NULL){
        printf("erreur d'allocation\n");
        exit(1);
     }
     printf("annee :");
     scanf("%d",&d->a);
     printf("mois  :");
     scanf("%d",&d->m);
     printf("jour  :");
     scanf("%d",&d->j);

    return d;
}
inscrit* crer_inscrit(){
     inscrit *d=(inscrit*)malloc(sizeof(inscrit));
     if (d==NULL)
     {
      printf("erreur d'allocation \n");
       free(d);
       exit(1);
     }
     char s[30];
    printf("Nom: ");
    scanf("%s", s);
    strcpy(d->Nom, s);

    printf("Prenom: ");
    scanf("%s", s);
    strcpy(d->Prenom, s);
     d->date_in=creer_date();
       d->next=NULL;
    return d;
}
inscrit* ajouter_d(inscrit* liste,inscrit* nouveau){
        if (nouveau==NULL)
        return liste;
    
      nouveau->next = liste;
    return nouveau;
}
inscrit* ajouter_fin(inscrit* liste,inscrit* nouveau){
    inscrit *P;
    P=liste;
    while(P->next != NULL){
      
        P = P->next;
    }
    P->next = nouveau;
    nouveau->next = NULL;


   return liste;
}
inscrit* supprimer_in(inscrit* liste,char* N,char* Pr)
{
    inscrit* P;
    inscrit* Q;
    P=liste;
    while(P!=NULL)
    {
        if (strcmp(P->Nom,N)==0 && strcmp(P->Prenom,Pr)==0)
        {
            if (P == liste)
            {
                liste = liste->next;
                }
             else
                {
                    Q->next = P->next;
                    P->next = NULL;
                    free(P);
                
                    }
        }
        Q=P;
        P = P->next;
        
}
return liste;
}
inscrit* supprimer_tous(inscrit* liste,date* d){
    inscrit* P;
    inscrit* Q;
    P=liste;
    while(P!=NULL){
        if(comparer_date(d,P->date_in)==0){
            if(P==liste)
            {
                liste = liste->next;
                P->next = NULL;
                free(P);
            }
            else
            {
                Q->next=P->next;
                P->next=NULL;
                free(P);
            }

        }
        Q=P;
        P=P->next;
    }
return liste;
}
void afficher_liste(inscrit* liste){
    while(liste!=NULL){
        afficher_inscrit(liste);
        liste=liste->next;

    }
}




inscrit* chercher_inscrit(inscrit* liste, char* N, char* Pr) {
    inscrit* P = liste;
    if (liste == NULL) {
        return NULL;
    }
    while (P != NULL) {
        if (P->Nom != NULL && P->Prenom != NULL && strcmp(N, P->Nom) == 0 && strcmp(Pr, P->Prenom) == 0) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
 int virifier_liste(inscrit * liste )
 {
    return liste=NULL;
 }
 int nombre_in( inscrit * liste){
    int m=0;
    inscrit *P;
    while(P!=NULL){
        m++;
        P=P->next;

    }
    return m;
 }
 void afficher_p_date(inscrit * liste,date * d){
    int n=0;
   while(liste!=NULL){
    if(comparer_date(d,liste->date_in==0))
        {
       afficher_inscrit(liste);
       liste=liste->next;
       n++;
        }

   }
   if(!n){
    printf("Aucun inscrit n'est inscrit le %d/%d/%d\n",d->j,d->m,d->a);
   }
 }

   int main(){
    int m;
   inscrit* i1=(inscrit*)malloc(sizeof(inscrit));
    inscrit* i2=(inscrit*)malloc(sizeof(inscrit));
    date* d=(date*)malloc(sizeof(date));

    i1=crer_inscrit();
   int i;
    for(i=0;i<3;i++){
      i2=ajouter_fin(i1,crer_inscrit());
    }
    afficher_liste(i2);
    printf("*****************************************\n");
    if (virifier_liste(i2)>0)
    printf("la liste contient %d\n",nombre_in(i1));
    else
    printf("la liste est vide :");

    d=creer_date();
     afficher_p_date(i2,d);

 

     inscrit* i3=(inscrit*)malloc(sizeof(inscrit));
     char Nom[30],Prenom[30];
     printf("saisir le nom qui chercher ");
     scanf("%s",Nom);
     printf("saisir le prenom qui chercher ");
    scanf("%s",Prenom);
    i3=chercher_inscrit(i2,Nom,Prenom);
    afficher_inscrit(i3);
    
   return 0;
   }
