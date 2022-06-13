#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
float matris[10][10],c,temp,sonuc[10];
int x,y,i,j,k,flag,a=0;
printf("***GAUSS ELEMINASYON METODU***\n");
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
printf("\nDenklemin matris uzerindeki hali\n");
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
for(k=0;k<x;k++){
    if(matris[k][k] == 0){
        flag = 0;
        while(a<x && flag==0){
            if(matris[a][k] != 0){
             for(y=0; y<x+1; y++){
                temp = matris[k][y];
                matris[k][y] = matris[a][y];
                matris[a][y] = temp;
    }
    flag = 1;
   }
   a++;
  }
 }
}
for(k=0;k<x-1;k++){
    for(i=k+1;i<x;i++){
        c=matris[i][k]/matris[k][k];
        for(j=0;j<x+1;j++){
            matris[i][j]=matris[i][j]-(c*matris[k][j]);
        }
    }
 }
printf("\nUst ucgen hali\n");
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
sonuc[x-1]=matris[x-1][x]/matris[x-1][x-1];
temp=matris[i][x];
for(i=x-2;i>=0;i--){
    for(j=i+1;j<x;j++){
        sonuc[i]=matris[i][x]-matris[i][j]*sonuc[j];
        matris[i][x]=sonuc[i];
 }
sonuc[i]=sonuc[i]/matris[i][i];
matris[i][x]=temp;
 }
printf("\n---Bilinmeyenlerin degerleri---\n");
for(i=0;i<x;i++){
    printf("%d. bilinmeyen = %f\n",i+1,sonuc[i]);
}
getchar();
return 0;
}

