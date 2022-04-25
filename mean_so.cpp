#include<bits/stdc++.h>
using namespace std;

	bool swapped=0,ordered=0;
	double sum=0,mean=0;
	int bi=0;

int partition(int arr[],int si,int ei,bool &swapped){

	bi=si-1;
	sum=0;
	for(int i=si;i<=ei;i++){
		sum=sum+arr[i];

	}

	mean= ceil((double)(sum)/(ei-si+1));

	for(int i=si;i<=ei;i++){
		if(arr[i]<mean){
			bi=bi+1;
			if(arr[bi]!=arr[i]){
				swap(arr[bi],arr[i]);
				swapped=true;
			}
		}
	}
		return bi;
}

void sort(int arr[],int si,int ei){

	if((ei-si)>1){
		swapped=false;
		bi=partition(arr,si,ei,swapped);
		ordered=false;
		if(swapped==false){
			ordered=true;
			for(int i=si;i<=ei-1;i++){
				if(arr[i]>arr[i+1]){
						ordered=false;
						break;
					}
				}
		}
		if(ordered==false){
			sort(arr,si,bi);
			sort(arr,bi+1,ei);
		}
	}
}



int main(){

	
	int arr[100];
	for(int i=0;i<100;i++){
	int	x=rand()%100;
		arr[i]=x;
	}

	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<"Before sorting: "<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";	
	cout<<endl<<endl;

	int si=0,ei=n-1;
	sort(arr,si,ei);

	cout<<"Sum is "<<sum<<". Mean is "<<mean<<endl<<endl;

	cout<<"After sorting: "<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<endl;
}
