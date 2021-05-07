// C++ program for building Heap from Array
  
#include <iostream>
  
using namespace std;
  
// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int arr[], int n, int i)
{
    int smallest = i; // Initialize smallest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
  
    // If right child is larger than smallest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
  
    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
  
        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}
  
// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;
  
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
  
// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";
  
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
  
  void mergeHeaps(int merged[], int a[], int b[],
                int n, int m)
{
    // Copy elements of a[] and b[] one by one
    // to merged[]
    for (int i = 0; i < n; i++)
        merged[i] = a[i];
    for (int i = 0; i < m; i++)
        merged[n + i] = b[i];
  
    // build heap for the modified array of
    // size n+m
    buildHeap(merged, n + m);
}
// Driver Code
int main()
{
    
    
    int h1,h2,h3;
	 int H1[h1];
 	 int H2[h2];
 	 h3=h1+h2;
 	 int H3[h3];
 	 
	int index1, index2;
 	
	 cout<<"H1 DIZISI BILGILERI "; 
	cout<<"H1 dizisinin uzunlugu =  ";
	cin>> h1;

  
  	for(int i=0; i<h1;i++){
  	
  	cout<<" H1 dizisinin " <<i<<". elemanini girin: ";
  	cin>>H1[i];
  	
 	}
    

  
 cout<<"H2 DIZISI BILGILERI "; 
	cout<<"H2 dizisinin uzunlugu =  ";
	cin>> h2;

  
  	for(int i=0; i<h2;i++){
  	
  	cout<<" H2 dizisinin " <<i<<". elemanini girin: ";
  	cin>>H2[i];
  	
 	}
 	
   
   
    buildHeap(H1, h1);
    buildHeap(H2, h2);
  
    printHeap(H1, h1);
    printHeap(H2, h2);


	mergeHeaps(H3, H1, H2, h1, h2);

    printHeap(H3, h2+h1);

    return 0;
}
