#pragma once

#include <deque>
#include <cstdint>
#include <tuple>
#include <algorithm>

template<class T>
class PriorityIndexedQue {
public:
	typedef std::int64_t Priority;
protected:
	typedef std::tuple<Priority, T> Item;
public:

	bool Pop() {
		if (!D.size()) { return false; }
		D.pop_front();
		return true;
	}
	bool Push(const T& In,const Priority& P) {
		D.push_back({ P,In });

		std::sort(D.begin(), D.end(), [](auto& A, auto& B) {return std::get<0>(A) < std::get<0>(B); });

		return true;
	}
	const Item& Front() {
		return  D.front();
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