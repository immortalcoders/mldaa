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

double fractionalKnapsack01(std::vector<Item>& items, int capacity)
{
    std::vector<Item> zeroOneItems;
    for (const Item& item : items)
    {
        int itemCount = capacity / item.weight;
        for (int i = 0; i < itemCount; i++)
        {
            zeroOneItems.push_back(item);
        }
    }

    std::sort(zeroOneItems.begin(), zeroOneItems.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item& item : zeroOneItems)
    {
        if (currentWeight + item.weight <= capacity)
        {
            totalValue += item.value;
            currentWeight += item.weight;
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
        items[i].valuePerWeight = static_cast<double>(items[i].value) / items[i].weight;
    }

    std::cout << "Enter the capacity of the knapsack: ";
    std::cin >> capacity;

    double maxTotalValue = fractionalKnapsack01(items, capacity);
    std::cout << "Maximum total value using 0/1 Knapsack: " << maxTotalValue << std::endl;

    return 0;
}
