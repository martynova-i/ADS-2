// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == value)
                count++;
}
    return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0, l = 0, r = len - 1;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (arr[mid] <= value)
            l = mid;
        else
            r = mid;
    }
    len = r - 1;
    for (int i = len; i >= 0; i--) {
        for (int j = 0; j < i; j++)
            if (arr[i] + arr[j] == value)
                count++;
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0, l = 0, r = len - 1;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (arr[mid] <= value)
            l = mid;
        else
            r = mid;
    }
    len = r - 1;

    for (int i = 0; i < len; i++) {
        int l = i, r = len, mid;
        while (l < r - 1) {
            mid = (l + r) / 2;
            if (arr[i] + arr[mid] == value) {
                count++;

                int j = mid + 1;
                while ((arr[i] + arr[mid] == value) && j < r) {
                    count++;
                    j++;
                }

                j = mid - 1;
                while ((arr[i] + arr[mid] == value) && j > i) {
                    count++;
                    j--;
                }
                break;
            }
            if (arr[i] + arr[mid] > value)
                l = mid;
            else
                r = mid;
        }
    }
    return count;
}
