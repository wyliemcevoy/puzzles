#pragma once
#include <stack>
namespace puzzles {

	template<class T>
	class DoubleStackQueue
	{
	public:
		DoubleStackQueue() : is_reversed_(false) {}
		~DoubleStackQueue() {}

		void push(const T & data);
		T top();
		void pop();
		int size();
		bool empty();

		//TODO: move & copy
	private:
		bool is_reversed_; // could be handled with a state machine patern
		std::stack<T> main_;
		std::stack<T> other_;

		void flip();
	};
}


template<class T>
void puzzles::DoubleStackQueue<T>::flip()
{
	if (is_reversed_)
	{
		while (!other_.empty())
		{
			main_.push(other_.top());
			main_.pop();
		}
	}
	else
	{
		while (!main_.empty())
		{
			other_.push(main_.top());
			other_.pop();
		}
	}

	is_reversed_ = !is_reversed_;
}


template<class T>
void puzzles::DoubleStackQueue<T>::push(const T & data)
{
	if (is_reversed_)
	{
		flip();
	}
	main_.push(data);
}

template<class T>
T puzzles::DoubleStackQueue<T>::top()
{
	if (is_reversed_)
	{
		return other_.top();
	}
	else
	{
		return main_.top();
	}
}

template<class T>
inline void puzzles::DoubleStackQueue<T>::pop()
{
	if (!is_reversed_)
	{
		flip();
	}
	other_.pop();
}

template<class T>
inline int puzzles::DoubleStackQueue<T>::size()
{
	if (is_reversed_)
	{
		return other_.size();
	}
	else
	{
		return main_.size();
	}
}


template<class T>
inline bool puzzles::DoubleStackQueue<T>::empty()
{
	if (is_reversed_)
	{
		return (other_.size() == 0);
	}
	else
	{
		return (main_.size() == 0);
	}
}