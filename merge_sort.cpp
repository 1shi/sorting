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
//ascending order
void merge(int *arr,int l,int m ,int r){
	int n1 = m-l+1;//left temp array size
	int n2 = r-m;//right temp array size
	int *left_arr = new int[n1];
	int *right_arr = new int[n2];
	//initilize the temporary array
	// it cant be done without extra space
	//if you swap the array is no longer sorted
	for(int k=0;k<n1;k++){
		left_arr[k] = arr[l+k];
	}
	for(int k=0;k<n2;k++){
		right_arr[k] = arr[k+m+1];
	}
	
	//now merge the array
	int i=0,j=0;
	int k = l;
	while((i<n1)&(j<n2)){
		if(left_arr[i]<right_arr[j]){
			arr[k] = left_arr[i];
			i++;
		}
		else{
			arr[k] = right_arr[j];
			j++;			
		}
		k++;
	}
	
	//now one array is empty and other has some elements left
	
	if(i==n1){//if left array is empty
		while(j<n2){
			arr[k] = right_arr[j];
			j++;
			k++;
		}
	}
	else{
		while(i<n1){
			arr[k] = left_arr[i];
			i++;
			k++;
		}
	}
	
}

void mergeSort(int *arr,int l, int r){
	if(r>l){// this stops the execution if there is only one element
		int m = l+((r-l)/2);//finding the middle of the array
		mergeSort(arr,l,m);//mergesort the left half
		mergeSort(arr,m+1,r);//mergesort the right half
		merge(arr,l,m,r);//merge the sorted array		
	}
}

int main(){
	int array[] = {5,26,24,68,45,36,48,0,800,87864354};
	int n = sizeof(array)/sizeof(array[0]);
	cout<<"(merge) sorting the array \n";
	mergeSort(array,0,n-1);//give the start and stop index
	print_res(array,n);	
	return 0;
}
