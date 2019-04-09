#pragma once

#include <vector>

#include "test.h"

template<typename rtype, typename... arg_types>
class TestManager
{
public:
	void addTest(Test<rtype, arg_types...>* test) {
		tests.push_back(test);
	}

	void start(arg_types... args) {
		for (auto* t : tests)
		{
			t->launch(args...);
		}
	}

	void results() {
		for (auto* t : tests)
		{
			std::cout << "Result: " << t->get() << "\t" << "Time taken: " << t->time_taken().count()/1000000.0 << "ms\n";
		}
	}

private:
	std::vector<Test<rtype, arg_types...>*> tests;
};
