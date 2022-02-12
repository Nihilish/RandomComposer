/*
  ==================================================================================================================

	CappedQueue.h
	Created: 03 Feb 2022 9:09:53pm
	Author:  Nihilish

  ==================================================================================================================
*/

#include <vector>
#include <queue>

#pragma once

/// <summary>
/// Queue like data structure that pushes out the oldest element when
/// the 'cap' threshold has been reached (FIFO).
/// </summary>
/// <typeparam name="T">Element type.</typeparam>
template<class T>
class CappedQueue
{
public:
	CappedQueue(int cap);
	~CappedQueue();

	// MEMBER FUNCTIONS
	//==============================================================================================================
	std::vector<T> getVector() const;
	void push(T pushedElement);

private:
	// MEMBER VARIABLES
	//==============================================================================================================
	int m_Cap;
	std::deque<T> m_Queue;
};

/// <summary>
/// Initializes a new CappedQueue instance.
/// </summary>
/// <typeparam name="T">The type.</typeparam>
/// <param name="cap">The threshold after which older elements should be pushed out.</param>
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

/// <summary>
/// Pushes an element onto the CappedQueue.
/// </summary>
/// <typeparam name="T">The type.</typeparam>
/// <param name="pushedElement">The element to add to the queue.</param>
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

/// <summary>
/// Gets a vector containing the CappedQueue's elements.
/// </summary>
/// <typeparam name="T">The type.</typeparam>
/// <returns>The vector containing the CappedQueue's elements.</returns>
template<class T>
std::vector<T> CappedQueue<T>::getVector() const
{
	std::vector<T> result = std::vector<T>();
	for (T item : m_Queue)
	{
		result.push_back(item);
	}

	return result;
}

