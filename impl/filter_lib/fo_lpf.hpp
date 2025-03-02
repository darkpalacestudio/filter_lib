/**
 * First order low-pass filter
 * Dimitris Tassopoulos 2016-2020
 */
#pragma once
#include "filter_common.hpp"

class FO_LPF : public Biquad {
public:
    CoefficientsType& calculate_coeffs(double filter_frequency_hz, double sampling_rate_hz);
};
