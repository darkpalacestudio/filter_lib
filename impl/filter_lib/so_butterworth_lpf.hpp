/**
 * Second order Butterworth low-pass filter
 * Dimitris Tassopoulos 2016-2020
 *
 * filter_frequency_hz, corner frequency
 * Butterworth low-pass and high-pass filters are specialized versions of the ordinary secondorder
 * low-pass filter. Their Q values are fixed at 0.707, which is the largest value it can
 * assume before peaking in the frequency response is observed.
 */
#pragma once
#include "filter_common.hpp"

class SO_BUTTERWORTH_LPF : public Biquad {
public:
    tp_coeffs& calculate_coeffs(float filter_frequency_hz, float sampling_rate_hz);
};
