#include <stdio.h>
#include <stdlib.h>

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
        printf("7. Sap xep mang theo thu tu giam dan (Insertion Sort)\n");
        printf("8. Tim kiem phan tu bang Binary Search\n");
        printf("9. Dao nguoc thu tu cac phan tu trong mang\n");
        printf("10. Thoat chuong trinh\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu trong mang: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Mang rong.\n");
                } else {
                    printf("Cac phan tu trong mang: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 3: {
                if (n == 0) {
                    printf("Mang rong.\n");
                } else {
                    int count = 0;
                    for (int i = 0; i < n; i++) {
                        int prime = 1;
                        if (arr[i] < 2) prime = 0;
                        for (int j = 2; j * j <= arr[i]; j++) {
                            if (arr[i] % j == 0) {
                                prime = 0;
                                break;
                            }
                        }
                        if (prime) count++;
                    }
                    printf("So luong so nguyen to: %d\n", count);
                }
                break;
            }

            case 4: {
                if (n == 0 || n == 1) {
                    printf("Mang khong du phan tu de tim gia tri nho thu hai.\n");
                } else {
                    int min = 1000000, secondMin = 1000000;
                    for (int i = 0; i < n; i++) {
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
            }

            case 5:
                if (n >= 100) {
                    printf("Mang da day. Khong the them phan tu moi.\n");
                } else {
                    printf("Nhap gia tri phan tu can them: ");
                    scanf("%d", &x);
                    printf("Nhap vi tri can them (0 - %d): ", n);
                    scanf("%d", &pos);
                    if (pos < 0 || pos > n) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = n; i > pos; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[pos] = x;
                        n++;
                    }
                }
                break;

            case 6:
                if (n == 0) {
                    printf("Mang rong. Khong the xoa phan tu.\n");
                } else {
                    printf("Nhap vi tri can xoa (0 - %d): ", n - 1);
                    scanf("%d", &pos);
                    if (pos < 0 || pos >= n) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = pos; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                    }
                }
                break;

            case 7:
                if (n == 0) {
                    printf("Mang rong. Khong the sap xep.\n");
                } else {
                    for (int i = 1; i < n; i++) {
                        int key = arr[i];
                        int j = i - 1;
                        while (j >= 0 && arr[j] < key) {
                            arr[j + 1] = arr[j];
                            j--;
                        }
                        arr[j + 1] = key;
                    }
                    printf("Mang sau khi sap xep giam dan: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 8:
                if (n == 0) {
                    printf("Mang rong. Khong the tim kiem.\n");
                } else {
                    printf("Nhap gia tri can tim: ");
                    scanf("%d", &x);
                    int left = 0, right = n - 1, found = 0;
                    while (left <= right) {
                        int mid = (left + right) / 2;
                        if (arr[mid] == x) {
                            printf("Phan tu %d duoc tim thay tai vi tri %d\n", x, mid);
                            found = 1;
                            break;
                        } else if (arr[mid] < x) {
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }
                    if (!found) {
                        printf("Khong tim thay phan tu %d\n", x);
                    }
                }
                break;

            case 9:
                if (n == 0) {
                    printf("Mang rong. Khong the dao nguoc.\n");
                } else {
                    for (int i = 0; i < n / 2; i++) {
                        int temp = arr[i];
                        arr[i] = arr[n - i - 1];
                        arr[n - i - 1] = temp;
                    }
                    printf("Mang sau khi dao nguoc: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 10:
                printf("Thoat chuong trinh.\n");
                exit(0);

            default:
                printf("Lua chon khong hop le!\n");
        }
    }
    return 0;
}


