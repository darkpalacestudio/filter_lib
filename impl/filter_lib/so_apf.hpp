/**
 * Second order all-pass filter
 * Dimitris Tassopoulos 2016-2020
 *
 * filter_frequency_hz, corner frequency
 * Q, steepness of phase shift at filter_frequency_hz (second-order only)
 */
#pragma once
#include "filter_common.hpp"

class SO_APF : public Biquad {
public:
    tp_coeffs& calculate_coeffs(float Q, float filter_frequency_hz, float sampling_rate_hz);
};
