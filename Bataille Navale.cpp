#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// tester les changements sur git


int i,j; /*Variable pour les boucles & recherches dans les tableaux*/
int col;/*Variable colonne*/
int lig;/*Variable Ligne*/
char tabbat[10][10];/*Table de la solution avec les bateaux*/
char grille[10][10];/*Table de jeux*/
char let; /*Variable pour afficher Coordonne en Lettre*/
char tablet[9][2];/*Tableau comparatif Lettre & chiffre*/
time_t t;   /*Variable pour générateur de nombre aléatoire*/


/**************************************MENU************************************/
void menu()
{
 cout<<"     Bataille Navale\n";
 cout<<"----------------------------\n";
 cout<<"1 : Placer les bateaux \n";
 cout<<"2 : Afficher solution\n";
 cout<<"3 : Jouer\n";
 cout<<"4 : Sauvegarder la partie\n";
 cout<<"5 : Charger la partie\n";
 cout<<"0 : Quitter\n";
}

/**********************Placement des bateaux***********************************/
void Placer()
{
int loc1;  /*Location N°1 pour les coordonnees d'un bateau*/
int loc2;  /*Location N°2 pour les coordonnees d'un bateau*/
int value; /*variable indiquant le nombre de bateau pour 1/6*/
srand((unsigned) time(&t));  /*Mise en place du Generateur de nombre aléatoire*/
cout<<"Entrez la taille de la grille de jeux (un carre)?\n";  /*nb de lignes du tableau*/
cin>>lig;
col=lig;


if (lig<2||lig>9)                                     /*test pour les nombres minimum & maximum de lignes*/
{
    while (lig<2||lig>9)
    {
       cout<<"Taille incorrecte.\n";
       cout<<"Ressaisir la taille ( >=2 <=9 ).\n";
       cin>>lig;
       col=lig;
    }
}

for (i=1;i<=lig;i++)                              /*Creation de la grille de point des bateaux*/
{
     for (j=1;j<=col;j++)
     {
         tabbat[i][j]='.';
     }
}

for (i=1;i<=lig;i++)                              /*Creation de la grille de point du jeux*/
{
     for (j=1;j<=col;j++)
     {
        grille[i][j]='.';
     }
}
cout<<"Fin de creation de la grille.\n";

value=col*lig/6;                                  /*Géneration des bateaux pour 1/6 des grilles*/

if (value<2)                                      /*Si la valeur trouve pour 1/6 est <2 alors je met 2 bateau*/
{
      value=2;
}
if (value>9)                                     /*Si la valeur trouve pour 1/6 est >9 alors je met 10 bateau*/
{
      value=10;
}
                                                      /*Géneration des  coordonnées des bateaux*/
for(i=1;i<=value;i++)
{
     loc1=(rand()%lig)+1;
     loc2=(rand()%col)+1;

     while(tabbat[loc1][loc2]=='X')                   /*Vérification de risque de doublon*/
     {
        loc1=(rand()%lig)+1;
        loc2=(rand()%col)+1;
     }
tabbat[loc1][loc2]='X';
}
cout<<"Fin de creation des bateaux.\n";
system("PAUSE");
}

/***************Affichage de la solution (ou sont les bateaux?)****************/
void Afficher()
{
cout<<"SOLUTION:\n"" ";              /*Afficher la solution*/
for (i=1;i<=lig;i++)             /*1er boucle pour afficher les coordonne en lettre*/
{
      let='A'+i-1;
      cout<<"   "<< let;
}

for (i=1;i<=lig;i++)           /*2eme boucle pour afficher la table solution avec les bateaux */
{
    cout<<"\n"<< i;

    for (j=1;j<=col;j++)
    {
        cout<<"   "<<tabbat[i][j];
    }
cout<<"\n";
}
system("PAUSE");
}

/********************************Jouer au jeu**********************************/
void Jouer ()
{
int sailoc1;      /*Saisie de ma location N°1 pour jouer*/
int sailoc2;      /*Saisie de ma location N°2 pour jouer*/
int nbbat;        /*Nombre de bateau*/
int nbtouch;      /*Nombre de bateau touche*/
int nbloup;       /*Nombre de bateau loupe*/
char sailocchar;  /*Saisie de ma location N°1 en charactere pour jouer*/

for (i=1;i<=9;i++)                             /*Création d'un tableau comparatif Lettre & Chiffre*/
{
      tablet[i][1]=i;
      tablet[i][2]='A'+i-1;
}

do
{
  nbbat=0;                          /*J'initialise mes calcul a 0*/
  nbtouch=0;
  nbloup=0;

     for (i=1;i<=lig;i++)         /*Combien de bateau il y a dans la grille, combien on été touché & loupé*/
     {
         for (j=1;j<=col;j++)
         {
             if (tabbat[i][j]=='X')            /*Compte le nombre de bateau(les 'X')*/
             {
                nbbat=nbbat+1;
             }
             if (grille[i][j]=='+')           /*Compte le nombre de bateau touché(les'+')*/
             {
               nbtouch=nbtouch+1;
             }
             if (grille[i][j]=='O')           /*Compte le nombre de bateau loupé(les 'O')*/
             {
               nbloup=nbloup+1;
             }
        }
    }
system("CLS");

cout<<"Taper Q pour quitter.\n\n";
cout<<nbbat<<" Bateau. \n";                             /*Afficher les scores*/
cout<<nbtouch<<" Bateau touche.\n";
cout<<nbloup<<" Bateau loupe.\n\n"" ";

if (nbbat!=nbtouch)             /*Verification si il a trouvé tous les bateau, si oui on quitte le jeux*/
{
     for (i=1;i<=lig;i++)              /*Boucle pour afficher les coordonne en lettre*/
     {
       let='A'+i-1;
       cout<<"   "<< let <<"";
     }
                                       /*Boucle pour afficher la table de jeux*/
     for (i=1;i<=lig;i++)
     {
        cout<<"\n"<< i;
        for (j=1;j<=col;j++)
        {
           cout<<"   "<<grille[i][j];
        }
     cout<<"\n";
     }

cout<<"Ecrire la Coordonne : (ex:A1 ou Q pour Quitter).\n";
cin >> sailocchar;                      /*Verification des coordonne si on demande de Quitter ou non*/

if(sailocchar!='Q')                     /*Si la coordonne est differente de Quitter alors on joue,sinon on quitte*/
{
cin >> sailoc1;

    for (i=1;i<=lig;i++)                   /*Convertion de la lettre en chiffre*/
    {
       if (sailocchar==tablet[i][2])
       {
         sailoc2=tablet[i][1];
       }
    }

if  (sailoc1>0 && sailoc2>0 && sailoc1<=lig && sailoc2<=col && sailocchar<='I')  /*Si les coordonne sont correcte on joue sinon on affiche une erreur*/
{
    if(tabbat[sailoc1][sailoc2]=='.')        /*Si il n'y a pas de bateau alors c'est loupé*/
    {
     grille[sailoc1][sailoc2]='O';
     cout<<"Loupe!\n";
    }
    else
    {
       if(tabbat[sailoc1][sailoc2]=='X')      /*Si il y a un bateau alors c'est touché*/
       {
         grille[sailoc1][sailoc2]='+';
         cout<<"Touche!\n";
       }
    }
}
else                                     /*Sinon si il y a une erreur on demande de resaisir*/
{
     cout<<"Erreur de choix, veuillez resaisir.\n";
}

system("PAUSE");
}
}
else                                   /*Si le joueur a trouvé tous les bateaux*/
{
  cout<<"\nVictore!! vous avez coule tous les navires ennemis.\n";
  cout<<"Veuillez reinitialiser une nouvelle partie.\n\n";
  sailocchar='Q';                       /*On quitte le jeux automatiquement si tous les bateaux on été trouvé*/
  system("PAUSE");
}
}
while(sailocchar!='Q');                /*Tant que la réponse est différente de Quitter on joue*/
}

/*****************************Sauvegarde de la partie**************************/
void Sauv ()
{
FILE *score;                                 /*Score est de type FICHIER*/
score=fopen("A:\\score.txt","w");    /*j'ouvre le FICHIER*/
if (score==NULL)                          /*Je verifie si le fichier existe*/
{
   cout<<"Fichier inexistant: score.txt\n";
}
else
{
    for(i=1;i<=lig;i++)                      /*J'enregistre ma solution avec les bateaux*/
    {
        for(j=1;j<=col;j++)
        {
          fprintf(score,"%c",tabbat[i][j]);
        }
    fprintf(score,"\n");
    }

for(i=1;i<=lig;i++)                      /*J'enregistre ma grille de jeux*/
{
      for(j=1;j<=col;j++)
      {
         fprintf(score,"%c",grille[i][j]);
      }
fprintf(score,"\n");
}
fclose(score);                             /*Je ferme le fichier Score.txt*/
cout<<"Partie sauvegardee avec succes!\n";
}
system("PAUSE");
}

/*****************************Chargement de la partie**************************/
void Charger()
{
char varcb; /*Variable pour savoir combien il y a de charactere dans ma sauvegarde*/
i=0;j=0;    /*J'initialise i & j à 0*/
FILE *score;                              /*Score est de type FICHIER*/

score=fopen("A:\\score.txt","r"); /*j'ouvre le FICHIER*/

if (score==NULL)                          /*Je verifie si le fichier existe*/
{
   cout<<"Fichier inexistant: score.txt\n";
}
else
{
   while (feof(score)==false)              /*Tant que ce n'est pas la fin du fichier on charge les données*/
   {
     i=i+1;                                  /*On compte combien il y a de charactere*/
     fscanf(score,"%c ",&varcb);
   }
lig=sqrt(i/2);                            /*On prend la racine carré de la moitier des caracteres*/
col=sqrt(i/2);                            /*ce qui me donne le nombre de ligne et colonne*/

fclose(score);                           /*On ferme le Fichier Score.txt*/

score=fopen("A:\\score.txt","r"); /*On le réouvre pour le relire depuis le debut*/

for(i=1;i<=lig;i++)                        /*On charge le tableau de solution*/
{
   for(j=1;j<=col;j++)
   {
       fscanf(score,"%c",&tabbat[i][j]);
   }
fscanf(score,"\n");
}

for(i=1;i<=lig;i++)                        /*On charge le tableau de jeux*/
{
   for(j=1;j<=col;j++)
   {
       fscanf(score,"%c",&grille[i][j]);
   }
fscanf(score,"\n");
}
fclose(score);                             /*On ferme le fichier Score.txt*/
cout<<"Partie chargee avec succes!\n";
}
system("PAUSE");
}

/************************Procédure principal gérant le Menu*********************/
void main ()
{
 char choix; /*Variable de selection des procédures dans le Menu*/
      menu ();
      cout<<"Entrez votre choix ?\n";
      cin >> choix;
      while (choix!='0')      /*Tant que mon choix n'est pas 0 pour Quitter on reste dans le programme*/
      {
       switch (choix)        /*Selon le choix on charge les procédures*/
       {
             case '1' : Placer();
             break;
             case '2' : Afficher();
             break;
             case '3' : Jouer ();
             break;
             case '4' : Sauv ();
             break;
             case '5' : Charger();
             break;
             default: cout<<"Erreur de choix\n";   /*Si le choix n'existe pas on affiche une erreur et on re-demande le choix*/
                      system("PAUSE");
       }
        system("CLS");          /*A la fin de chaque procedure lance on efface l'ecran pour recharger le menu*/
        menu ();
        cout <<"Entrez votre choix: \n";
        cin >> choix;
      }
 system("PAUSE");
}
