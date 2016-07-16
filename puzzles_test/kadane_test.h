#pragma once
#include "gtest\gtest.h"
#include "kadane.h"

class KadaneTest : public ::testing::Test
{
public:
	KadaneTest();
	~KadaneTest();
	void SetUp() override;
	void TearDown() override {}
	std::vector<int> data;
};

