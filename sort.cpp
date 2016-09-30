

#include <iostream>
#include <vector>
#include "sort.h"

using std::cout;
using std::endl;

int insertionSort(Container& arr, Iter start, Iter end)
{
	int count=0;
	
	for(int i=1;i<end;i++)
	{
		int j=i;
		
		while(j>0 && arr[j]<arr[j-1])
		{
			Val temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j--;
			count++;
		}
		count++;
	}
	return count;
}

int mergeSort(Container& arr, Iter start, Iter end)  
{
  int count1=0;
  int count2=0;
  int count3=0;
  
  if( start<(end-1) )
  {  
    Iter mid=(start+end)/2;
    
    count2=mergeSort( arr, start, mid);
    count3=mergeSort( arr, mid, end);
    
    Container newarr;//(end-start);//changed from end - start + 1
    
    Iter i,j;//deleted k
  
    i=start;
    j=mid;
    //k=start;
    
    while(i<mid && j<end)
    {
      if(arr[i]<=arr[j])
      {
        //newarr[k]=arr[i];
        newarr.push_back(arr[i]);
        i++;
        count1++;
      }
      else
      {
        //newarr[k]=arr[j];
        newarr.push_back(arr[j]);
        j++;
        count1++;//added this because a comparison is done. If this is left out, the count will only work if i < j
      }
     // k++;
    }
  
      while(i<mid)
      {
        //newarr[k]=arr[i];
        newarr.push_back(arr[i]);
        i++;
        //k++;
      }
      while(j<end)
      {
        //newarr[k]=arr[j];
        newarr.push_back(arr[j]);
        j++;
        // k++;
      }
      
      for(i=0;i<newarr.size();i++)//changed
      {
        arr[start + i]=newarr[i];
      }
  }
  
  int count=count1+count2+count3;
  return count;
}

//help from text p. 525
int quickSort(Container& arr, Iter start, Iter end)
{
	int count=0;
	
	if(arr.size()>1) 
	{
		count+=partition(arr,start,end-1);
	}
		
return count;	
}

int partition(Container& a, Iter st, Iter nd)
{
	int count=0;
	
	if(st>=nd)
	{
		return count;
	
	}
	
	Iter left,right;
	left=st;
	right=nd-1;
	Val piv=a[nd];
	Val temp;
	
	while(left<=right)
	{
			while(left<=right && a[left]<=piv)
			{
				left++;
				count++;
			}
			while(right>=left && a[right]>=piv)
			{
				right--;
				count++;
			}
			if(left<right)
			{
				temp=a[left];
				a[left]=a[right];
				a[right]=temp;
			}
	}
		
		temp=a[left];
		a[left]=a[nd];
		a[nd]=temp;
		

		count+=partition(a,st,left-1);
		
		count+=partition(a,left+1,nd);
		
	 return count;  
}

//for help with shell sort function http://www.cplusplus.com/forum/general/123961/
int shellSort(Container& arr, Iter start, Iter end)
{
	Iter dis, i, j, temp;
	Iter n=(end-start);
	int count=0;
	
    for (dis = n/2; dis > 0; dis /= 2)
	{

        for (i = dis; i < n; i++)
		{

            for (j=i-dis; j>=0 && arr[j]>arr[j+dis]; j-=dis) 
			{
				count++;
                temp = arr[j];
                arr[j] = arr[j+dis];
                arr[j+dis] = temp;
            }
		}
	}
	
	return count;
}


void print(const Container& arr,int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;
}
/*
int main()
{
	Iter n=10;
	Container a(n);
	
	int arr[n]={8,3,10,3,15,200,50,2,5,29};
	
	for(int i=0;i<n;i++)
	{
		a[i]=arr[i];
	}
	
	cout<<"end "<<n<<endl;
	
	print(a,n);
	//int num_comp_i=insertionSort(a,0,n); 
	//int num_comp_m=mergeSort(a,0,n);
	int num_comp_q=quickSort(a,0,n);
	//int num_comp_s=shellSort(a,0,n);
	
	print(a,n);
	
	//cout<<"number of comparisons insertion sort "<<num_comp_i<<endl;
	//cout<<"number of comparisons mergesort "<<num_comp_m<<endl;
	//cout<<"number of comparisons quicksort "<<num_comp_q<<endl;
	//cout<<"number of comparisons shellsort "<<num_comp_s<<endl;
	
	
cout<<"end"<<endl;
}*/


