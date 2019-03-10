#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int getCheapestCost( Node *rootNode )
{
   // your code goes here
  if (!rootNode) return 0;

  int min_cost = numeric_limits<int>::max();
  queue<tuple<int,Node*>> level_order;
  tuple<int,Node*> temp = make_tuple(0,rootNode);
  level_order.push(temp);

  // Time: O(N + (N-1)) == O(N)
  // Space: O(N-1) == O(N)

  while (!level_order.empty()) {
    temp = level_order.front();
    level_order.pop();

    int parent_costs = get<0>(temp);
    Node* curr_node = get<1>(temp);
    int accum = parent_costs + curr_node->cost;

    if (curr_node->children.empty()) {
      min_cost = min(min_cost, accum);
    }
    else {
      for (size_t i=0; i<curr_node->children.size(); ++i) {
        tuple<int,Node*> child = make_tuple(accum, curr_node->children[i]);
        level_order.push(child);
      }
    }
  }
  return min_cost;
}

int main()
{
    return 0;
}
