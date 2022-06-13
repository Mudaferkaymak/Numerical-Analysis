#include<stdio.h>
#include<conio.h>
#include<math.h>


int main(){
	printf("---TRAPEZ YONTEMI----\n");
	int i,kssayisi,secim,j;
	double sonuc=0,n,h,a,b,sonuc1=0,sonuc2=0,gercekSonuc=0,temp;
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
	printf("\nIntegralin baslangic degerini giriniz: ");
	scanf("%lf",&a);
	temp=a;
	printf("Integralin bitis degerini giriniz: ");
	scanf("%lf",&b);
	printf("\nYaklasik degeri hesaplamak icin n degerini giriniz: ");
	scanf("%lf",&n);
	
	h=(b-a)/n;
	for(i=0;i<n;i++){
		sonuc1=0;
		sonuc2=0;
		for(j=0;j<kssayisi;j++){
		sonuc1=sonuc1+(katsayilar[j]*pow(a,usler[j]));
		sonuc2=sonuc2+(katsayilar[j]*pow((a+h),usler[j]));
	}
	    sonuc=sonuc+h*((sonuc1+sonuc2)/2);
        a=a+h;
	}
	
	//gerçek degerini bulma
	a=temp;
	for(i=0;i<kssayisi;i++){
		gercekSonuc=gercekSonuc+((katsayilar[i]*pow(b,usler[i]+1)/(usler[i]+1)-(katsayilar[i]*pow(a,usler[i]+1)/(usler[i]+1))));
	}
	  if(gercekSonuc<0){
	    	gercekSonuc*=-1;	
	}	
	printf("\nGercek sonuc = %lf\n",gercekSonuc);
	printf("Trapez yontemi sonucu = %lf\n",sonuc);
	printf("Mutlak hata payi = %lf\n",fabs(gercekSonuc-sonuc));
	return 0;
}
