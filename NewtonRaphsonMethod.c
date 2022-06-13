//NEWTON-RAPHSON YÖNTEMÝ///
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	printf("***NEWTON-RAPHSON***\n");
	int i,kssayisi,katsayilar[20],usler[20],n=0;
	float sonuc=0,a,b,c,sonuc1=0,sonuc2=0,hatapayi,value,temp=0,sonuc3=0;

	
	printf("Fonksiyonunuzun kac katsayidan olusacagini girin: ");
	scanf("%d",&kssayisi);
	for(i=0;i<kssayisi;i++){
		printf("%d. katsayiyi giriniz: ",i+1);
		scanf("%d",&katsayilar[i]);		
	}

	for(i=0;i<kssayisi;i++){
		printf("%d. X'in ussunu giriniz: ",i+1);
		scanf("%d",&usler[i]);
	}
	printf("\nFonkisonun alt sinirini giriniz: ");
	scanf("%f",&a);
	printf("Fonkisonun ust sinirini giriniz: ");
	scanf("%f",&b);
	printf("\nGirdiginiz deger araliginda bi baslangic degeri seciniz: ");
	scanf("%f",&c);
	printf("\nHata payini giriniz: ");
	scanf("%f",&hatapayi);
	while(temp>=hatapayi || n==0){	
    if(n!=0){
    	c=value;
	}
	sonuc3=0;
	sonuc=0;
		for(i=0;i<kssayisi;i++){
		sonuc=sonuc+(katsayilar[i]*pow(c,usler[i]));
	}
   	for(i=0;i<kssayisi;i++){
   		if(usler[i]==0 && i==kssayisi-1){
   			sonuc3=sonuc3+0;
		    }else{
		   	sonuc3=sonuc3+(katsayilar[i]*(usler[i])*pow(c,(usler[i]-1)));
		   }
	}
    value=c-(sonuc/sonuc3);
	n++;
    temp=(value-c);
    if(temp<0){
    	temp=temp*(-1);
	}
	printf("\n%d. ITERASYON\n--- Kok = %f \n--- Guncel hata payi = %lf\n",n,value,temp);
  }
  printf("\n%d. Iterasyonda yaklasik kok degeri bulundu.\n",n);
  printf("Kok:%f",value);
  getchar();
  return 0;
}
