/**
 * First order high-shelving filter
 * Dimitris Tassopoulos 2016
 *
 * filter_frequency_hz , high shelf frequency
 * Low-frequency gain/attenuation in dB
 * Shelving filters are used in many tone controls, especially when there are only two, bass
 * and treble, which are almost always implemented as shelf types. The filters have a corner
 * frequency and gain or attenuation value.
 */
#pragma once
#include "biquad_modified.hpp"
#include "filter_common.hpp"

class FO_SHELVING_HIGH : public BiquadModified {
public:
    CoefficientsType& calculate_coeffs(double gain_db, double filter_frequency_hz, double sampling_rate_hz);
};
