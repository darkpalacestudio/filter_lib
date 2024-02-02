#include "so_parametric_ncq.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& SO_PARAMETRIC_NCQ::calculate_coeffs(
    float gain_db, float Q, float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t const w
        = 2.0f * std::numbers::pi_v<float> * filter_frequency_hz / sampling_rate_hz;
    coef_t const m = std::pow(10.0f, gain_db / 20.0f);
    coef_t const z = 4.0f / (1.0f + m);
    coef_t const b
        = 0.5f * ((1.0f - z * std::tan(w / (2.0f * Q)) / (1.0f + z * std::tan(w / (2.0f * Q)))));
    coef_t const g = (0.5f + b) * std::cos(w);
    m_coeffs.a0 = 0.5f - b;
    m_coeffs.a1 = 0.0f;
    m_coeffs.a2 = -(0.5f - b);
    m_coeffs.b1 = -2.0f * g;
    m_coeffs.b2 = 2.0f * b;
    m_coeffs.c0 = m - 1.0f;
    m_coeffs.d0 = 1.0f;

    return (std::ref(m_coeffs));
}
