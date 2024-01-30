#include<stdio.h>
 void selectionsort(int arr[],int n){

for(int i=0;i<n;i++){


int minindex=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[minindex]){
            minindex = j;
        }
        int temp=arr[minindex];
        arr[minindex]=arr[j];
        arr[j]=temp;

    }
}


}


int main(){
int arr[6]={22,66,21,20,9,7};
for (int i = 0; i<6; i++)
{
printf(" %d ",arr[i]);
}
printf("\n");
selectionsort(arr,6);

for (int i = 0; i<6; i++)
{
printf(" %d ",arr[i]); 
}

return 0;
}
