/**
 * Second order band-pass filter
 * Dimitris Tassopoulos 2016-2020
 *
 * filter_frequency_hz , corner frequency
 * Q , quality factor controlling width of peak or notch = 1/BW
 */
#pragma once
#include "filter_common.hpp"

class SO_BPF : public Biquad {
public:
    CoefficientsType& calculate_coeffs(
        double Q, double filter_frequency_hz, double sampling_rate_hz);
};
