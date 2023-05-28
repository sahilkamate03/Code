#include <bits/stdc++.h>
using namespace std;
long long ans =0;

void merge(int arr[], int p, int q, int r) {

	// long long int ans = 0;

	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], M[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];

	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = M[j];
		j++;
		k++;
	}

	for (int i = 0; i < n2; i++)
	{
		int c = n1-1;
		if (M[i] < L[c])
		{
			ans++;c--;
			while(M[i]<L[c] && c>=0)
			{
				ans++;
				c--;
			}
		}
		else
			break;
	}

	// return ans;
}

void mergeSort(int arr[], int l, int r) {
	// long long int ans =0;
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		// merge(arr, l, m, r);
		merge(arr, l, m, r);
		// cout << l << " " <<r << endl;
	}
	// cout << ans << endl;
}

int main()
{
	int arr[] = {2, 5, 1, 3, 4};
	int size = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, size - 1);

	// for (int i = 0; i < size; i++)
	// {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	cout << ans << endl;
	return 0;
}