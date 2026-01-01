/* This DSA project implements various sorting algorithms including Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, and Quick Sort.
It provides a menu-driven interface for users to choose sorting methods and display results. */

#include<iostream>
#include<windows.h>
using namespace std;

//global variable
int swaps;

//menu
void menu(){
        cout<<"\n--- Sorting Menu ---\n";
        cout<<"1. Bubble Sort\n";
        cout<<"2. Selection Sort\n";
        cout<<"3. Insertion Sort\n";
        cout<<"4. Merge Sort\n";
        cout<<"5. Quick Sort\n";
        cout<<"6. Change Array Values\n";
        cout<<"7. Display Array\n";
        cout<<"8. Exit\n";
        cout<< "Enter your choice: ";
}

//temparary array fuction
void temparray(int orignalarry[], int arr[], int length){
	for(int i=0;i<length;i++){
		arr[i]=orignalarry[i];
	}
}

//swaping function
void swap(int &num1, int &num2){
	int temp;
	temp=num1;
	num1=num2;
	num2=temp;
}

//display sorted array
void displayarray(int arr[],int length){
	system("cls");
	system("color 2");//9
	cout<<"Sorted Array : ";
	for (int i=0;i<length;i++){
    cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Total Swaps in this Algorithm : "<<swaps<<endl;
	system("pause");
	system("cls");
	system("color 7");
}

//animation
void animation(int arr[], int length) {
	system("cls");
	system("color c");
	cout<<"Sorting the array Please Wait!..."<<endl;
    for (int i=0;i<length;i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    Sleep(1000);
}

//bubble sort function
void bubblesort(int arr[],int length){
     for(int i=0;i<length-1;i++){
		for(int j=0;j<length-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swaps++;
				animation(arr,length);
			}
		}
	}
	
}

//slecting sort function
void slectionsort(int arr[],int length){
	
	for (int i=0;i<length-1;i++){
		int smallvalue=i;
		for (int j=i+1;j<length;j++){
			if(arr[j]<arr[smallvalue]){
				smallvalue=j;
			}
		}
		swap(arr[i],arr[smallvalue]);
		swaps++;
		animation(arr,length);
	}
	
}

//insertion sort function
void insertionsort(int arr[],int length){
	
	for (int i=1;i<length;i++){
		int prev=i-1;
		int curr=arr[i];
		while(prev>=0&&arr[prev]>curr){
			arr[prev+1]=arr[prev];
			animation(arr,length);
			prev--;
		}
		arr[prev+1]=curr;
		swaps++;
		animation(arr,length);
	}
	
}

//merg sort functions
void merg(int arr[],int start,int mid, int end, int length){
	int temp[100];
	int i=start;
	int j=mid+1;
	int index=0;
	while(i<=mid&&j<=end){
		if(arr[i]<=arr[j]){
			temp[index]=arr[i];
			i++;
			index++;
		}
		else{
			temp[index]=arr[j];
			j++;
			index++;
		}
	}
	
	while (i<=mid){
		temp[index]=arr[i];
		i++;
		index++;
	}
	while (j<=end){
		temp[index]=arr[j];
		j++;
		index++;
	}
	for(int i=0;i<index;i++){
		arr[i+start]=temp[i];
	}
	animation(arr,length);
}

void mergsort(int arr[],int start, int end, int length){
	if(start<end){
		int mid=start+(end-start)/2;
		mergsort(arr,start,mid,length);
		mergsort(arr,mid+1,end,length);
		
		merg(arr,start,mid,end,length);
	}
}

//quick sorting functions
int partition(int arr[],int start,int end, int length){
	int index=start-1;
	int piv=arr[end];
	for(int i=start;i<end;i++){
		if(arr[i]<=piv){
			index++;
			swap(arr[i],arr [index]);
			swaps++;
		}
	}
	 index++;
	 swap(arr[end],arr[index]);
	 animation(arr,length);
	 swaps++;
	 return index;
}

void quicksort(int arr[],int start,int end, int length){
	if(start<end){
		int pivot=partition(arr,start,end,length);
		
		quicksort(arr,start,pivot-1,length);
		quicksort(arr,pivot+1,end,length);
	}
}

//main function
int main(){
	
	system("mode con: cols=100 lines=35");
	
//taking the value from user in orignal array
	int orignalarry[100];
	int length;
	up:
	cout<<"Enter the length of Array : ";
	cin>>length;
	cout<<"Enter values in array:"<<endl;
    for (int i=0;i<length;i++){
    	cout<<i+1<<") ";
    	cin>>orignalarry[i];
	}
	system ("cls");
	int arr[length];
	
//main menu implementation
	int choice=0;
	while(choice!=8){
	menu();
	cin>>choice;
	
	switch(choice){
		
		case 1:
			swaps=0;
			temparray(orignalarry,arr,length);
			bubblesort(arr,length);
			displayarray(arr,length);
			break;
		
		case 2:
			swaps=0;
			temparray(orignalarry,arr,length);
			slectionsort(arr,length);
			displayarray(arr,length);
			break;
		
		case 3:
			swaps=0;
			temparray(orignalarry,arr,length);
			insertionsort(arr,length);
			displayarray(arr,length);
			break;
		
		case 4:
			swaps=0;
			temparray(orignalarry,arr,length);
			mergsort(arr,0,length-1,length);
			displayarray(arr,length);
			break;
			
		case 5:
			swaps=0;
			temparray(orignalarry,arr,length);
			quicksort(arr,0,length-1,length);
			displayarray(arr,length);
			break;
			
		case 6:
			system("cls");
			goto up;
			break;
		
		case 7:
			swaps=0;
			temparray(orignalarry,arr,length);
			displayarray(arr,length);
			break;
			
		case 8:
			cout<<"Exiting the Program..."<<endl;
			break;
			
		default:
			cout<<"ERROR!!...."<<endl;
		    break;
		    
	}
}

	return 0;

}
