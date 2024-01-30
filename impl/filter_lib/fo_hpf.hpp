/**
 * First order high-pass filter
 * Dimitris Tassopoulos 2016-2020
 */
#pragma once
#include "filter_common.hpp"

class FO_HPF : public Biquad {
public:
    tp_coeffs& calculate_coeffs(float filter_frequency_hz, float sampling_rate_hz);

private:
    float m_filter_frequency_hz { -9999.0f };
    float m_fs { -9999.0f };
};
