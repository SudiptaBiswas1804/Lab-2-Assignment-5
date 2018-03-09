//Programme for binary search
#include <iostream>
using namespace std;

//The function for binary search
void binarysearch(int arr[], int lsize, int rsize, int key){
	int mid=(lsize+rsize)/2;    //Finding the middle position for comparision
	if(key>=arr[lsize] && key<=arr[rsize]){    //To check if the element is there in the list or not
		if(arr[mid]==key){       //If the middle element is the key 
			cout<<"The element found at "<<mid<<endl;
		}
		else{
			if(arr[mid]>key){
				binarysearch(arr,lsize,mid-1,key);  //If the middle element is larger then recursive function applied for the left half array
			}
			else if(arr[mid]<key){
				binarysearch(arr,mid+1,rsize,key);  //If the middle element is smaller then recursive function applied for the right half array
			}
		}
	}
}

//Function for finding the smallest element
int small(int arr[]){
	return arr[0];
}

//Main function for the programme
int main() {
	int n,i,j,k,temp=0;
	int arr[n];
	cin>>n;
	for(i=0; i<n; i++){     //Taking in the array
		cin>>arr[i];
	}
	
	//Bubble sorting - sorting in the ascending order
	for(i=0; i<n; i++){
		for(j=0; j<n-1; j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	//Printing the array
	cout<<"The sorted array is : "<<endl;
	for(k=0; k<n; k++){
		cout<<arr[k]<<" ";
	}
	cout<<endl;
	cout<<"Smallest element is : "<<small(arr)<<endl;
	int size=n;
	int key=94;
	binarysearch(arr,0,size-1,key);  //Calling the binary search function 
	return 0;
}
