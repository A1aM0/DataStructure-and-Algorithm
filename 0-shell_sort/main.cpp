#include <iostream>

void sort(int a[]){
    int result[INT8_MAX];
    int i,j,gap;
    int n = sizeof(a);

    // gap为步长，每次减为原来的一半。
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        // 共gap个组，对每一组都执行直接插入排序
        for (i = 0 ;i < gap; i++)
        {
            for (j = i + gap; j < n; j += gap)
            {
                // 如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
                if (a[j] < a[j - gap])
                {
                    int tmp = a[j];
                    int k = j - gap;
                    while (k >= 0 && a[k] > tmp)
                    {
                        a[k + gap] = a[k];
                        k -= gap;
                    }
                    a[k + gap] = tmp;
                }
            }
        }

    }
    std::cout<<*result;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    int array[] = {5, 3, 9, 12, 6, 1, 7, 2, 4, 11, 8, 10};
    sort(array);
    return 0;
}