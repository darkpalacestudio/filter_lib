/**
 * Second order parametric/peaking cut filter with constant-Q
 * Dimitris Tassopoulos 2016-2020
 *
 * filter_frequency_hz , center frequency
 * Q quality factor
 * Gain/attenuation in dB
 * Parametric EQs allow you to adjust the center frequency, Q and boost or cut creating any
 * arbitrary bumps or notches in the frequency response. The parametric EQ is a
 * variation on the ordinary band-pass and band-stop fi lters that generates symmetrical boost/
 * cut curves and mixes in the dry signal to create the fi nal response. A true digital parametric
 * EQ not only has independent controls, but each control only varies one coeffi cient in the
 * fi lter. The parametric EQs in this section afford the same frequency response but adjustments
 * in any parameter require a recalculation of all the coeffi cients. These fi lters are also called
 * peaking fi lters.
 *
 * This design creates an almost perfect constant-Q filter with only a small amount of error
 * for low-boost (or cut) values.
 */
#pragma once
#include "filter_common.hpp"

class SO_PARAMETRIC_CQ_CUT : public Biquad {
public:
    CoefficientsType calculate_coeffs(
        double gain_db, double Q, double filter_frequency_hz, double sampling_rate_hz);
};
