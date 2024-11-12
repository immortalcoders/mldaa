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
    for ( const Item& item : items)
    {
        int itemCount = capacity / item.weight;
        for (int i=0; i < itemCount; i++)
        {
            zeroOneItems.push_back(item);
        }
    }
    
}

int main()
{
    
}