#pragma once

#include <deque>
#include <cstdint>
#include <tuple>
#include <algorithm>

template<class T, class Priority = std::intmax_t >
class PriorityIndexedQue {
public:
	//ypedef std::int64_t Priority;
protected:
	typedef std::tuple<Priority, T> Item;
public:
	enum Order{
		UltlaHigh=-100,
		High=1,
		Middle=0x71000000,
		Low=0x7f000000,
		UltlaLow=0x7ff00000
	};
public:

	bool Pop() {
		if (!D.size()) { return false; }
		D.pop_front();
		return true;
	}
	bool Push(const T& In,const Priority& P) {
		D.push_back({ P,In });

		std::stable_sort(D.begin(), D.end(), [](auto& A, auto& B) {return std::get<0>(A) < std::get<0>(B); });//0 is priority High.

		return true;
	}
	const Item& Front() {
		return  D.front();
	}

	Priority TailPriority() {
		return std::get<0>(D.back());
	}

	const Item& operator[](std::size_t In) {
		return D[In];
	}

	typename std::deque<Item>::const_iterator begin() {
		return D.cbegin();
	}
	typename std::deque<Item>::const_iterator end() {
		return D.cend();
	}

	std::size_t Size() {
		return D.size();
	}
protected:
	std::deque<Item> D;
};