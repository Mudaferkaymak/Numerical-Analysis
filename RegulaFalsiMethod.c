//REGULA-FALSÝ METODU///
#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){
	printf("***REGULA-FALSI***\n");
	int i,kssayisi,usler[20],n=1;
	float sonuc=0,a,b,c,sonuc1=0,sonuc2=0,hatapayi,katsayilar[20];

	
	printf("Fonksiyonunuzun kac katsayidan olusacagini girin: ");
	scanf("%d",&kssayisi);
	for(i=0;i<kssayisi;i++){
		printf("%d. katsayiyi giriniz: ",i+1);
		scanf("%f",&katsayilar[i]);		
	}
	for(i=0;i<kssayisi;i++){
		printf("%d. X'in ussunu giriniz: ",i+1);
		scanf("%d",&usler[i]);
	}
	printf("\nFonkisonun alt sinirini giriniz: ");
	scanf("%f",&a);
	printf("Fonkisonun ust sinirini giriniz: ");
	scanf("%f",&b);
	printf("\nHata payini giriniz: ");
	scanf("%f",&hatapayi);
		for(i=0;i<kssayisi;i++){
		sonuc1=sonuc1+(katsayilar[i]*pow(a,usler[i]));
	}		
		for(i=0;i<kssayisi;i++){
		sonuc2=sonuc2+(katsayilar[i]*pow(b,usler[i]));
	}
    if(sonuc1*sonuc2<0){
    	printf("Alt ve ust sinirlarin carpimi 0'dan kucuk oldugundan bisection yontemi icin uygun\n");
	}	
	
    do{	
	sonuc1=0;	
	sonuc2=0;
		for(i=0;i<kssayisi;i++){
		sonuc1=sonuc1+(katsayilar[i]*pow(a,usler[i]));
		sonuc2=sonuc2+(katsayilar[i]*pow(b,usler[i]));
	}
	
	c=(a*sonuc2-b*sonuc1)/(sonuc2-sonuc1);
	n++;
	sonuc=0;
		for(i=0;i<kssayisi;i++){
		sonuc=sonuc+(katsayilar[i]*pow(c,usler[i]));
	}
	
	if(sonuc*sonuc1<0){
		b=c;
	}else if(sonuc*sonuc2<0){
		a=c;

	}
	printf("\n%d. ITERASYON\n--- Kok=%f\n--- f(kok)=%f \n--- Guncel hata payi: %f\n",n,c,sonuc,(b-a)/pow(2,n));
  }while((b-a)/pow(2,n)>=hatapayi);
  
  printf("a=%f        b=%f",a,b);
  
  printf("\n%d. Iterasyonda yaklasik kok degeri bulundu.\n",n);
  
  printf("Kok=%f",c);
  
  getchar();
  return 0;
}
