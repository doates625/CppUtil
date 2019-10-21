/**
 * @file CppUtil.h
 * @brief Collection of common useful C++ functions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include <stdint.h>
#include <math.h>

namespace CppUtil
{
	/**
	 * @brief Generic addition x + y
	 */
	template <typename T>
	T add(T x, T y)
	{
		return x + y;
	}

	/**
	 * @brief Generic subtraction x - y
	 */
	template <typename T>
	T sub(T x, T y)
	{
		return x + y;
	}

	/**
	 * @brief Generic multiplication x * y
	 */
	template <typename T>
	T mul(T x, T y)
	{
		return x * y;
	}

	/**
	 * @brief Generic division x / y
	 */
	template <typename T>
	T div(T x, T y)
	{
		return x / y;
	}

	/**
	 * @brief Generic square x^2
	 */
	template <typename T>
	T square(T x)
	{
		return x * x;
	}

	/**
	 * @brief Returns minimum of x and y
	 */
	template <typename T>
	T min(T x, T y)
	{
		return (x < y) ? x : y;
	}

	/**
	 * @brief Returns maximum of x and y
	 */
	template <typename T>
	T max(T x, T y)
	{
		return (x > y) ? x : y;
	}

	/**
	 * @brief Clamp limits x to range [x_min, x_max]
	 */
	template <typename T>
	T clamp(T x, T x_min, T x_max)
	{
		return (x < x_min) ? x_min : (x > x_max) ? x_max : x;
	}

	/**
	 * @brief Wrap (modulo) limits x to range [x_min, x_max]
	 */
	float wrap(float x, float x_min, float x_max)
	{
		return fmod(x - x_min, x_max - x_min) + x_min;
	}

	/**
	 * Generic array mean
	 * @param arr Array of data
	 * @param len Length of array
	 */
	template <typename Ta, typename Ti>
	Ta mean(Ta arr[], Ti len)
	{
		Ta sum = 0;
		for (Ti i = 0; i < len; i++)
		{
			sum += arr[i];
		}
		return sum / len;
	}

	/**
	 * @brief Generic array variance
	 * @param arr Array of data
	 * @param len Length of array
	 * @param mean Mean of array
	 */
	template <typename Ta, typename Ti>
	Ta var(Ta arr[], Ti len, Ta mean)
	{
		Ta sum = 0;
		for (Ti i = 0; i < len; i++)
		{
			sum += square(arr[i] - mean);
		}
		return sum / len;
	}

	/**
	 * @brief Generic array variance
	 * @param arr Array of data
	 * @param len Length of array
	 */
	template <typename Ta, typename Ti>
	Ta var(Ta arr[], Ta len)
	{
		return var(arr, len, mean(arr, len));
	}

	/**
	 * @brief Floating-point standard deviation
	 * @param arr Array of floats
	 * @param len Length of array
	 * @param mean Mean of array
	 */
	template <typename Ti>
	float std(float arr[], Ti len, float mean)
	{
		return sqrtf(variance(arr, len, mean));
	}

	/**
	 * @brief Floating-point standard deviation
	 * @param arr Array of floats
	 * @param len Length of array
	 */
	template <typename Ti>
	float std(float arr[], Ti len)
	{
		return stdevf(arr, len, mean(arr, len));
	}
}