#include <stdio.h>
#include <limits.h>

#define MAX 50

int PQ[MAX];
int FRONT = -1;
int REAR = -1;

void insert(int ITEM)
{
    if (REAR == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (FRONT == -1)
    {
        FRONT = 0;
    }

    REAR = REAR + 1;
    PQ[REAR] = ITEM;
    printf("Inserted Item = %d\n", ITEM);
}

int findMax()
{
    if (FRONT == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int highestPriority = INT_MIN;
    int INDEX = -1;

    for (int i = FRONT; i <= REAR; i++)
    {
        if (PQ[i] > highestPriority)
        {
            highestPriority = PQ[i];
            INDEX = i;
        }
    }

    return INDEX;
}

void deleteItem()
{
    if (FRONT == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    int INDEX = findMax();

    /* Extra safety check in case FindMax returns -1 */
    if (INDEX == -1)
        return;

    int ITEM = PQ[INDEX];

    /* Shift elements left to close the gap */
    for (int i = INDEX; i < REAR; i++)
    {
        PQ[i] = PQ[i + 1];
    }

    REAR = REAR - 1; /* As elements are shifted */

    /* Reset queue if it becomes empty */
    if (REAR < FRONT)
    {
        FRONT = -1;
        REAR = -1;
    }

    printf("Deleted Item = %d\n", ITEM);
}

int main()
{
    int choice, item;
    do
    {
        printf("\n1.Insert 2.DeleteMax 3.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Item value (Priority): ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            deleteItem();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
