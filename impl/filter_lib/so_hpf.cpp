#include "so_hpf.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& SO_HPF::calculate_coeffs(
    float Q, float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t const w
        = 2.0f * static_cast<float>(std::numbers::pi) * filter_frequency_hz / sampling_rate_hz;
    coef_t const d = 1.0f / Q;
    coef_t const b = 0.5f * (1.0f - (d / 2) * std::sin(w)) / (1.0f + (d / 2.0f) * std::sin(w));
    coef_t const g = (0.5f + b) * std::cos(w);

    m_coeffs.a0 = (0.5f + b + g) / 2.0f;
    m_coeffs.a1 = -(0.5f + b + g);
    m_coeffs.a2 = m_coeffs.a0;
    m_coeffs.b1 = -2.0f * g;
    m_coeffs.b2 = 2.0f * b;

    return (std::ref(m_coeffs));
}
