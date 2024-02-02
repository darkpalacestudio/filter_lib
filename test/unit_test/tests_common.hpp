#ifndef TESTS_COMMON_HPP
#define TESTS_COMMON_HPP

#include "filter_lib/filter_includes.hpp"
#include <gtest/gtest.h>
#include <iostream>

// #define DEBUG_OUTPUT

constexpr inline auto BW_DEF = 1000.0f;
constexpr inline auto Q_DEF = 1.0f;
constexpr inline auto GAIN = 1.0f;
constexpr inline auto FC = 5000.0f;
constexpr inline auto SAMPLING_RATE = 96000.0f;
constexpr inline auto TEST_SAMPLE_0 = 0;
constexpr inline auto TEST_SAMPLE_1 = 1.0f;

static inline void debug_print(Biquad::tp_coeffs& coeffs)
{
    std::cout << "Coeffs: " << std::endl;
    std::cout << "\ta0: " << coeffs.a0 << std::endl;
    std::cout << "\ta1: " << coeffs.a1 << std::endl;
    std::cout << "\ta2: " << coeffs.a2 << std::endl;
    std::cout << "\tb1: " << coeffs.b1 << std::endl;
    std::cout << "\tb2: " << coeffs.b2 << std::endl;
}

#endif
