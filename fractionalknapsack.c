#include <stdio.h>

typedef struct
{
    int weight;
    int value;
    float ratio;
} Item;

void sortItems(Item items[], int n)
{
    int i, j;
    Item temp;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(Item items[], int n, int capacity)
{
    int i;
    float totalValue = 0.0;
    float currentWeight = 0.0;

    for (i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= capacity)
        {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            int remainingWeight = capacity - currentWeight;
            totalValue += (remainingWeight / (float)items[i].weight) * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n, capacity, i;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++)
    {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
        printf("Value: ");
        scanf("%d", &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    sortItems(items, n);

    float maxValue = fractionalKnapsack(items, n, capacity);

    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    return 0;
}

/*


In this code, the user is prompted to enter the number of items, weight, and value of each item, as well as the knapsack capacity. The Item structure represents each item with its weight, value, and ratio (value/weight). The sortItems function sorts the items based on their ratios in descending order. The fractionalKnapsack function implements the fractional knapsack algorithm, considering the capacity constraint. Finally, the main function reads user inputs, sorts the items, and calculates the maximum value that can be achieved in the knapsack.

*/