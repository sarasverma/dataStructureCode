#include <stdio.h>
#include <stdlib.h>

#define MAX 30
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int size, int i)
{
    if (size == 1)
    {
        puts("Single element present in the array");
    }
    else
    {
        int largest = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < size && array[left] > array[largest])
            largest = left;
        if (right < size && array[right] > array[largest])
            largest = right;

        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
}

void insert(int array[], int element)
{
    if (size == 0)
    {
        array[0] = element;
        size++;
    }
    else
    {
        array[size] = element;
        size++;
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(array, size, i);
    }
}

void delete (int array[], int element)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == element)
            break;
    }
    if (i == size)
        puts("Element not found");
    else
    { // swap deleted element with last added element.
        swap(&array[i], &array[size]);
        size--;
        for (i = size / 2 - 1; i >= 0; i--)
            heapify(array, size, i);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\t", array[i]);
    printf("\n");
}

int main()
{
    // array representation of tree.
    // because it is more easy.
    int tree[MAX], choice, element;
    while (1)
    {
        printf("1.INSERT\t2.DELETE\t3.TRAVERSAL\t4.EXIT\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be inserted :");
            scanf("%d", &element);
            insert(tree, element);
            break;

        case 2:
            printf("Enter element to be deleted :");
            scanf("%d", &element);
            delete (tree, element);
            break;

        case 3:
            printArray(tree, size);
            break;

        case 4:
            exit(0);
            break;

        default:
            puts("Invalid choice");
        }
    }

    return 0;
}