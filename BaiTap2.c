
void Occurrences(int arr[],int n, int resultArr[][100]) {
	for (int i = 0; i < n; i++)
	{
		int j = -1;
	forwrd:
		j++;
		if (resultArr[0][j] < -10000) {
			resultArr[0][j] = arr[i];
			resultArr[1][j] = 1;
		}
		else if (resultArr[0][j] == arr[i])
		{
			resultArr[1][j]++;
		}
		else goto forwrd;
		
	}
}
void InputArray(int arr[], int n)
{
	int* index = arr--;
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap gia tri [%d]=", i);
		scanf("%d", index);
		index++;
	}
}
int main(){
	int n;
	int arr[MAX_COLS], arrCount[2][MAX_COLS];
	printf("Nhap n: ");
	scanf("%d", &n);
	InputArray(arr, n);
	Occurrences(arr, n, arrCount);
	int i=0;
	do
	{
		printf("%d - %d; ", arrCount[0][i], arrCount[1][i]);
	} while (arrCount[0][i] > -100000);
}