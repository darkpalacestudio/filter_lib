/**
 * First order all-pass filter
 * Dimitris Tassopoulos 2016-2020
 *
 * filter_frequency_hz, corner frequency
 */
#pragma once
#include "filter_common.hpp"

class FO_APF : public Biquad {
public:
    tp_coeffs& calculate_coeffs(float filter_frequency_hz, float sampling_rate_hz = 44100);
};
