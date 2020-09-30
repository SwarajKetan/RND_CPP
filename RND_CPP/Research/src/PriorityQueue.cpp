#include "Runnable.h"
#include <queue>
#include <iostream>
namespace PriorityQueue {

	struct Priority_Q : public Runnable {


		// Inherited via Runnable
		virtual void Run() override
		{

			int arr[] = { 10, 6, 7, 3, 8, 9, 1, 2};

			//auto comp = [](const int x, const int y)-> bool { return x > y; };

			std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
			std::priority_queue<int> pq2;

			for (auto num : arr)
			{
				pq.push(num);
				pq2.push(num);
			}

			while (!pq.empty())
			{
				std::cout << pq.top() << " " ;
				pq.pop();
			}
			std::cout << std::endl;

			while (!pq2.empty())
			{
				std::cout << pq2.top() << " ";
				pq2.pop();
			}

			std::cout << std::endl;
		}

	};
}