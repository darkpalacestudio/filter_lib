#include "fo_apf.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& FO_APF::calculate_coeffs(double filter_frequency_hz, double sampling_rate_hz)
{
    coef_t const a
        = (std::tan(std::numbers::pi_v<double> * filter_frequency_hz / sampling_rate_hz) - 1.0)
        / (std::tan(std::numbers::pi_v<double> * filter_frequency_hz / sampling_rate_hz) + 1.0);

    m_coeffs.a0 = a;
    m_coeffs.a1 = 1.0;
    m_coeffs.a2 = 0.0;
    m_coeffs.b1 = a;
    m_coeffs.b2 = 0.0;

    return (std::ref(m_coeffs));
}
