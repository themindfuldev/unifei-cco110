#include <stdio.h>
#include <conio.h>
#include <math.h>

#define pi 3.141592            // #define var valor - define uma constante
//const float pi = 3.141592;   // const tipo var = valor; - defina uma constante

void main()
{
  int op;
  float v1, v2, area, per;
  do
  {
    do
    {
      v1 = 0;
      v2 = 0;
      clrscr();
      printf("\n\tCALCULO DE CARACTERISTICAS DE FIGURAS\n\n\t\t1 - Quadrado\n\t\t2 - Retangulo\n\t\t3 - Triangulo Retangulo\n\t\t4 - Circulo\n\t\t5 - Sair\n\n\tEscolha a opcao desejada [1, 2, 3, 4 ou 5]: ");
      scanf("%d", &op);
      if ((op!=1)&(op!=2)&(op!=3)&(op!=4)&(op!=5))
      {
        printf("\n\n\tOpcao invalida!!\n\t[Pressione alguma tecla para continuar...]");
        getch();
      }
    }
    while ((op!=1)&(op!=2)&(op!=3)&(op!=4)&(op!=5));
    if (op==1)
    {
      do
      {
        clrscr();
        printf("\n\tCALCULO DE CARACTERISTICAS DO QUADRADO\n\n\tDigite o valor do lado: ");
        scanf("%f", &v1);
        if (v1<=0)
        {
          printf("\n\tO valor do lado deve ser positivo!!\n\t[Pressione alguma tecla para continuar...]");
          getch();
        }
      }
      while (v1<=0);
      area = v1*v1;
      per = 4*v1;
      printf("\n\n\tArea: %0.2f u\n\tPerimetro: %0.2f u2\n\n\t[Pressione alguma tecla para continuar...]", area, per);
      getch();
    }
    else if (op==2)
    {
      while (v1<=0)
      {
        clrscr();
        printf("\n\tCALCULO DE CARACTERISTICAS DO RETANGULO\n\n\tDigite o valor da base: ");
        scanf("%f", &v1);
        if (v1<=0)
        {
          printf("\n\tO valor da base deve ser positivo!!\n\t[Pressione alguma tecla para continuar...]");
          getch();
        }
      }
      printf("\n\tDigite o valor da altura: ");
      scanf("%f", &v2);
      if (v2<=0)
      {
        printf("\n\tO valor da altura deve ser positivo!!\n\t[Pressione alguma tecla para continuar...]");
        getch();
        while (v2<=0)
        {
          clrscr();
          printf("\n\tCALCULO DE CARACTERISTICAS DO RETANGULO\n\n\tDigite o valor da base: %0.2f\n\n\tDigite o valor da altura: ", v1);
          scanf("%f", &v2);
          if (v2<=0)
          {
            printf("\n\tO valor da altura deve ser positivo!!\n\t[Pressione alguma tecla para continuar...]");
            getch();
          }
        }
      }
      area = v1*v2;
      per = (2*v1)+(2*v2);
      printf("\n\n\tArea: %0.2f u\n\tPerimetro: %0.2f u2\n\n\t[Pressione alguma tecla para continuar...]", area, per);
      getch();
    }
    else if (op==3)
    {
      while (v1<=0)
      {
        clrscr();
        printf("\n\tCALCULO DE CARACTERISTICAS DO TRIANGULO RETANGULO\n\n\tDigite o valor da base: ");
        scanf("%f", &v1);
        if (v1<=0)
        {
          printf("\n\tO valor da base deve ser positivo!!\n\t[Pressione alguma tecla para continuar...]");
          getch();
        }
      }
      printf("\n\tDigite o valor da altura: ");
      scanf("%f", &v2);
      if (v2<=0)
      {
        printf("\n\tO valor da altura deve ser positivo!!\n\t[Pressione alguma tecla para continuar...]");
        getch();
        while (v2<=0)
        {
          clrscr();
          printf("\n\tCALCULO DE CARACTERISTICAS DO TRIANGULO RETANGULO\n\n\tDigite o valor da base: %0.2f\n\n\tDigite o valor da altura: ", v1);
          scanf("%f", &v2);
          if (v2<=0)
          {
            printf("\n\tO valor da altura deve ser positivo!!\n\t[Pressione alguma tecla para continuar...]");
            getch();
          }
        }
      }
      area = (v1*v2)/2;
      per = v1+v2+sqrt(pow(v1,2)+pow(v2,2));     //sqrt() - calcula raiz quadrada
      printf("\n\n\tArea: %0.2f u\n\tPerimetro: %0.2f u2\n\n\t[Pressione alguma tecla para continuar...]", area, per);
      getch();
    }
    else if (op==4)
    {
      while (v1<=0)
      {
        clrscr();
        printf("\n\tCALCULO DE CARACTERISTICAS DO CIRCULO\n\n\tDigite o valor do raio: ");
        scanf("%f", &v1);
        if (v1<=0)
        {
          printf("\n\tO valor do raio deve ser positivo!!\n\t[Pressione alguma tecla para continuar...]");
          getch();
        }
      }
      area = pi*pow(v1,2);         //pow() - calcula exponencia��o
      per = 2*pi*(v1);
      printf("\n\n\tArea: %0.2f u\n\tPerimetro: %0.2f u2\n\n\t[Pressione alguma tecla para continuar...]", area, per);
      getch();
    }
  }
  while(op!=5);
}