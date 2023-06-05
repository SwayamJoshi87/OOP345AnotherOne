#include "Queue.h"

#ifndef SDDS_UNIQUEUE_H_
#define SDDS_UNIQUEUE_H_

namespace sdds {

	template <typename T>
	class UniqueQueue : public Queue<T, 100u>
	{
	public:
		//Override the push function to check if the item is already in the queue
		bool push(const T& item) override {
			for (unsigned int i = 0; i < this->size(); i++) {
				//If the item is already in the queue, return false
				if (this->m_queue[i] == item) {
					return false;
				}
			}
			return Queue<T, 100u>::push(item);
		}
	};

	//Specialization when T is a double
	template <>
	class UniqueQueue<double> : public Queue<double, 100u>
	{
	public:
		bool push(const double& item) override {
			for (unsigned int i = 0; i < this->size(); ++i) {
				//check if difference between items is less than or equal to 0.005
				double newItem = std::fabs(this->m_queue[i] - item);
				if (newItem <= 0.005) {
					return false;
				}
			}
			return Queue<double, 100u>::push(item);
		}
	};

};

#endif // !SDDS_UNIQUEUE_H_
