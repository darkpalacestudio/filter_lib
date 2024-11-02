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
    tp_coeffs& calculate_coeffs(double Q, double filter_frequency_hz, double sampling_rate_hz);
};
