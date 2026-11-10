#include <stdio.h>

int main()
{
    int arr[100];
    int n, i;
    int sum = 0;
    int largest, smallest;
    float average;

    // Get the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Check whether the size is valid
    if (n <= 0 || n > 100)
    {
        printf("Invalid array size!\n");
        return 0;
    }

    // Read array elements
    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the array
    printf("\nArray elements are:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Initialize largest and smallest
    largest = arr[0];
    smallest = arr[0];

    // Calculate sum, largest and smallest
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (arr[i] > largest)
        {
            largest = arr[i];
        }

        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    // Calculate average
    average = (float)sum / n;

    // Display results
    printf("\n\nSum = %d", sum);
    printf("\nAverage = %.2f", average);
    printf("\nLargest element = %d", largest);
    printf("\nSmallest element = %d", smallest);

    return 0;
}
sample input:Enter the number of elements: 5
Enter 5 elements:
Element 1: 10
Element 2: 20
Element 3: 30
Element 4: 40
Element 5: 50
sample output:
Array elements are:
10 20 30 40 50

Sum = 150
Average = 30.00
Largest element = 50
Smallest element = 10
