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

int partition(int *arr,int low,int high){
	//it is an inplace algorithm as we dont use any spare memory
	
	//if any random pivot chosen swap it with the last element
	int pivot=arr[high];//set the partition element as highest index
	//can chose at random for better result
	//int j=low;//smaller elements end index
	int i=low;//larger element start index
	for(int k=low;k<high;k++){
		if(arr[k]<pivot){
			swap(&arr[i],&arr[k]);
			i++;
		}
	}
	swap(&arr[high],&arr[i]);//swap the pivot with the ith element (start of elements greater tthan pivot)
	return i;//return the position of pivot
}

void quickSort(int *arr,int low,int high){
	if(low<high){// if more than one element partition and sort
		int p = partition(arr,low,high);//get the index of partition
		quickSort(arr,low,p-1);//sort the array to the left of partition
		quickSort(arr,p+1,high);//sort the array to the right of partition
	}
}

int main(){
	int array[] = {5,26,24,68,45,36,48,0,800};
	int n = sizeof(array)/sizeof(array[0]);
	cout<<"(quick) sorting the array \n";
	quickSort(array,0,n-1);
	print_res(array,n);
	cout<<"\n\n";	
	return 0;
}
