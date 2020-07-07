/*
https://www.geeksforgeeks.org/fractional-knapsack-problem/

Given weights and values of n items,
we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

Input:

Items as (value, weight) pairs
arr[] = {{60, 10}, {100, 20}, {120, 30}}
Knapsack Capacity, W = 50;

Output:

Maximum possible value = 240
by taking items of weight 10 and 20 kg and 2/3 fraction
of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

The basic idea of the greedy approach is to calculate the ratio value/weight
for each item and sort the item on basis of this ratio.
Then take the item with the highest ratio and add them until we can’t add the next item as a whole and at the end add the next item as much as we can.
Which will always be the optimal solution to this problem.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item
{
    int _weight;
    int _value;

    Item(int w = 0, int v = 0)
        : _weight(w), _value(v)
    {

    }
};

double SolveFractionalKnapsackProblem(std::vector<Item> items, int W)
{
    std::sort
    (
        items.begin(), 
        items.end(), 
        [](const Item &I1, const Item &I2)
        {
            double ratio1 = (double)I1._value / I1._weight;
            double ratio2 = (double)I2._value / I2._weight;

            return ratio1 > ratio2;
        }
    );

    int curWeight = 0;
    double maxValue = 0.0;
    for (Item I : items)
    {
        // If adding next item won't overflow, add it completely
        if (curWeight + I._weight <= W)
        {
            curWeight += I._weight;
            maxValue += I._value;
        }
        // If we can't add a completely item, add fractional part of it
        else
        {
            W -= curWeight;
            maxValue += (I._value) * ((double)W / I._weight);
            break;
        }
    }

    return maxValue;
}

int main()
{
    int W = 50;
    std::vector<Item> items = { {10, 60}, {20, 100}, {30, 120} };

    std::cout << SolveFractionalKnapsackProblem(items, W) << std::endl;    

    return 0;
}