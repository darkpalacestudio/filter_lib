#include "so_apf.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& SO_APF::calculate_coeffs(
    float Q, float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t const a = (std::tan(static_cast<float>(std::numbers::pi) * Q / sampling_rate_hz) - 1.0f)
        / (std::tan(static_cast<float>(std::numbers::pi) * Q / sampling_rate_hz) + 1.0f);
    coef_t const b = -std::cos(
        2 * static_cast<float>(std::numbers::pi) * filter_frequency_hz / sampling_rate_hz);
    m_coeffs.a0 = -a;
    m_coeffs.a1 = b * (1.0f - a);
    m_coeffs.a2 = 1.0f;
    m_coeffs.b1 = m_coeffs.a1;
    m_coeffs.b2 = m_coeffs.a0;
    return (std::ref(m_coeffs));
}
