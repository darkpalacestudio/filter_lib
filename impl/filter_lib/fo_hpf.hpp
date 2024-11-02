/**
 * First order high-pass filter
 * Dimitris Tassopoulos 2016-2020
 */
#pragma once
#include "filter_common.hpp"

class FO_HPF : public Biquad {
public:
    tp_coeffs& calculate_coeffs(double filter_frequency_hz, double sampling_rate_hz);

private:
    coef_t m_filter_frequency_hz { -9999.0 };
    coef_t m_fs { -9999.0 };
};
