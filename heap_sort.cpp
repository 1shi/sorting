#include <iostream>
using namespace std;
//void bubbleSort(int arr[], int n)
void print_heap(int *arr,int n){
	cout<<"Print the heap \n";
	int count = 1;
	int j=0,i=0;
	while(i<n){
		for(int l=0;l<(n/2)-i;l++){
			cout<<"  ";
		}
		while(j<count && i<n){
			cout<<arr[i]<<"  ";
			j++;
			i++;
		}
		j=0;
		count *=2;
		cout<<endl;
	}
	cout<<endl;
}

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

void heapify(int *arr, int n, int i){
	//check if left or right node is greater than the root
	//if yes swap with the larger one
	int largest = i;//initilize largest as root; if it changes we swap
	int l = 2*i+1;//left node; as indexing from 0, 1 must be left node 
	int r = 2*i+2;//right node; as indexing from 0, 2 must be right node
	//cout<<"hello heapify "<<i<<"\n";
	//need to also check that l & r dont exceed n
	//else segmentation fault core dumped
	if((l<n)&&(arr[l]>arr[largest])){//if left node is greater than root
		largest = l;
	}
	if((r<n)&&(arr[r]>arr[largest])){// if right node is greater than root or both (root and left node)
		largest = r;
	}
	
	if(largest != i){
		swap(&arr[i],&arr[largest]);
		//may be the root was the smallest element thus need to rebalance the subtree which was perturbed
		heapify(arr,n,largest);
	}
}
//max heap made
void heapSort(int *arr,int n){
	//now we need to build a heap
	//obvious start from the bottommost layer
	//call heapify to hepify that subtree
	//start point = n/2 - 1  the last element of first filled row
	//if 5 elements then 5/2-1 = 1
	//indexing from zero right subtree is empty
	//cout<<"inside heapsort \n\n";
	for(int i=(n/2)-1;i>=0;i--){
		heapify(arr,n,i);
	}
	cout<<"made the heap \n\n";
	print_heap(arr,n);
	
	for(int i=n-1;i>0;i--){
		swap(&arr[i],&arr[0]);
		//print_res(arr,n);
		heapify(arr,i,0);//heapify the remaining heap
	}
}

int main(){
	int array[] = {5,26,24,68,45,36,48,0,800};
	int n = sizeof(array)/sizeof(array[0]);
	cout<<"(heap) sorting the array \n";
	heapSort(array,n);
	print_res(array,n);
	cout<<"\n\n";	
	return 0;
}
