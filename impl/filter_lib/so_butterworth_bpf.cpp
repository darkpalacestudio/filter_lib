#include "so_butterworth_bpf.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& SO_BUTTERWORTH_BPF::calculate_coeffs(
    float bw, float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t const c = 1.0f
        / (std::tan(
            static_cast<float>(std::numbers::pi) * filter_frequency_hz * bw / sampling_rate_hz));
    coef_t const d = 2.0f
        * std::cos(
            2.0f * static_cast<float>(std::numbers::pi) * filter_frequency_hz / sampling_rate_hz);

    m_coeffs.a0 = 1.0f / (1.0f + c);
    m_coeffs.a1 = 0.0f;
    m_coeffs.a2 = -m_coeffs.a0;
    m_coeffs.b1 = -m_coeffs.a0 * (c * d);
    m_coeffs.b2 = m_coeffs.a0 * (c - 1.0f);

    return (std::ref(m_coeffs));
}
