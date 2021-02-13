#include<stdio.h>

void Merge(int arr[], int l, int m, int r);
void MergeSort(int arr[],int l,int r);

void main()
{
	int i, j, studentsNumber, counter = 0, output = 1;
	int studentScore[100];
	
	//The group should has at least 3 students
	do
	{
		scanf("%d",&studentsNumber);
		
	}while(studentsNumber < 3);
	
	//students Score arr is empty
	for(i = 0; i < studentsNumber; i++)
	{
		scanf("%d",&studentScore[i]);
	}
		
	//students stand in a line in increasing order
	MergeSort(studentScore, 0, studentsNumber-1);
	
	for(i = 0; i < studentsNumber - 1; i++)
	{
			if(studentScore[i] + 1 != studentScore[i+1])
			{
				if(counter < 2)
				{
					output = 0;
					break;
				}
				else
					counter = 0;			
			}
			counter++;
	}
	
	if(output)
		printf("YES");
	else
		printf("NO");
}
//Merge Sort
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void Merge(int arr[], int l, int m, int r)
{
	int i,j,k;
	
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    i = 0;
 
    // Initial index of second subarray
    j = 0;
 
    // Initial index of merged subarray
    k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void MergeSort(int arr[],int l,int r)
{
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    MergeSort(arr,l,m);
    MergeSort(arr,m+1,r);
    Merge(arr,l,m,r);
}
