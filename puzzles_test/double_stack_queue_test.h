#pragma once
#include "gtest/gtest.h"
#include "double_stack_queue.h"



class DoubleStackQueueTest : public ::testing::Test
{
public:
	DoubleStackQueueTest();
	~DoubleStackQueueTest();

	puzzles::DoubleStackQueue<int> queue_;
};

