#pragma once

#include <chrono>
#include <future>
#include <type_traits>

template<typename rtype, typename... arg_types>
class Test {
public:
	Test(rtype(*func)(arg_types... args)) : func(func) {}
	Test(const Test<rtype, arg_types...>&) = default;

	void launch(arg_types... args) {
		value = std::async(func, args...);
		time = std::async([this]() {
			auto now = std::chrono::high_resolution_clock::now();
			value.wait();
			return std::chrono::high_resolution_clock::now() - now;
		});
	}

	rtype get() {
		if (value.valid())
		{
			return value.get();
		}
		throw std::future_errc::no_state;
	}

	std::chrono::duration<double, std::micro> time_taken() {
		if (time.valid())
		{
			return time.get();
		}
		throw std::future_errc::no_state;
	}
	
private:
	rtype(*func)(arg_types... args);
	std::future<rtype> value;
	std::future<std::chrono::duration<__int64, std::nano>> time;
};