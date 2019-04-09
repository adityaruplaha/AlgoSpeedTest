#include <ctime>
#include <iostream>

#include <cassert>

#include "test_mgr.h"

using num = unsigned long long;

template <typename T1, typename T2>
num HCF(T1 a, T2 b)
{
	static_assert(std::is_integral_v<T1> && std::is_integral_v<T2>);
	assert(a & b);
	if (a == b) { return a; }

	num x = (a > b ? a : b); // greater
	num y = (a < b ? a : b); // lesser

	while (num r = x % y)
	{
		x = y;
		y = r;
	}

	return y;
}

template <typename T1, typename T2, typename... Tr>
num HCF(T1 a, T2 b, Tr... c)
{
	return HCF(HCF(a, b), std::forward<Tr>(c)...);
}

int main() {
	TestManager<num, num, num, num> mgr{};
	mgr.addTest(new Test(&HCF<num, num, num>));
	mgr.start(256242050, 675125795275, 1611561616);
	// wait
	std::this_thread::sleep_for(std::chrono::seconds(2));
	mgr.results();
	return 0;
}