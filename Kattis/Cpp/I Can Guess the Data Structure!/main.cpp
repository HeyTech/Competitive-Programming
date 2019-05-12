// https://open.kattis.com/problems/guessthedatastructure
#include <iostream>
#include <cstdint>

#include <stack>
#include <queue>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();

  std::uint16_t N, ele;
  while(std::cin >> N){
    bool pStack = true, pQueue = true, pPrioQueue = true;
    std::stack<std::uint16_t> stack;
    std::queue<std::uint16_t> queue;
    std::priority_queue<std::uint16_t> prioQueue;

    while (N--) {
      std::cin >> ele;
      switch (ele) {
        case 1:
          std::cin >> ele;
          if (pStack) stack.push(ele);
          if (pQueue) queue.push(ele);
          if (pPrioQueue) prioQueue.push(ele);
          break;

        case 2: {
          std::cin >> ele;
          if (pStack){
            if (stack.empty() || stack.top() != ele) pStack = false;
            else stack.pop();
          }

          if (pQueue){
            if (queue.empty() || queue.front() != ele) pQueue = false;
            else queue.pop();
          }

          if (pPrioQueue) {
            if (prioQueue.empty() || prioQueue.top() != ele) pPrioQueue = false;
            else prioQueue.pop();
          }

          break;
        }
      }
    }

    std::uint16_t valid = (pStack ? 1 : 0)  + (pQueue ? 1 : 0)  +  (pPrioQueue ? 1 : 0);
    if(valid > 1) printf("not sure\n");
    else if(valid == 0) printf("impossible\n");
    else if(pStack) printf("stack\n");
    else if(pQueue) printf("queue\n");
    else if(pPrioQueue) printf("priority queue\n");
  }
}