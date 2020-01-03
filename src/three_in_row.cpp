//Incluimos bibliotecas y namespaces respectivos

#include <iostream>
#include <stdio.h>

using namespace std;

//variables globales
struct tablero{
       struct{
              int X;
              int O;
       };
       int ocupado;
};
const int n=3;
const int m=3;



//funciones globales
void dibujarTablero(tablero tabla[n][m]);
/*int opcionEjeY(char);
int opcionEjeX(char);*/
int comprobarVictoria(tablero tabla[n][m]);


int main(int argc, char *argv[])
{
   tablero tabla[n][m];
   int opcion;
   int victoria,cont,i,j,p,q;

   inicio:
   cont=0;
   //inicializamos a cero el juego
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
       tabla[i][j].O=0;
       tabla[i][j].X=0;
       tabla[i][j].ocupado=0;
       }
   }

   dibujarTablero(tabla);
   //iniciamos partida:
   for(i=0;i<9 && cont==0;i++)
   {
           bucle:
           if(i%2==0)//mueve X
           {
               cout<<"Juegan X: ";
               cin>>opcion;
               p=opcion/10;
               q=opcion%10;
               if(p<0 || q<0 || p>2 || q>2)
               {
               cout<<"Coordenadas incorrectas pruebe otra vez"<<endl;
               goto bucle;
               }
               else if(tabla[p][q].ocupado==1)
               {
               cout<<"ATENCION, la casilla esta ocupada"<<endl;
               goto bucle;
               }

               else
               {
               tabla[p][q].X=1;
               tabla[p][q].ocupado=1;
               }
           }
           else //mueve O
           {
               cout<<"Juegan O: ";
               cin>>opcion;
               p=opcion/10;
               q=opcion%10;
               if(p<0 || q<0 || p>2 || q>2)
               {
               cout<<"Coordenadas incorrectas pruebe otra vez"<<endl;
               goto bucle;
               }
               else if(tabla[p][q].ocupado==1)
               {
               cout<<"ATENCION, la casilla esta ocupada"<<endl;
               goto bucle;
               }

               else
               {
               tabla[p][q].O=1;
               tabla[p][q].ocupado=1;
               }
           }
           dibujarTablero(tabla);
           //condiciones de victoria, comprobamos si se llego a la victoria
           victoria=comprobarVictoria(tabla);
           if(victoria==1){
                cout<<" X GANAN!!!"<<endl;
                cont++;
           }
           if(victoria==0){
                cout<<" O GANAN!!!"<<endl;
                cont++;
           }
   }
   if(!cont)
   cout<<" LA PARTIDA ACABA EN TABLAS "<<endl;

   cout<<"Para jugar otra partida pulse 1:";
   cin>>opcion;
   if(opcion==1)
   {
      system("cls");
      goto inicio;
   }

   system("PAUSE");
   return -0;
}



//imprime tablero en pantalla
void dibujarTablero(tablero tabla[n][m])
{
printf("------------------------------------\n");
	printf("BIENVENIDO AL JUEGO \n");
printf("       TRIQUI\n");
printf("------------------------------------\n");
printf("HECHO Y MEJORADO POR\n");
printf("PARA QUE JUEGUE LA FAMILIA \n");
printf("------------------------------------\n");
printf("------  A Jugar  -----\n");


    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,203,205,205,205,203,205,205,205,187);
    printf("\n");
    if(tabla[0][0].ocupado==1)
    {
        if(tabla[0][0].X==1)
        printf("%c%c%c%c%c",186,32,88,32,186);//,32,32,32,186,32,32,32,186);
        else
        printf("%c%c%c%c%c",186,32,79,32,186);//,32,32,32,186,32,32,32,186);
    }
        else
        printf("%c%c%c%c%c",186,32,32,32,186);//,32,32,32,186,32,32,32,186);
    if(tabla[1][0].ocupado==1)
    {
        if(tabla[1][0].X==1)
        printf("%c%c%c%c",32,88,32,186);//,32,32,32,186);
        else
        printf("%c%c%c%c",32,79,32,186);//,32,32,32,186);
    }
        else
        printf("%c%c%c%c",32,32,32,186);
    if(tabla[2][0].ocupado==1)
    {
        if(tabla[2][0].X==1)
        printf("%c%c%c%c",32,88,32,186);
        else
        printf("%c%c%c%c",32,79,32,186);
    }
        else
        printf("%c%c%c%c",32,32,32,186);
    printf(" 0");
    printf("\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",186,32,32,32,186,32,32,32,186,32,32,32,186);
    printf("\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n");
    if(tabla[0][1].ocupado==1)
    {
        if(tabla[0][1].X==1)
        printf("%c%c%c%c%c",186,32,88,32,186);//,32,32,32,186,32,32,32,186);
        else
        printf("%c%c%c%c%c",186,32,79,32,186);//,32,32,32,186,32,32,32,186);
    }
        else
        printf("%c%c%c%c%c",186,32,32,32,186);//,32,32,32,186,32,32,32,186);
    if(tabla[1][1].ocupado==1)
    {
        if(tabla[1][1].X==1)
        printf("%c%c%c%c",32,88,32,186);//,32,32,32,186);
        else
        printf("%c%c%c%c",32,79,32,186);//,32,32,32,186);
    }
        else
        printf("%c%c%c%c",32,32,32,186);
    if(tabla[2][1].ocupado==1)
    {
        if(tabla[2][1].X==1)
        printf("%c%c%c%c",32,88,32,186);
        else
        printf("%c%c%c%c",32,79,32,186);
    }
        else
        printf("%c%c%c%c",32,32,32,186);
    //printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",186,32,32,32,186,32,32,32,186,32,32,32,186);
    printf(" 1");
    printf("\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",186,32,32,32,186,32,32,32,186,32,32,32,186);
    printf("\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n");
    if(tabla[0][2].ocupado==1)
    {
        if(tabla[0][2].X==1)
        printf("%c%c%c%c%c",186,32,88,32,186);//,32,32,32,186,32,32,32,186);
        else
        printf("%c%c%c%c%c",186,32,79,32,186);//,32,32,32,186,32,32,32,186);
    }
        else
        printf("%c%c%c%c%c",186,32,32,32,186);//,32,32,32,186,32,32,32,186);
    if(tabla[1][2].ocupado==1)
    {
        if(tabla[1][2].X==1)
        printf("%c%c%c%c",32,88,32,186);//,32,32,32,186);
        else
        printf("%c%c%c%c",32,79,32,186);//,32,32,32,186);
    }
        else
        printf("%c%c%c%c",32,32,32,186);
    if(tabla[2][2].ocupado==1)
    {
        if(tabla[2][2].X==1)
        printf("%c%c%c%c",32,88,32,186);
        else
        printf("%c%c%c%c",32,79,32,186);
    }
        else
        printf("%c%c%c%c",32,32,32,186);
    //printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",186,32,32,32,186,32,32,32,186,32,32,32,186);
    printf(" 2");
    printf("\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",186,32,32,32,186,32,32,32,186,32,32,32,186);
    printf("\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,202,205,205,205,202,205,205,205,188);
    printf("\n");
    printf("  0   1   2  ");
    printf("\n");
    printf("\n");
}


//comprobamos si hay victoria
int comprobarVictoria(tablero tabla[n][m])
{
    //victoria X devuelve el valor 1
    if(tabla[0][0].X==1 && tabla[1][1].X==1 && tabla[2][2].X==1)
    return 1;
    else if(tabla[0][2].X==1 && tabla[1][1].X==1 && tabla[2][0].X==1)
    return 1;
    else if(tabla[0][1].X==1 && tabla[1][1].X==1 && tabla[2][1].X==1)
    return 1;
    else if(tabla[1][0].X==1 && tabla[1][1].X==1 && tabla[1][2].X==1)
    return 1;
    else if(tabla[0][2].X==1 && tabla[0][1].X==1 && tabla[0][0].X==1)
    return 1;
    else if(tabla[2][2].X==1 && tabla[2][1].X==1 && tabla[2][0].X==1)
    return 1;
    else if(tabla[0][0].X==1 && tabla[1][0].X==1 && tabla[2][0].X==1)
    return 1;
    else if(tabla[0][2].X==1 && tabla[1][2].X==1 && tabla[2][2].X==1)
    return 1;
    //victoria O devuelve el valor 0
    if(tabla[0][0].O==1 && tabla[1][1].O==1 && tabla[2][2].O==1)
    return 0;
    else if(tabla[0][2].O==1 && tabla[1][1].O==1 && tabla[2][0].O==1)
    return 0;
    else if(tabla[0][1].O==1 && tabla[1][1].O==1 && tabla[2][1].O==1)
    return 0;
    else if(tabla[1][0].O==1 && tabla[1][1].O==1 && tabla[1][2].O==1)
    return 0;
    else if(tabla[0][2].O==1 && tabla[0][1].O==1 && tabla[0][0].O==1)
    return 0;
    else if(tabla[2][2].O==1 && tabla[2][1].O==1 && tabla[2][0].O==1)
    return 0;
    else if(tabla[0][0].O==1 && tabla[1][0].O==1 && tabla[2][0].O==1)
    return 0;
    else if(tabla[0][2].O==1 && tabla[1][2].O==1 && tabla[2][2].O==1)
    return 0;
    //no hay victoria de ninguno
    return -1;
}
