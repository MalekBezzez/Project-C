#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//creation module pile
int estvide(char pile[92]){
if(strlen(pile)==0)
    return 1;
else
    return 0;
}
void Empiler(char e,char pile[92]){
 pile[strlen(pile)]=e;
}

char depiler(char pile[92]){
char a;
a=pile[strlen(pile)-1];
pile[strlen(pile)-1]='\0';
return (a);
}
char sommet(char pile[92]){
return(pile[strlen(pile)-1]);
}
//fin module
int isdigit_1(char e){
if(e=='0'||e=='1'||e=='2'||e=='3'||e=='4'||e=='5'||e=='6'||e=='7'||e=='8'||e=='9'||e=='.')
    return 1;
else
 return 0;
}
int priority(char e){
if(e=='-'||e=='+')
    return 1;
else if(e=='*'||e=='/')
    return 2;
else if(e=='^')
    return 3;
else
    return 0;

}
//creation pile d evaluation//
int estvide2(float evalp[92],int*j){
if(*j==0)
    return 1;
else
    return 0;
}
void Empiler2(float e,float evalp[92],int*j){
 evalp[*j]=e;
 *j=*j+1;
}
float depiler2(float evalp[92],int*j){
float a;
a=evalp[*j-1];
evalp[*j-1]=0.0;
*j=*j-1;
return (a);}
float sommet2(float evalp[92],int*j){
    if(*j>0)//n'est pas vide la liste d'evaluation la position du superieur a zero
    {return(evalp[*j-1]);}
    else
    {printf("la pile d'evaluation est vide");
        return 0;}

}
//fin module pile d'evaluation*********
float Operation(float op1,float op2,char operat){
if(operat=='+')
    return op1+op2;
else if(operat=='-')
    return op1-op2;
else if(operat=='*')
    return op1*op2;
else if(operat=='/'){
 if(op2=='0'){

    return 0;}
 else
        return op1/op2;}
else //c'est une puissance
    return pow(op1,op2);
}




int main(){
    //declaration conversion
char pile[92]="";
char infix[92]="";
char postfix[92]="";
int i,nbo=0,nbf=0;
char a;
//declaration evaluation
float evalp[92];
char operateur[92]="";
int valide=1;
float op1,op2,result;
int j=0;// j indique l'indice du prochaine saisie dans evalp
float b;
char choix[4];
int nbpar;

while(1){
printf("--------------------CALCULATRICE-----------------------\n");

gets(infix);
for(i=0;i<strlen(infix);i++)
{if(infix[i]=='(')
    nbo+=1;
else if (infix[i]==')')
    nbf+=1;
else
    continue;

}
if(nbf>nbo){
    printf("syntax ERROR\n");
    nbf=0;//initialisation pour la nouvelle calcul
    nbo=0;
    printf("-------------------------------------------------------");}
else
{


//test la validite d'expression infix
//conversion infix to postfix avec caractere separateur f
for(i=0;i<strlen(infix);i++)
{if(infix[i]==' ')
continue;
//addition caractere de fin

if(isdigit_1(infix[i])==1){
while(1){
    postfix[strlen(postfix)]=infix[i];
    if(isdigit_1(infix[i])==1&&isdigit_1(infix[i+1])==0)
        break;
    else
    i+=1;}
    postfix[strlen(postfix)]='f';}

else if (infix[i]=='(')//on ajoute directement
           {
            Empiler(infix[i],pile);
            }
else if(infix[i]==')')//en cas de ) on depile  vers postfix jusqu'a rencontre (
{a=sommet(pile);
    while(a!='(')
    {a=depiler(pile);


    postfix[strlen(postfix)]= a ;
     a=sommet(pile);
    }

 depiler(pile);
}
else
{
    //it's operator
while(priority(infix[i])<=priority(sommet(pile))&&estvide(pile)==0)//tant que la priority du infix[i]<= on va depiler vers postfix jusqu'a ce que la priorité sera valide
 {a=depiler(pile);
postfix[strlen(postfix)]= a;}

Empiler(infix[i],pile);
}
}//fin de loop
//vider la pile
while(estvide(pile)==0)
{
    a=depiler(pile);
postfix[strlen(postfix)]= a;
}

for(i=0;i<strlen(postfix);i++){
    if(postfix[i]=='(')
        nbpar+=1;
}printf("\n");

if(nbpar!=0){
    printf("syntax ERROR \n");
    nbpar=0;//initialisation pour la nouvelle calcul
    printf("-------------------------------------------------------");
}
else
{






/////*************partie evaluation postfix**********/////

for(i=0;i<strlen(postfix);i++)
{if(postfix[i]=='f')// si caractere fin on continue
continue;
if(isdigit_1(postfix[i])==1)
{while(postfix[i]!='f')// parcours jusqu'a obtenir tous les chiffres du reel
{Empiler(postfix[i],operateur);
i+=1;
}b=atof(operateur);//conversion en float puis ajouter au evalp
Empiler2(b,evalp,&j);
//rendre l'operateur vide pour la nouvelle operateur***
while(estvide(operateur)==0){
    a=depiler(operateur);
}
}
else //is operator
    { op2=depiler2(evalp,&j);
     op1=depiler2(evalp,&j);

    result=Operation(op1,op2,postfix[i]);
    Empiler2(result,evalp,&j);


    }
    if(op2==0 &&postfix[i]=='/')//detection erreur du division sur zero
{
    valide=0;

    break;
}
}//fin de loop d'evaluation
if(valide==0){
        printf("\n");

        printf("Math ERROR on ne peut pas diviser sur zero!!!!\n" );
        printf("-------------------------------------------------------");}
else

{b=sommet2(evalp,&j);
printf("\n");




printf("votre resultas est %.3f\n",b);
printf("-------------------------------------------------------\n");




}
}
}
printf("\n");
printf("faire autre calcul oui ou non\n ");
gets(choix);
printf("\n");
//rendrent les variables a l'etats initiales
valide=1;
nbpar=0;
while(estvide(postfix)==0)
{
    a=depiler(postfix);
}
printf("\n");
printf("\n");

if(strcmp(choix,"oui"))
    break;
   }//fin de while
}// fin main








