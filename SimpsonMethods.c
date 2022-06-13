#include<stdio.h>
#include<conio.h>
#include<math.h>


int main(){
	printf("***SIMPSON YONTEMI***\n");
	float kssayisi,katsayilar[20],usler[20];
	float sonuc=0,n,h,a,b,sonuc1=0,sonuc2=0,gercekSonuc=0,temp,sonuc3=0,c,d,sonuc4=0,temp2;
    int i,j,secim;
	
	printf("Fonksiyonunuzun kac katsayidan olusacagini girin: ");
	scanf("%f",&kssayisi);
	for(i=0;i<kssayisi;i++){
		printf("%d. katsayiyi giriniz: ",i+1);
		scanf("%f",&katsayilar[i]);		
	}
	for(i=0;i<kssayisi;i++){
		printf("%d. X'in ussunu giriniz: ",i+1);
		scanf("%f",&usler[i]);
	}
	printf("\nIntegralin baslangic degerini giriniz: ");
	scanf("%f",&a);
	temp=a;
	printf("Integralin bitis degerini giriniz: ");
	scanf("%f",&b);
	temp2=b;
	printf("\nYaklasik degeri hesaplamak icin n degerini giriniz: ");
	scanf("%f",&n);
	printf("\nHangi simpson yöntemini kullanmak istediginizi seciniz\n[1]1/3 Simpson Yontemi\n[2]3/8 Simpson Yontemi\n");
	scanf("%d",&secim);
	if(secim==1){
		printf("\n---1/3 SIMPSON YONTEMI---\n");
	h=(b-a)/n;
	for(i=0;i<n;i++){
		sonuc1=0;
		sonuc2=0;
		sonuc3=0;
		for(j=0;j<kssayisi;j++){
		sonuc1=sonuc1+(katsayilar[j]*powf(a,usler[j]));
		sonuc2=sonuc2+(katsayilar[j]*powf((a+h),usler[j]));
		sonuc3=sonuc3+(katsayilar[j]*powf((2*a+h)/2,usler[j]));
	}
	
	    sonuc=sonuc+h*((sonuc1+4*sonuc3+sonuc2)/6);
        a=a+h;
	}
	//gerçek degerini bulma
	a=temp;
	for(i=0;i<kssayisi;i++){
		gercekSonuc=gercekSonuc+((katsayilar[i]*powf(b,usler[i]+1)/(usler[i]+1)-(katsayilar[i]*powf(a,usler[i]+1)/(usler[i]+1))));
		}
			    if(gercekSonuc<0){
	    	gercekSonuc*=-1;	
	}
	printf("Gercek sonuc = %f\n",gercekSonuc);
	printf("1/3 Simpson yontemi sonucu = %f\n",fabs(sonuc));
	printf("Mutlak hata payi = %f\n",fabs(gercekSonuc-sonuc));
	getchar();
}else if(secim==2){
	printf("\n---3/8 SIMPSON YONTEMI---\n");
	d=(b-a)/n;
	b=a+d;
	h=(b-a)/3;
	for(i=0;i<n;i++){
		sonuc1=0;
		sonuc2=0;
		sonuc3=0;
		sonuc4=0;
		for(j=0;j<kssayisi;j++){
		sonuc1=sonuc1+(katsayilar[j]*powf(a,usler[j]));
		sonuc2=sonuc2+(katsayilar[j]*powf((a+h),usler[j]));
		sonuc3=sonuc3+(katsayilar[j]*powf((a+(2*h)),usler[j]));
		sonuc4=sonuc4+(katsayilar[j]*powf((a+(3*h)),usler[j]));
	}
	
        sonuc=sonuc+(d*(sonuc1+3*sonuc2+3*sonuc3+sonuc4)/8);
        a=a+d;
	}
	//gerçek degerini bulma
	a=temp;
	b=temp2;
	for(i=0;i<kssayisi;i++){
		gercekSonuc=gercekSonuc+((katsayilar[i]*powf(b,usler[i]+1)/(usler[i]+1)-(katsayilar[i]*powf(a,usler[i]+1)/(usler[i]+1))));
	}
		    if(gercekSonuc<0){
	    	gercekSonuc*=-1;
		}
	printf("Gercek sonuc = %f\n",gercekSonuc);
	printf("3/8 Simpson yontemi sonucu = %f\n",fabs(sonuc));
	printf("Mutlak hata payi = %f\n",fabs(gercekSonuc-sonuc));
	getchar();
	

}
	return 0;
}
