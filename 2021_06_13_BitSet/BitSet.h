#pragma once
#include <vector>
namespace czh
{
	template<size_t N>
	class bitset
	{
	private:
		std::vector<char> _bits;
	public:
		bitset()
		{
			_bits.resize((N >> 3) + 1, 0);
		}
		void set(size_t x)
		{
			// 将 x 对应的位设置为1
			size_t index = x >> 3;
			size_t num = x % 8;
			_bits[index] |= (1 << num);

		}
		void reset(size_t x)
		{
			size_t index = x / 8;
			size_t num = x % 8;
			_bits[index] &= (~(1 << num));
		}
		bool test(size_t x)
		{
			size_t index = x / 8;
			size_t num = x % 8;
			return _bits[index] & (1 << num);
		}
	};
	void test_bitset()
	{
		bitset<100> bs;
		bs.set(10);
		bs.set(17);
		bs.set(80);

		cout << bs.test(10) << endl;
		cout << bs.test(17) << endl;
		cout << bs.test(80) << endl;
		cout << bs.test(81) << endl << endl;

		bs.reset(80);
		bs.set(81);

		cout << bs.test(10) << endl;
		cout << bs.test(17) << endl;
		cout << bs.test(80) << endl;
		cout << bs.test(81) << endl;

	}
}