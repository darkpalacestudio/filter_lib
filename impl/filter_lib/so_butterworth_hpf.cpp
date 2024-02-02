#include "so_butterworth_hpf.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& SO_BUTTERWORTH_HPF::calculate_coeffs(
    float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t const c = std::tan(std::numbers::pi_v<float> * filter_frequency_hz / sampling_rate_hz);
    m_coeffs.a0 = 1.0f / (1.0f + std::numbers::sqrt2_v<float> * c + std::pow(c, 2.0f));
    m_coeffs.a1 = -2.0f * m_coeffs.a0;
    m_coeffs.a2 = m_coeffs.a0;
    m_coeffs.b1 = 2.0f * m_coeffs.a0 * (std::pow(c, 2.0f) - 1.0f);
    m_coeffs.b2 = m_coeffs.a0 * (1.0f - std::numbers::sqrt2_v<float> * c + std::pow(c, 2.0f));
    return (std::ref(m_coeffs));
}
