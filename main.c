#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5


typedef struct Point{
    int x;
    int y;
}Point;

typedef int increment;

//Prototype
void initTab(int Tab[TAILLE][TAILLE]);
void VerifNE(Point *p);
void VerifNO(Point *p);
void verifcarree(Point *p,int Tab [TAILLE][TAILLE]);


//BUT : Initialiser et afficher un carrée magique dont la somme des lignes, colonnes et diagonales on la meme valeur
//ENTREE : Constante d'entier de 5 ou 7, variable de type structuré Point, variable type increment et 3 int
//SORTIE : Le carrée magique afficher et verifier
int main()
{
Point p;//variable de type structuré servant de curseur
increment inc=1;//variable increment servant a remplir le tableau
int Tab[TAILLE][TAILLE];//Tableau
int i=0;//variables pour les boucles for
int j=0;

    initTab(Tab);//Initialize a 0 les cases du tableau
    //Calcule le millieu du carre
    p.y=(TAILLE/2)-1;
    p.x=(TAILLE/2);

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            if(Tab[p.y][p.x]==0){
                Tab[p.y][p.x]=inc;//Incremente le tableaux
                VerifNE(&p);//Verifie si on ne sort pas du tableux en se deplacant au Nord Est
            }else{
                VerifNO(&p);//Verifie si on ne sort pas du tableux en se deplacant au Nord Ouest
                Tab[p.y][p.x]=inc;//Incremente le tableaux
                VerifNE(&p);//Verifie si on ne sort pas du tableux en se deplacant au Nord Est
            }
            inc+=1;
        }
    }

    //Boucle pour afficher le tableaux
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            if(j==0){
                printf("\n%d  ",Tab[i][j]);
            }else{
                printf("%d  ",Tab[i][j]);
            }
        }
    }

    //verifcarree(&p, Tab);//verifie si les ligne, colonne ou diagonale sont egales

    return 0;
}


//BUT : Initialize a 0 les cases du tableau
//ENTREE : Tableau d'entier
//SORTIE : Tableau d'entier initialiser a 0
void initTab(int Tab[TAILLE][TAILLE])
{
int i=0;
int j=0;

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            Tab[i][j]=0;
        }
    }
}


//BUT : Verifie si on ne sort pas du tableux en se deplacant au Nord Est
//ENTREE : Adresse de p
//SORTIE : Adresse de p modifier en consequence (Sortie du tableau)
void VerifNE(Point *p){

    if((p->y>0)&&(p->x<TAILLE-1)){

        p->y-=1;
        p->x+=1;
    }else if(p->y==0){

        p->y=TAILLE-1;
        p->x+=1;
    }else if(p->x==TAILLE-1){

        p->y-=1;
        p->x=0;
    }
}


//BUT : Verifie si on ne sort pas du tableux en se deplacant au Nord Ouest
//ENTREE : Adresse de p
//SORTIE : Adresse de p modifier en consequence (Sortie du tableau)
void VerifNO(Point *p){

    if((p->y>0)&&(p->x>0)){

        p->y-=1;
        p->x-=1;
    }else if(p->y==0){

        p->y=TAILLE-1;
        p->x-=1;
    }else if(p->x==0){

        p->y-=1;
        p->x=TAILLE-1;
    }
}


//BUT : Affiche la somme des ligne, colonne ou diagonale
//ENTREE : Adresse de p et le tableau
//SORTIE : La somme des ligne, colonne ou diagonale
/*void verifcarree(Point *p,int Tab [TAILLE][TAILLE])
{
int i=0;
int j=0;
int res=0;

        //Verifie les lignes
        for(i=0;i<TAILLE;i++){
            for(j=0;j<TAILLE;j++){
                res+=Tab[i][j];
            }
            printf("%d\n",res);
            res=0;
        }
        //verifie les colonnes
        for(i=0;i<TAILLE;i++){
            for(j=0;j<TAILLE;j++){
                res+=Tab[j][i];
            }
            printf("%d\n",res);
            res=0;
        }
        //verifie la diagonale de la droite vers la gauche
        j=0;
        for(i=0;i<TAILLE;i++){
            res+=Tab[i][j];
            j+=1;
        }
        printf("%d\n",res);
        res=0;
        //verifie la diagonale de la gauche vers la droite
        j=TAILLE-1;
        for(i=0;i<TAILLE;i++){
            res+=Tab[i][j];
            j-=1;
        }
        printf("%d\n",res);
}*/
