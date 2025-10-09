#include <iostream>
#include <algorithm>

/*

********************************************************************************
* Knapsack:
* The Knapsack Problem is an optimization problem where we aim to maximize total
* value of items placed in a bag with a limited weight capacity.
*
* Each item has a value and a weight. We must decide which items to include
* so that the total value is maximized without exceeding the weight capacity.
*
* Uses of Knapsack:
* 1. **Resource Allocation** – Choosing best combination of resources under constraints.
* 2. **Algorithm Practice** – A classic problem to learn recursion, dynamic programming, 
*    and optimization.
* 3. **Logistics & Finance** – Selecting optimal items, investments, or loads within limits.
* 4. **Real-World Optimization** – Used in budgeting, scheduling, and decision making.
********************************************************************************

PSEUDOCODE KnapsackTail(values[], weights[], n, W)
    // Base case: no items left or no remaining capacity
    IF n == 0 OR W == 0 THEN
        RETURN 0

    // If current item weight exceeds capacity, skip it
    IF weights[n-1] > W THEN
        RETURN KnapsackTail(values, weights, n-1, W)

    // Tail recursive: last operation chooses max value including/excluding current item
    INCLUDE = values[n-1] + KnapsackTail(values, weights, n-1, W - weights[n-1])
    EXCLUDE = KnapsackTail(values, weights, n-1, W)

    RETURN MAX(INCLUDE, EXCLUDE)
END PSEUDOCODE

PSEUDOCODE KnapsackHead(values[], weights[], n, W)
    // Base case
    IF n == 0 OR W == 0 THEN
        RETURN 0

    // Recursive calls first
    PREV_INCLUDE = KnapsackHead(values, weights, n-1, W - weights[n-1])  // if item included
    PREV_EXCLUDE = KnapsackHead(values, weights, n-1, W)                  // if item excluded

    // Then process the current item decision
    IF weights[n-1] > W THEN
        RETURN PREV_EXCLUDE
    ELSE
        RETURN MAX(values[n-1] + PREV_INCLUDE, PREV_EXCLUDE)
        
END PSEUDOCODE

********************************************************************************
*/


using namespace std;

int knapsack_tail_recursion(int capacity, int weights[], int values[], int n) {
    if (n == 0 || capacity == 0) return 0;

    if (weights[n - 1] > capacity) return knapsack_tail_recursion(capacity, weights, values, n - 1);

    int include = values[n - 1] + knapsack_tail_recursion(capacity - weights[n - 1], weights, values, n - 1);
    int exclude = knapsack_tail_recursion(capacity, weights, values, n - 1);

    return max(include, exclude);
}


int knapsack_head_recursion(int capacity, int weights[], int values[], int n) {
    if (n == 0 || capacity == 0) return 0;

    int include = 0, exclude = 0;

    if (weights[n - 1] <= capacity) {
        include = values[n - 1] + knapsack_head_recursion(capacity - weights[n - 1], weights, values, n - 1);
    }
        
    exclude = knapsack_head_recursion(capacity, weights, values, n - 1);

    return max(include, exclude);
}


int knapsack_iterative(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}


int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    cout << "Tail Recursion Result  : " << knapsack_tail_recursion(capacity, weights, values, n) << endl;
    cout << "Head Recursion Result  : " << knapsack_head_recursion(capacity, weights, values, n) << endl;
    cout << "Iterative Result       : " << knapsack_iterative(capacity, weights, values, n) << endl;

    return 0;
}
