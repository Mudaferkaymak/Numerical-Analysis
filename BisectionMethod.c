#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){
	printf("***BISECTION METHOD***\n");
	int i,kssayisi,katsayilar[20],usler[20],n=0;
	double sonuc=0,a,b,c,sonuc1=0,sonuc2=0,hatapayi=0,ustSinir,altSinir;

	
	printf("Fonksiyonunuzun kac katsayidan olusacagini girin: \n");
	scanf("%d",&kssayisi);
	for(i=0;i<kssayisi;i++){
		printf("%d. katsayiyi giriniz: ",i+1);
		scanf("%d",&katsayilar[i]);		
	}
	for(i=0;i<kssayisi;i++){
		printf("%d. X'in ussunu giriniz: ",i+1);
		scanf("%d",&usler[i]);
	}
	printf("\nFonkisonun alt sinirini giriniz:");
	scanf("%lf",&a);
	printf("Fonkisonun ust sinirini giriniz:");
	scanf("%lf",&b);
	printf("\nHata payini giriniz:");
	scanf("%lf",&hatapayi);
		for(i=0;i<kssayisi;i++){
		sonuc1=sonuc1+(katsayilar[i]*pow(a,usler[i]));
	}		
		for(i=0;i<kssayisi;i++){
		sonuc2=sonuc2+(katsayilar[i]*pow(b,usler[i]));
	}
    if(sonuc1*sonuc2<0){
    	printf("\nAlt ve ust sinirlarin carpimi 0'dan kucuk oldugundan bisection yontemi icin uygun\n");
	}	
	
    do{
    	altSinir = a;
    	ustSinir = b;
	sonuc1=0;
	sonuc2=0;		
		for(i=0;i<kssayisi;i++){
		sonuc1=sonuc1+(katsayilar[i]*pow(a,usler[i]));
	}		
		for(i=0;i<kssayisi;i++){
		sonuc2=sonuc2+(katsayilar[i]*pow(b,usler[i]));
	}
	sonuc=0;
	c=(a+b)/2;
	n++;
		for(i=0;i<kssayisi;i++){
		sonuc=sonuc+(katsayilar[i]*pow(c,usler[i]));
	}
	
	if(sonuc*sonuc1<0){
		b=c;

	}else if(sonuc*sonuc2<0){
		a=c;

	}
	printf("\n%d. Iterasyon\n--- Kok= %lf \n--- f(kok)= %lf \n--- Guncel hata payi: %f\n",n,c,sonuc,(ustSinir-altSinir)/pow(2,n));
  }
  while((ustSinir-altSinir)/pow(2,n)>=hatapayi);
  printf("\n%d. Iterasyonda yaklasik kok degeri bulundu.\n",n);
  printf("Kok=%f",c);
  getchar();
  return 0;
}
