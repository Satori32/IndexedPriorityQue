#include <iostream>

#include "PriorityIndexedQue.h"

int main() {
	PriorityIndexedQue<int> PIQ;
	std::size_t L = 7;
	for (size_t i = 0; i < L; i++){
		PIQ.Push(i, L-i);
	}
	std::cout <<"Tail:"<<PIQ.TailPriority()<< std::endl;
	for (auto& o : PIQ) {
			std::cout <<"P:"<< std::get<0>(o) << ',' <<"V:"<< std::get<1>(o) << std::endl;
	}

	std::cout << std::endl;

	while (PIQ.Size()) {
		for (auto& o : PIQ) {
			std::cout <<"P:"<< std::get<0>(o) << ',' <<"V:"<< std::get<1>(o) << std::endl;
		}
		PIQ.Pop();	
		std::cout << std::endl;

	}
	std::cout << std::endl;

	for (auto& o : PIQ) {
			std::cout <<"P:"<< std::get<0>(o) << ',' <<"V:"<< std::get<1>(o) << std::endl;
	}

	std::cout << std::endl;
	{
		PriorityIndexedQue<int> PQ;

		PQ.Push(30, PQ.Low);
		PQ.Push(31, PQ.Middle);
		PQ.Push(32, PQ.High);
		PQ.Push(33, PQ.UltlaHigh); 		
		PQ.Push(34, PQ.UltlaLow);
	}

	return 0;
}