#include<conio.h>
#include<stdio.h>
#include<math.h>
#define nMax 100

int main(){
   int x[nMax+1],y[nMax+1],b;
   int jumx,jumy,sigmax=0,sigmay=0,skuadratx=0,skuadraty=0,sigmaxy=0,sigmaerror=0,i,n;
   int kuadx[nMax+1],kuady[nMax+1],xy[nMax+1];
   float m=0,c,error[nMax+1],fx[nMax+1];
   //,xy[nMax+1]
   //,skuadraty[nMax+1]

//algoritma
  printf("==================================================\n");
  printf(":::           PROGRAM REGRESI LINIER           :::\n");
  printf("==================================================\n\n");
  printf("Diah Purwaningsih\t\t\t3411151012\n");
  printf("Annisa Cahyadilani\t\t\t3411151022");
	
  printf ("\n\nMasukkan banyak N : "); scanf ("%d", &n);
  printf ("\n\n");

   for(i=1;i<=n;i++){
      printf("masukan nilai x [%d]: ",i); scanf("%d",&jumx);
      printf("masukan nilai y [%d]: ",i); scanf("%d",&jumy);
      x[i]=jumx;
      y[i]=jumy;
      kuadx[i]=pow(x[i], 2);
      kuady[i]=pow(y[i], 2);
      sigmax=sigmax + x[i];
      sigmay=sigmay + y[i];
      skuadratx=skuadratx + kuadx[i];
      skuadraty=skuadraty + kuady[i];
      xy[i]=x[i]*y[i];
      sigmaxy=sigmaxy + xy[i];
}
		//hitung m
       	m=((n*sigmaxy)-(sigmax*sigmay))/((n*skuadratx)-pow(sigmax,2));
  	   	printf("\nNilai m = %f ", m);
		//hitung c
	 	c=((sigmay*skuadratx)-(sigmax*sigmaxy))/((n*skuadratx)-pow(sigmax,2));
  		printf("\nNilai c = %f \n", c);
  		//hitung fx
  		for (i=1;i<=n;i++){
			fx[i]=((m*x[i])+c);  
		}
		//hitung error
		for (i=1;i<=n;i++){
			error[i]=(fx[i]-y[i]);
		}
  						printf("----------------------------------------------------------------------\n");
						printf("X\tY\tX Kuadrat\tY Kuadrat\tXY\tfx\tError\n");
						printf("----------------------------------------------------------------------\n");
						for(i=1;i<=n;i++){
						printf("%d\t%d\t%d\t\t%d\t\t%d\t%.2f\t%.2f\n",x[i],y[i],kuadx[i],kuady[i],xy[i],fx[i],error[i]);
						} 
						printf("----------------------------------------------------------------------\n");
						printf("%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n",sigmax,sigmay,skuadratx,skuadraty,sigmaxy);
 		for (i=1;i<=n;i++){
 			sigmaerror=(sigmaerror+error[i]/n);
		 }
getch();
return 0;
}
