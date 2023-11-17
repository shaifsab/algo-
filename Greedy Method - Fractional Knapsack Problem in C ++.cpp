#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Structure to represent an item
struct Item {
    int weight, value;
};

// Function to compare items based on their value-to-weight ratio
bool itemCompare(const Item &a, const Item &b) {
    double ratioA = static_cast<double>(a.value) / a.weight;
    double ratioB = static_cast<double>(b.value) / b.weight;
    return ratioA > ratioB;  // Sort in descending order of value-to-weight ratio
}

// Function to solve the Fractional Knapsack Problem
double fractionalKnapsack(vector<Item> items, int capacity) {
    // Sort items based on value-to-weight ratio
    sort(items.begin(), items.end(), itemCompare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item &item : items) {
        // If adding the entire item doesn't exceed the capacity, add it
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Add a fraction of the item to fill the knapsack to its capacity
            double remainingCapacity = capacity - currentWeight;
            totalValue += (remainingCapacity / item.weight) * item.value;
            break;  // Knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    // Example items
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;

    // Function call
    double maxValue = fractionalKnapsack(items, capacity);

    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
