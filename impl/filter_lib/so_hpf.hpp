/**
 * Second order high-pass filter
 * Dimitris Tassopoulos 2016-2020
 *
 * filter_frequency_hz , corner frequency
 * Q , quality factor controlling resonant peaking
 */
#pragma once
#include "filter_common.hpp"

class SO_HPF : public Biquad {
public:
    tp_coeffs& calculate_coeffs(float Q, float filter_frequency_hz, float sampling_rate_hz);
};
