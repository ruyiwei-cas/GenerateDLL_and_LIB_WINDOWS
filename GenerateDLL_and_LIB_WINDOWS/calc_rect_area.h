#pragma once
#include<iostream>
#include<algorithm>
using namespace std;
#ifdef __linux__
#define FUNCTION_EXPORT __attribut__ ((visibility("default")))
#else
#define FUNCTION_EXPORT __declspec(dllexport)
#endif // __linux || __linux__

FUNCTION_EXPORT
int calcRectArea(int width, int height);
