
void helper(int* arr, int n, int S, int index, int sum, std::string current) {
	if (n == index) {
		if (S == sum) {
			std::cout << current << std::endl;
		}
		return;
	}

	helper(arr, n, S, index + 1, sum + arr[index], current + "+" + std::to_string(arr[index]));
	helper(arr, n, S, index + 1, sum - arr[index], current + "-" + std::to_string(arr[index]));
}
