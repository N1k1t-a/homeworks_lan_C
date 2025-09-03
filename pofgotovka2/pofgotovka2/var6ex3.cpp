
void swap(void* p1, void* p2, size_t size) {
	char* a = (char*)p1;
	char* b = (char*)p2;

	for (int i = 0; i < size; i++) {
		char temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}