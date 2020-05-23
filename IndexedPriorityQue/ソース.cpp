#include <iostream>

#include "PriorityIndexedQue.h"

int main() {
	PriorityIndexedQue<int> PIQ;
	std::size_t L = 7;
	for (size_t i = 0; i < L; i++){
		PIQ.Push(i, L-i);
	}

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

	return 0;
}