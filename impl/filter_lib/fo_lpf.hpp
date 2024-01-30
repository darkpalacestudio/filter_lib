/**
 * First order low-pass filter
 * Dimitris Tassopoulos 2016-2020
 */
#pragma once
#include "filter_common.hpp"

class FO_LPF : public Biquad {
public:
    tp_coeffs& calculate_coeffs(float filter_frequency_hz, float sampling_rate_hz);
};
