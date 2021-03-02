#pragma once
#include <iostream>
using namespace std;

template <class T>
T Add(const T& left, const T& right);

template <class T>
T Add(const T& left, const T& right)
{
	return left + right;
}