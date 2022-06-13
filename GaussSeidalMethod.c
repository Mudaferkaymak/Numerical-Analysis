#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
	float matris[10][10],c,temp,sonuc[10],max[10],xyz[10];
	int x,y,i,j,k,n;
	
	printf("***GAUSS SEIDEL METODU***\n");
	printf("Bilinmeyen sayisini giriniz: ");
	scanf("%d",&x);
	for(i=0;i<x;i++){
		sonuc[i]=0;
	}
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			printf("%d. denklemin %d. katsayisini giriniz: ",i+1,j+1);
			scanf("%f",&matris[i][j]);
		}
		printf("%d. denklemin sonucunu giriniz: ",i+1);
		scanf("%f",&matris[i][x]);
	}
	printf("\n");
    for(i=0;i<x;i++){
    	printf("%d. degisken icin baslangic degeri giriniz: ",i+1);
    	scanf("%f",&xyz[i]);
	}
	printf("\nIstediginiz iterasyon sayisini giriniz: ");
	scanf("%d",&n);
	for(i=0;i<x;i++){
		for(j=0;j<x+1;j++){
			if(j==x){
				printf(" | %f",matris[i][j]);
			}else{
				printf("%f ",matris[i][j]);			
			}
		}
		printf("\n");
	}

	for(k=0; k<x+1; k++){

        for(i=k+1; i<x; i++){

            if(fabs(matris[i][k]) > fabs(matris[k][k])){

                for(j=0; j<x+1; j++){
                    temp = matris[i][j];
                    matris[i][j] = matris[k][j];
                    matris[k][j] = temp;
                }
            }
        }
    }
	printf("\nHer suturda mutlak degerce en buyuk olan kosegen uzerinde olmalidir\n");
	for(i=0;i<x;i++){
		for(j=0;j<x+1;j++){
			if(j==x){
				printf(" | %f",matris[i][j]);
			}else{
				printf("%f ",matris[i][j]);			
			}
		}
		printf("\n");
	}	
	for(k=0;k<n;k++){
		for(i=0;i<x;i++){
		temp=matris[i][x];
		for(j=0;j<x;j++){
			if(i!=j){
			    sonuc[i]=temp-matris[i][j]*xyz[j];
				temp=sonuc[i];			
			}
		}
			xyz[i]=sonuc[i]/matris[i][i];
	}	
	printf("\n%d.ITERASYON\n",k+1);
		for(i=0;i<x;i++){
		printf("--- %d. Bilinmeyenin degeri = %f\n",i+1,xyz[i]);
	 }
	}
    getchar();
	return 0;
}
