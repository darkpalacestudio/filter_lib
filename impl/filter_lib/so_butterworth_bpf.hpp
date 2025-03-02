/**
 * Second order Butterworth band-pass filter
 * Dimitris Tassopoulos 2016-2020
 *
 * filter_frequency_hz , corner frequency
 * BW , bandwidth of peak/notch = filter_frequency_hz/Q
 * Butterworth BPF and BSF are made by cascading (BPF) or paralleling (BSF) a Butterworth
 * LPF and Butterworth HPF.
 */
#pragma once
#include "filter_common.hpp"

class SO_BUTTERWORTH_BPF : public Biquad {
public:
    CoefficientsType& calculate_coeffs(
        double bw, double filter_frequency_hz, double sampling_rate_hz);
};
