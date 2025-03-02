/**
 * Second order Linkwitz-Riley low-pass filter
 * Dimitris Tassopoulos 2016-2020
 *
 * filter_frequency_hz , corner frequency (-6 dB)
 * Second-order Linkwitz/Riley LPFs are designed to have an attenuation of -6 dB
 * at the corner frequency rather than the standard -3 dB When these
 * filters are placed in parallel with the same cutoff frequency, their outputs sum exactly and
 * the resulting response is flat. They are often used in crossovers.
 */
#pragma once
#include "filter_common.hpp"

class SO_LINKWITZ_RILEY_LPF : public Biquad {
public:
    CoefficientsType& calculate_coeffs(double filter_frequency_hz, double sampling_rate_hz);
};
