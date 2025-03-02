/**
 * Second order parametric/peaking filter with non-constant-Q
 * Dimitris Tassopoulos 2016-2020
 *
 * filter_frequency_hz , center frequency
 * Q quality factor
 * Gain/attenuation in dB
 * Parametric EQs allow you to adjust the center frequency, Q and boost or cut creating any
 * arbitrary bumps or notches in the frequency response. The parametric EQ is a
 * variation on the ordinary band-pass and band-stop filters that generates symmetrical boost/
 * cut curves and mixes in the dry signal to create the fi nal response. A true digital parametric
 * EQ not only has independent controls, but each control only varies one coefficient in the
 * filter. The parametric EQs in this section afford the same frequency response but adjustments
 * in any parameter require a recalculation of all the coefficients. These filters are also called
 * peaking filters.
 * This parametric EQ is not constant-Q, which means the bandwidth varies depending on the
 * boost/cut value. Some analog filters have the same issue, although there is occasional debate
 * over whether or not this is desirable in an EQ design.
 */
#pragma once
#include "filter_common.hpp"

class SO_PARAMETRIC_NCQ : public Biquad {
public:
    CoefficientsType& calculate_coeffs(
        double gain_db, double Q, double filter_frequency_hz, double sampling_rate_hz);
};
