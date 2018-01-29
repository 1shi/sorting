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

void selectionSort(int *arr,int n){
	cout<<"(selection) sorting the array \n";
	int max_ind = 0;
	for(int i=0;i<n-1;i++){
		max_ind = i;
		for(int j=i;j<n;j++){
			if(arr[j]>arr[max_ind]){
				max_ind = j;
			}
		}
		swap(&arr[i],&arr[max_ind]);
	}
}

int main(){
	int array[] = {5,26,24,68,45,36,48,0,800};
	int n = sizeof(array)/sizeof(array[0]);
	selectionSort(array,n);
	print_res(array,n);	
	return 0;
}
