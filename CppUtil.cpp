/**
 * @file CppUtil.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "CppUtil.h"
#include <math.h>

/**
 * @brief Limits val to range [val_min, val_max]
 * @param val Input value
 * @param val_min Minimum value
 * @param val_max Maximum value
 */
float clamp_limit(float val, float val_min, float val_max)
{
	if(val > val_max)
	{
		return val_max;
	}
	if(val < val_min)
	{
		return val_min;
	}
	return val;
}

/**
 * @brief Modulo (wrap) limits val to range [val_min, val_max]
 * @param val Input value
 * @param val_min Minimum value
 * @param val_max Maximum value
 */
float mod_limit(float val, float val_min, float val_max)
{
	return fmod(val - val_min, val_max - val_min) + val_min;
}

/**
 * @brief Named function for float addition (a + b)
 */
float fadd(float a, float b)
{
	return a + b;
}

/**
 * @brief Named function for float subtraction (a - b)
 */
float fsub(float a, float b)
{
	return a - b;
}

/**
 * @brief Named function for float multiplication (a * b)
 */
float fmul(float a, float b)
{
	return a * b;
}

/**
 * @brief Named function for float division (a / b)
 */
float fdiv(float a, float b)
{
	return a / b;
}

/**
 * @brief Squares floating-point input n
 */
float fsq(float n)
{
	return n * n;
}

/**
 * @brief Computes arithmetic mean of array
 * @param arr Array of numbers
 * @param len Length of array
 */
float mean(float arr[], uint32_t len)
{
	float sum = 0.0f;
	for (uint32_t i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum / len;
}

/**
 * @brief Computes variance of array given the mean
 * @param arr Array of numbers
 * @param mean Mean of array
 * @param len Length of array
 */
float variance(float arr[], float mean, uint32_t len)
{
	float sum = 0.0f;
	for (uint32_t i = 0; i < len; i++)
	{
		sum += fsq(arr[i] - mean);
	}
	return sum / len;
}

/**
 * @brief Computes standard deviation of array given the mean
 * @param arr Array of numbers
 * @param mean Mean of array
 * @param len Length of array
 */
float stdev(float arr[], float mean, uint32_t len)
{
	return sqrtf(variance(arr, mean, len));
}

/**
 * @brief Returns smaller of a or b
 */
int min(int a, int b)
{
	return (a < b) ? a : b;
}

/**
 * @brief Returns larger of a or b
 */
int max(int a, int b)
{
	return (a > b) ? a : b;
}