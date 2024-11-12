#include <iostream>
#include <vector>
#include <algorithm>

struct Item
{
    int weight;
    int value;
    double valuePerWeight;
};

bool compareItems(Item a, Item b)
{
    return a.valuePerWeight > b.valuePerWeight;
}

double fractionalKnapsack(std::vector<Item>& items, int capacity)
{
    for (Item& item : items) 
    {
        item.valuePerWeight = static_cast<double>(item.value) / item.weight;
    }

    std::sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item& item : items)
    {
        if (currentWeight + item.weight <= capacity)
        {

            totalValue += item.value;
            currentWeight += item.weight;
        } 
        else
        {

            int remainingCapacity = capacity - currentWeight;
            double fraction = static_cast<double>(remainingCapacity) / item.weight;
            totalValue += item.value * fraction;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n;
    int capacity;

    std::cout << "Enter the number of items: ";
    std::cin >> n;

    std::vector<Item> items(n);

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Enter the weight and value for item " << i + 1 << ": ";
        std::cin >> items[i].weight >> items[i].value;
    }

    std::cout << "Enter the capacity of the knapsack: ";
    std::cin >> capacity;

    double maxTotalValue = fractionalKnapsack(items, capacity);
    std::cout << "Maximum total value: " << maxTotalValue << std::endl;

    return 0;
}
