#include "so_butterworth_lpf.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& SO_BUTTERWORTH_LPF::calculate_coeffs(
    float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t c = 1.0f
        / (std::tan(static_cast<float>(std::numbers::pi) * filter_frequency_hz / sampling_rate_hz));
    m_coeffs.a0 = 1.0f / (1.0f + static_cast<float>(std::numbers::pi) * c + std::pow(c, 2.0f));
    m_coeffs.a1 = 2.0f * m_coeffs.a0;
    m_coeffs.a2 = m_coeffs.a0;
    m_coeffs.b1 = 2.0f * m_coeffs.a0 * (1.0f - std::pow(c, 2.0f));
    m_coeffs.b2
        = m_coeffs.a0 * (1.0f - static_cast<float>(std::numbers::pi) * c + std::pow(c, 2.0f));
    return (std::ref(m_coeffs));
}