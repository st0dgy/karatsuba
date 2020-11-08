#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testkaratsuba
{
	TEST_CLASS(testkaratsuba)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			t = fmax(1, 1);
		Assert::AreEqual(t, 1);
		}
	};
}
