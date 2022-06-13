#include<stdio.h>
#include<conio.h>
#include<math.h>


int main(){
	printf("---SAYISAL TUREV---\n");
	int i,kssayisi,secim;
	float sonuc=0,a,h;
	float katsayilar[20],usler[20];

	
	printf("Fonksiyonunuzun kac katsayidan olusacagini girin: \n");
	scanf("%d",&kssayisi);
	for(i=0;i<kssayisi;i++){
		printf("%d. katsayiyi giriniz: ",i+1);
		scanf("%f",&katsayilar[i]);		
	}
	for(i=0;i<kssayisi;i++){
		printf("%d. X'in ussunu giriniz: ",i+1);
		scanf("%f",&usler[i]);
	}
	printf("\nFonksiyonun hangi noktadan turevini alacaginizi giriniz:");
	scanf("%f",&a);
	printf("h degerini giriniz:");
	scanf("%f",&h);
	printf("\nHangi turev islemini istediginizi seciniz\n[1]Ileri Farklar ile Turev\n[2]Geri Farklar ile Turev\n[3]Merkezi Farklar ile Turev\n");
	scanf("%d",&secim);
	
	if(secim==1){
	  printf("\n---Ileri Farklar ile Turev---\n");
	  for(i=0;i<kssayisi;i++){
	  	sonuc=sonuc+(katsayilar[i]*(pow(a+h,usler[i])-pow(a,usler[i]))/h);
	  }	
		printf("Sonuc = %f",sonuc);
		
	}else if(secim==2){
	  printf("\n---Geri Farklar ile Turev---\n");
	  for(i=0;i<kssayisi;i++){
	  	sonuc=sonuc+(katsayilar[i]*(pow(a,usler[i])-pow(a-h,usler[i]))/h);
	  }	
		printf("Sonuc = %f",sonuc);	
		
	}else if(secim==3){
	    printf("\n---Merkezi Farklar ile Turev---\n");
	    for(i=0;i<kssayisi;i++){
	  	sonuc=sonuc+(katsayilar[i]*(pow(a+h,usler[i])-pow(a-h,usler[i]))/(h*2));
	  }	
		printf("Sonuc = %f",sonuc);		
	}
	getchar();
	return 0;
}
