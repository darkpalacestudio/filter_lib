/**
 * First order high-pass filter
 * Dimitris Tassopoulos 2016-2020
 */
#pragma once
#include "filter_common.hpp"

class FO_HPF : public Biquad {
public:
    CoefficientsType& calculate_coeffs(double filter_frequency_hz, double sampling_rate_hz);

private:
    CoefT m_filter_frequency_hz { -9999.0 };
    CoefT m_fs { -9999.0 };
};
