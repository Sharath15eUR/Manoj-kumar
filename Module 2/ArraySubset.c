#include <stdio.h>

int isSubset(int arr1[], int arr2[], int m, int n)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
 
        if (j == m)
           return 0;
    }
 
    
}
 
int main()
{
	int n1,n2,i;
	printf("Enter the size of first array:");
	scanf("%d",&n1);
	printf("Enter the size of second array:");
	scanf("%d",&n2);
    
    int arr1[n1],arr2[n2];
    printf("Enter the elements of first array:");
	for(i=0;i<n1;i++){
		scanf("%d",&arr1[i]);
	}
	
	printf("Enter the elements of second array:");
	for(i=0;i<n2;i++){
		scanf("%d",&arr2[i]);
	} 
    if (isSubset(arr1, arr2, n1, n2))
        printf("arr2[] is subset of arr1[] ");
    else
        printf("arr2[] is not a subset of arr1[]");
 
    return 0;
}

