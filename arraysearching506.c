#include <stdio.h>

int main()
{
    int arr[100];
    int n, i, search;
    int found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &search);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == search)
        {
            printf("\nElement %d found at position %d.\n",
                   search, i + 1);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nElement %d not found in the array.\n", search);
    }

    return 0;
}
