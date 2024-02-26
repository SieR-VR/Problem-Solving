#include <iostream>

using namespace std;

int n;
int arr[500000];
int temp[500000];

long long result = 0;

void merge(int start, int last)
{
    int mid = (start + last) / 2;
    int i = start;
    int j = mid + 1;
    int k = start;

    int count = 0;

    while (i <= mid && j <= last) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
            result += (long long)count;
        }
        else {
            temp[k++] = arr[j++];
            count++;
        }
    }

    if (i > mid) {
        while (j <= last) {
            temp[k++] = arr[j++];
            count++;
        }
    }
    else {
        while(i <= mid) {
            temp[k++] = arr[i++];
            result += (long long)count;
        }
    }

    for (int i = start; i <= last; i++)
        arr[i] = temp[i];
}

void sort(int start, int last)
{
    if (start < last) {
        int mid = (start + last) / 2;
        sort(start, mid);
        sort(mid + 1, last);
        merge(start, last);
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    sort(0, n-1);

    cout << result;
}