int compare(const void* a, const void* b) {
	int x = *(const int*)a;
	int y = *(const int*)b;

	return (x > y) - (x < y);
}
