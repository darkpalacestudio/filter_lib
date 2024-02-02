#include "fo_shelving_high.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& FO_SHELVING_HIGH::calculate_coeffs(
    float gain_db, float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t const th
        = 2.0f * std::numbers::pi_v<float> * filter_frequency_hz / sampling_rate_hz;
    coef_t const m = std::pow(10.0f, gain_db / 20.0f);
    coef_t const b = (1.0f + m) / 4.0f;
    coef_t const d = b * std::tan(th / 2.0f);
    coef_t const g = (1.0f - d) / (1.0f + d);

    m_coeffs.a0 = (1.0f + g) / 2.0f;
    m_coeffs.a1 = -((1.0f + g) / 2.0f);
    m_coeffs.a2 = 0.0f;
    m_coeffs.b1 = -g;
    m_coeffs.b2 = 0.0f;
    m_coeffs.c0 = m - 1.0f;
    m_coeffs.d0 = 1.0f;

    return (std::ref(m_coeffs));
}
