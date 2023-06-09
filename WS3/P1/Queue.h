#include <iostream>
#include <string>
#include <iomanip>
#include "Dictionary.h"

#ifndef SDDS_QUEUE_H_
#define SDDS_QUEUE_H_

namespace sdds {

	template <typename T, unsigned int N>
	class Queue
	{
		T m_queue[N];
		T garbage = T();
		unsigned int currenSize = 0;

	public:
		Queue() : currenSize{ 0 } {
		}
		bool push(const T& item) {
			//bool result = false;
			if (currenSize < N) {
				m_queue[currenSize] = item; //end of the queue
				currenSize++;
				return true;
			}
			return false;
		}

		T pop() {
			if (currenSize > 0) {
				T removed = m_queue[0]; //first element
				--currenSize;
				//shift the array one step forward
				for (unsigned int i = 0; i < currenSize; i++) {
					m_queue[i] = m_queue[i + 1];
				}
				return removed;
			}
			return garbage;
		}

		unsigned int size() const {
			return currenSize;
		}

		void display(std::ostream& os = std::cout) const {
			os << "----------------------" << std::endl;
			os << "| Dictionary Content |" << std::endl;
			os << "----------------------" << std::endl;
			for (unsigned int i = 0; i < currenSize; i++) {
				os << m_queue[i] << "\n";
			}
			os << "----------------------" << std::endl;
		}

		T operator[](unsigned int i) const {
			if (i < currenSize) { //its inside the bounds
				return m_queue[i];
			}
			return garbage;
		}
	};

	// Specialization for T = Dictionary and CAPACITY = 100u
	template <>
	class Queue<Dictionary, 100u>
	{
		Dictionary m_queue[100u];
		Dictionary garbage;
		unsigned int currenSize;

	public:
		Queue() 
		{
			currenSize = 0;
			garbage.set("Empty Term","Empty Substitute");
		}

		bool push(const Dictionary& item) {
			bool result = false;
			if (currenSize < 100u) {
				m_queue[currenSize] = item;
				currenSize++;
				result = true;
			}
			return result;
		}

		Dictionary pop() {
			if (currenSize > 0) {
				Dictionary removed = m_queue[0];
				--currenSize;
				//shift the array one step forward
				for (unsigned int i = 0; i < currenSize; i++) {
					m_queue[i] = m_queue[i + 1];
				}
				return removed;
			}
			return garbage;
		}

		unsigned int size() const {
			return currenSize;
		}

		void display(std::ostream& os = std::cout) const {
			os << "----------------------" << std::endl;
			os << "| Dictionary Content |" << std::endl;
			os << "----------------------" << std::endl;
			for (unsigned int i = 0; i < currenSize; i++) {
				os << m_queue[i] << "\n";
			}
			os << "----------------------" << std::endl;
			
		}

		Dictionary operator[](unsigned int i) const {
			if (i < 100u) {
				return m_queue[i];
			}
			return garbage;
		}
	};

};

#endif // !SDDS_QUEUE_H_

