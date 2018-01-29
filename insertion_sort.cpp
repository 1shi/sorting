#include <iostream>
using namespace std;
//void bubbleSort(int arr[], int n)
void print_res(int *arr,int n){
	cout<<"Print the sorted array \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

void swap(int *xp, int *yp){
	//sending adddress so need pointer to receive it
	//xp and xp are pointer so to access their value we use *xp abd *yp
	int temp;
	temp =  *xp;
	*xp = *yp;
	*yp = temp;	
}

void insertionSort(int *arr,int n){
	cout<<"(insertion) sorting the array \n";
	//array is sorted till ith element
	for(int i=1;i<n;i++){
		for(int j=i;j>0;j--){
			if(arr[j]<arr[j-1]){//just change sign to get asc or desc order
				swap(&arr[j],&arr[j-1]);
			}
		}
	}
}

int main(){
	int array[] = {5,26,24,68,45,36,48,0,800};
	int n = sizeof(array)/sizeof(array[0]);
	insertionSort(array,n);
	print_res(array,n);	
	return 0;
}
