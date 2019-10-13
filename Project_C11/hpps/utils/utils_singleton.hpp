// 实现基于以下假设：良好的设计在进入main函数之前应该是单线程的，
// 因此可以使用全局变量的方式来设计singleton，
// 并且保证在使用该singleton之前其已经被正确的初始化。
#pragma once

template <typename T>
class Singleton
{
public:
	struct object_creator
	{
		object_creator() { Singleton<T>::instance(); }
		inline void do_nothing()const {}
	};

	static object_creator create_object;

	typedef T object_type;

	static object_type& instance()
	{
		static object_type obj;
		create_object.do_nothing();
		return obj;
	}
};

template <typename T> typename Singleton<T>::object_creator
Singleton<T>::create_object;

