#include "fo_shelving_high.hpp"
#include <cmath>
#include <numbers>

Biquad::CoefficientsType& FO_SHELVING_HIGH::calculate_coeffs(
    double const gain_db, double const filter_frequency_hz, double const sampling_rate_hz)
{
    CoefT const th
        = 2.0f * std::numbers::pi_v<float> * filter_frequency_hz / sampling_rate_hz;
    CoefT const m = std::pow(10.0f, gain_db / 20.0f);
    CoefT const b = (1.0f + m) / 4.0f;
    CoefT const d = b * std::tan(th / 2.0f);
    CoefT const g = (1.0f - d) / (1.0f + d);

    m_coeffs.a0 = (1.0f + g) / 2.0f;
    m_coeffs.a1 = -((1.0f + g) / 2.0f);
    m_coeffs.a2 = 0.0f;
    m_coeffs.b1 = -g;
    m_coeffs.b2 = 0.0f;
    m_coeffs.c0 = m - 1.0f;
    m_coeffs.d0 = 1.0f;

    return (std::ref(m_coeffs));
}
