#include<stdio.h>
#include <time.h>
#include <conio.h>
#define MAX 500000

void heapolustur(int *a,int size){
    int i,m;
    m=(size-2)/2;

    for(i=m ; i>=0;i--)
        maxheapify(a,i,size);
}

void maxheapify(int *a,int i,int size){
    int largest=i,left,right;
    left=(2*i)+1;
    right=(2*i)+2;
    if(left<size && a[left]>a[largest])
    largest=left;
    if(right<size && a[right]>a[largest])
    largest=right;
    if(largest!=i)
    {
    swap(&a[largest],&a[i]);
    maxheapify(a,largest,size);
    }
}

void heapsort(int *a,int size){
    heapolustur(a,size);
    while(size>1)
    {
    swap(&a[0],&a[size-1]);
    --size;
    maxheapify(a,0,size);
    }
}

void swap(int *a,int *b){
int temp;
temp=*a;
*a=*b;
*b=temp;
}

void dizi_doldur(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		a[i]=1+rand()%100;
	}
}

int main(){
	int i,j,arr[MAX],n,k=0;
	srand(time(NULL));
	clock_t start;
	clock_t end;
	int diyagram[10],tekrar=10;
	double sonuc[10];
	
	while(k<tekrar){
	
		printf("%d. dizinin eleman sayisini giriniz: ",k+1);
		scanf("%d",&n);
		diyagram[k]=n;
		printf("%d elemanli dizi icin: \n",n);
		dizi_doldur(arr,n);
		/*printf("Sirasiz random dizi:\n");
		for(i=0;i<n;i++){
			printf(" %d ",arr[i]);
		}*/
		
		start=clock();
		heapsort(arr,n);
		end=clock();
		double time_passed = ((double)(end-start)/CLOCKS_PER_SEC)*1000;
		sonuc[k]=time_passed;
		/*printf("Random dizinin siralanmis hali:\n");
		for(i=0;i<n;i++){
			printf(" %d ",arr[i]);
		}*/
		printf("\n%.8lf milisaniye",time_passed);
		printf("\n\n");
		k++;
	}
	printf("DIZI ELEMAN SAYISI ---       SURE\n");
	for(i=0;i<tekrar;i++){
		printf(">      %6d        ",diyagram[i]);
		printf("---");
		printf("   %.8lf\n",sonuc[i]);
	}
	printf("\n");
	printf("          #DIYAGRAM#         \n");
	
	for(i=0;i<tekrar;i++){
		printf(">> %5d   ",diyagram[i]);
		for(j=0;j<sonuc[i];j++){
			printf("*");
		}
		printf("\n");	
	}

return 0;
}
