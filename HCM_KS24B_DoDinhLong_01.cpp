 					#include <stdio.h>
					#include <stdlib.h>

int printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int isPrime(int n) {
    if (n < 2) return 0;
    int i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int countPrimes(int arr[], int n) {
    int count = 0, i;
    for (i = 0; i < n; i++) {
        if (isPrime(arr[i])) count++;
    }
    return count;
}

int insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return 0;
}

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int deleteAtPosition(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) return -1;
    int i;
    for (i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return 0;
}

int insertAtPosition(int arr[], int *n, int x, int pos) {
    if (pos < 0 || pos > *n) return -1;
    int i;
    for (i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = x;
    (*n)++;
    return 0;
}

int reverseArray(int arr[], int n) {
    int i, temp;
    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    return 0;
}

int main() {
    int arr[100], n = 0, choice, x, pos;

    while (1) {
        																		printf("\n=*=*=*=*= MENU =*=*=*=*=\n");
       																		 printf("1. Nhap so phan tu va gia tri cho mang\n");
        																	printf("2. In ra gia tri cac phan tu trong mang\n");
        																printf("3. Dem so luong cac so nguyen to trong mang\n");
        															printf("4. Tim gia tri nho thu hai trong mang\n");
        														printf("5. Them mot phan tu vao vi tri bat ky trong mang\n");
        													printf("6. Xoa phan tu tai mot vi tri bat ky trong mang\n");
        												printf("7. Sap xep mang theo thu tu giam dan Insertion Sort\n");
        											printf("8. Tim kiem phan tu bang Binary Search\n");
        										printf("9. Dao nguoc thu tu cac phan tu trong mang\n");
        									printf("10. Thoat chuong trinh\n");
        								printf("Lua chon cua ban: ");
        						scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu trong mang: ");
                scanf("%d", &n);
                int i;
                for (i = 0; i < n; i++) {
                    printf("Nhap arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                printf("Cac phan tu trong mang: ");
                printArray(arr, n);
                break;

            case 3:
                printf("So luong so nguyen to: %d\n", countPrimes(arr, n));
                break;

            case 4:
                {
                    int min = 1000000, secondMin = 1000000;
                    for (i = 0; i < n; i++) {
                        if (arr[i] < min) {
                            secondMin = min;
                            min = arr[i];
                        } else if (arr[i] < secondMin && arr[i] != min) {
                            secondMin = arr[i];
                        }
                    }
                    if (secondMin == 1000000) {
                        printf("Khong co gia tri nho thu hai.\n");
                    } else {
                        printf("Gia tri nho thu hai: %d\n", secondMin);
                    }
                }
                break;

            case 5:
                printf("Nhap gia tri phan tu can them: ");
                scanf("%d", &x);
                printf("Nhap vi tri can them 0 - %d: ", n);
                scanf("%d", &pos);
                if (insertAtPosition(arr, &n, x, pos) == -1) {
                    printf("Vi tri khong hop le!\n");
                }
                break;

            case 6:
                printf("Nhap vi tri can xoa 0 - %d: ", n - 1);
                scanf("%d", &pos);
                if (deleteAtPosition(arr, &n, pos) == -1) {
                    printf("Vi tri khong hop le!\n");
                }
                break;

            case 7:
                insertionSort(arr, n);
                printf("Mang sau khi sap xep giam dan: ");
                for (i = n - 1; i >= 0; i--) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 8:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                pos = binarySearch(arr, n, x);
                if (pos != -1) {
                    printf("Phan tu %d duoc tim thay tai vi tri %d\n", x, pos);
                } else {
                    printf("Khong tim thay phan tu %d\n", x);
                }
                break;

            case 9:
                reverseArray(arr, n);
                printf("Mang sau khi dao nguoc: ");
                printArray(arr, n);
                break;

            case 10:
                printf("Thoat chuong trinh.\n");
                exit(10);

            default:
                printf("Lua chon khong hop le!\n");
        }
    }
    return 0;
}


