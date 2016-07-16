#include "kadane_test.h"



KadaneTest::KadaneTest()
{
}


KadaneTest::~KadaneTest()
{
}

void KadaneTest::SetUp()
{
	data.push_back(10);
	data.push_back(11);
	data.push_back(-20);
	data.push_back(4);
}

TEST_F(KadaneTest, dummy)
{
	std::tuple<int, int, int> result = puzzles::ExplainedKadane(data);
	ASSERT_EQ(std::get<2>(result), 21);
}
