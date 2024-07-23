#include "so_apf.hpp"
#include <cmath>
#include <numbers>
#include <algorithm>

Biquad::tp_coeffs& SO_APF::calculate_coeffs(
    float Q, float filter_frequency_hz, float sampling_rate_hz)
{
    // sanitize values
    Q = std::clamp(Q, 0.0001f, 10000.0f);
    filter_frequency_hz = std::clamp(filter_frequency_hz, 1.0f, sampling_rate_hz);

    // calculate helper variables
    coef_t const a = (std::tan(std::numbers::pi_v<float> * Q / sampling_rate_hz) - 1.0f)
        / (std::tan(std::numbers::pi_v<float> * Q / sampling_rate_hz) + 1.0f);
    coef_t const b = -std::cos(
        2 * std::numbers::pi_v<float> * filter_frequency_hz / sampling_rate_hz);

    // calculate coefficients
    m_coeffs.a0 = -a;
    m_coeffs.a1 = b * (1.0f - a);
    m_coeffs.a2 = 1.0f;
    m_coeffs.b1 = m_coeffs.a1;
    m_coeffs.b2 = m_coeffs.a0;
    return (std::ref(m_coeffs));
}
