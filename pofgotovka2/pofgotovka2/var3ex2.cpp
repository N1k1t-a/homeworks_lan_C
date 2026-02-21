

int* get_array_sum(int n){
	int size = 0;

	for (int i = 1; i <= n; i++) {
		size += i;
	}

	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		arr[i] = 1;
	}

	return arr;
}