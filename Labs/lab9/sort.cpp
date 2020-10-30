#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool check_num(int x){
	if( x <0 || x > 25){
		return false;
	}
return true;
}

/*
void merge(int arr[], int l, int m, int r){
	
	int i,j,k;
	int n1 = m -l +1;
	int n2 = r - m;

	int* L = new int [n1];
	int* R = new int [n2];

	for(i=0; i < n1; i++)
		L[i] = arr[l + i];
	for(j=0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i=0, j=0, k =l;

	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while( j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
	delete [] L;
	delete [] R;
}


void mergeSort(int arr[], int l, int r){
	if( l < r){
		int m = (l+(r-1))/2;
	
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		
		merge(arr, l, m, r);
	}else{
		return;
	}
}


void fill_arr(int* arr[], int size){
	for(int i=0; i < size; i++){
		*arr[i] = rand()% 100 + 1;
	}
}
*/


void merge(int** a, const int low, const int mid, const int high){
	int *tmp = new int[high-low+1];

	int left = low, right = mid+1, current =0;

	while(left <= mid && right <=high){
		if(*a[left] <= (*a)[right]){
			tmp[current] = (*a)[left];
			left++;
		}else{
			tmp[current] = (*a)[right];
			right++;
		}
		current++;
	}
	if(left > mid){
		for(int i=right; i <=high; i++){
			tmp[current]= (*a)[i];
			current++;
		}
	}else{
		for(int i=left; i <=mid; i++){
			tmp[current]= (*a)[i];
			current++;
		}
	}

	for(int i=0; i < high-low; i++){
		(*a)[i+low] = tmp[i];
	}

	delete [] tmp;
}

void merge_sort(int** a, const int low, const int high){
	if(low >= high)
		return;
	
	int mid = (low+high)/2;
	merge_sort(a, low, mid);
	merge_sort(a, mid+1, high);
	merge(a, low, mid, high);
}


int main(){
	srand(time(NULL));
	int size;
	cout << "Enter size of array: ";
 	cin >> size;
	bool num = check_num(size);
	while(num == false){
		cout << "Enter a number greater than 0 and less than 25: " << endl;
		cin >> size;
		num = check_num(size);
	}
	
	int* arr = new int[size];
	for(int i=0; i < size; i++){
		arr[i] = rand() % 100 +1;
	}

	cout << "array elements: " << endl;
	for(int i=0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	int* new_arr = new int [size];

	for(int i=0; i < size; i++){
		new_arr[i] = arr[i];
	};

	cout << "array elements: " << endl;
	for(int i=0; i < size; i++){
		cout << new_arr[i] << " ";
	}
	
	merge_sort(&new_arr, 0, size);

	cout << "Sorted elements: " << endl;
	for(int i=0; i < size; i++){
		cout << new_arr[i] << " ";
	}
	cout << endl;

	delete [] arr;
	delete [] new_arr;
	
return 0;
}