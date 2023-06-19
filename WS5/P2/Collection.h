#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_

namespace sdds {

	template <typename T>
	class Collection {
		std::string m_name;	
		T* m_items;
		size_t m_size;
		void (*m_observer)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection(std::string name) : m_name(name), m_items(nullptr), m_size(0) {};
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection() {
			if(m_items)
			delete[] m_items;
		}
		const std::string& name() const {
			return m_name;
		}
		size_t size() const {
			return m_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool found = false;
			for (size_t i = 0; i < m_size; i++) {
				if (m_items[i].title() == item.title()) {
					found = true;
				}
			}
			if (!found) {
				T* temp = new T[m_size + 1];
				for (size_t i = 0; i < m_size; i++) {
					temp[i] = m_items[i];
				}
				temp[m_size] = item;
				delete[] m_items;
				m_items = temp;
				m_size++;
				if (m_observer != nullptr) {
					m_observer(*this, item);
				}
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= m_size) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
			}
			return m_items[idx];
		}
		T* operator[](std::string title) const {
			
			
			for (size_t i = 0; i < m_size; i++) {
				if (m_items[i].title() == title) {
					return &m_items[i];
				}
			}
			
			return nullptr;
			

		}
		friend std::ostream& operator<<(std::ostream& os, const Collection& collection) {
			for (size_t i = 0; i < collection.m_size; i++) {
				os << collection.m_items[i];		
			}
			return os;
		}
	};

}

#endif // !SDDS_SPELLCHECKER_H_
