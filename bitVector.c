/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Autor: Felipe Schreiber
       Matheus Moura
*/

#include <stdio.h>
#include "bitVector.h"
#include <stdbool.h>
#include <stdlib.h>
/*
Inputs: Essa funcao recebe um vetor denotado por *arr, bem como o numero dos vertices que estao conectados tal como foram lidos do arquivo de input(nao importa a ordem) e o numero maximo de vertices. Importante: i e j variam de 1 ate numero maximo de vertices.

Output: Essa funcao coloca o respectivo bit da conexao em nivel 1, embora nao retorne nenhum valor.
*/
void addVectorBit(char *arr,int j,int i,int V)
{
 int indiceReal,numberOfShifts,a,totalOfPreviousBits;
 if(i<j)
 {
  if(i != 1)
  {
   a = (V -1*(i - 2));
   totalOfPreviousBits= (a+V)*(i-1);
   //Calculo da P.A. ate o indice anterior
   totalOfPreviousBits /= 2;
  }
  else
   totalOfPreviousBits = 0;
  //a eh o n-esimo - 1 termo da P.A. queremos achar quantos bits ja foram usados antes de chegar no registrador alvo
  indiceReal = (totalOfPreviousBits+V-j);
  numberOfShifts = (indiceReal%8);
  printf("\nindiceReal:%d || Number of shifts:%d\n",indiceReal,numberOfShifts);
  //printf("\nindiceReal/8:%d\n",(indiceReal/8));
  arr[indiceReal/8] |= (1<<numberOfShifts);
  if(getVectorBit(arr,i,j,V))
   printf("\nInsercao OK\n");
  //printf("\nresultado do shift:%d\n",(1<<numberOfShifts) );
  printf("\narr[indiceReal/8]:%d\n",arr[indiceReal/8]);
 }
 else
 {
  if(j != 1)
  {
   a = (V -1*(j - 2));
    totalOfPreviousBits= (a+V)*(j-1);
   //Calculo da P.A. ate o indice anterior
   totalOfPreviousBits /= 2;
  }
  else
   totalOfPreviousBits = 0;
  //Calculo da P.A. ate o indice anterior
  indiceReal = (totalOfPreviousBits+V-i);
  numberOfShifts = (indiceReal%8);
  printf("\nindiceReal:%d || Number of shifts:%d\n",indiceReal,numberOfShifts);
  //printf("\nindiceReal/8:%d\n",(indiceReal/8));
  arr[indiceReal/8] |= (1<<numberOfShifts);
  if( getVectorBit(arr,i,j,V) )
   printf("\nInsercao OK\n");
  //printf("\nresultado do shift:%d\n",(1<<numberOfShifts) );
  printf("\narr[indiceReal/8]:%d\n",arr[indiceReal/8]);
 }
 //if(getBit(arr,j,i,V))
  //printf("\nInsercao OK\n");
}

bool getVectorBit(char *arr,int j,int i,int V)
{
 int indiceReal,a,totalOfPreviousBits,numberOfShifts;
 //printf("\nget BIT!\n");
 if(i<j)
 {
  indiceReal=(V-j);
  if(i != 1)
  {
   a = (V -1*(i - 2));
   totalOfPreviousBits= (a+V)*(i-1);
   //Calculo da P.A. ate o indice anterior
   totalOfPreviousBits /= 2;
  }
  else
   totalOfPreviousBits = 0;
  //a eh o n-esimo - 1 termo da P.A. queremos achar quantos bits ja foram usados antes de chegar no registrador alvo
  //printf("\nTOPB:%d\n",totalOfPreviousBits);
  indiceReal += totalOfPreviousBits;
  numberOfShifts = ((indiceReal)%8);
  //printf("\nindiceReal:%d || Number of shifts:%d\n",indiceReal,numberOfShifts);
  //printf("\nindiceReal/8:%d\n",(indiceReal/8));
  //printf("\narr[indiceReal/8]:%d\n",arr[indiceReal/8]);
  if(arr[indiceReal/8] & (1<<numberOfShifts))
   return true;
  return false;
 // printf("\nLinha:%d Coluna:%d\n",(i-1),indiceReal);
 // printf("\nNumero de shifts:%d\n",numberOfShifts); 
 }
 else
 {
  indiceReal=(V-i);
  if(j != 1)
  {
   a = (V-1*(j-2));
   //printf("\na:%d\n",a);
   totalOfPreviousBits=(a+V)*(j-1);//Calculo da P.A. ate o indice anterior
   totalOfPreviousBits /= 2;
   //printf("\nTOPB j != 1:%d\n",totalOfPreviousBits);
  }
  else
   totalOfPreviousBits = 0;
  //Calculo da P.A. ate o indice anterior
  //printf("\nTOPB:%d\n",totalOfPreviousBits);
  indiceReal += totalOfPreviousBits;
  numberOfShifts = ((indiceReal)%8);
  //printf("\nindiceReal:%d || Number of shifts:%d\n",indiceReal,numberOfShifts);
  //printf("\nindiceReal/8:%d\n",(indiceReal/8));
  //printf("\nand:%d\n",and);
  //printf("\narr[indiceReal/8]:%d\n",arr[indiceReal/8]);
  if(arr[indiceReal/8] & (1<<numberOfShifts))
   return true;
  return false;
  //printf("\nLinha:%d Coluna:%d\n",(j-1),indiceReal);
  //printf("\nNumero de shifts:%d\n",numberOfShifts);
 }
}

void bitVectorPrint(char *arr,int V)/*Imprime na tela como se fosse uma matriz de v² posicoes normalmente*/
{
 int i,j;
 for(i=1;i<=V;i++)
 {
  for(j=1;j<=V;j++)
  { 
   if(getVectorBit(arr,i,j,V))
    printf("1");
   else
    printf("0");   
  }
  printf("\n");
 }
   
}

char *bitVectorCreator(int V)
//maxBytes eh calculado fazendo maxBits = (1 + V)*V/2 (Soma de todos os termos da P.A.) e maxBytes = [(maxBits - 1)/8 + 1];
{
 char *adjArray;
 int i,maxBytes,maxBits;
 maxBits = ((1 + V)*V/2);
 maxBytes = ((maxBits - 1)/8 + 1);
 printf("\nnumero max de bytes:%d\n",maxBytes);
 adjArray = malloc((maxBytes)*sizeof(char));
 for(i = 0; i<maxBytes;i++)
  adjArray[i] = 0;
 return adjArray;
}
