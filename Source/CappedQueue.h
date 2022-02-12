#include <vector>
#include <queue>

#pragma once

template<class T>
class CappedQueue
{
public:
	CappedQueue(int cap);
	~CappedQueue();

	void push(T pushedElement);
	std::vector<T> get() const;

private:
	int m_Cap;
	std::deque<T> m_Queue;
};

template <class T>
CappedQueue<T>::CappedQueue(int cap) :
	m_Cap(cap),
	m_Queue()
{
}

template<class T>
CappedQueue<T>::~CappedQueue()
{
}

template<class T>
void CappedQueue<T>::push(T pushedElement)
{
	if (m_Queue.size() < m_Cap)
		m_Queue.push_back(pushedElement);
	else
	{
		m_Queue.pop_front();
		m_Queue.push_back(pushedElement);
	}
}

template<class T>
std::vector<T> CappedQueue<T>::get() const
{
	std::vector<T> result = std::vector<T>();
	for (T item : m_Queue)
	{
		result.push_back(item);
	}

	return result;
}

