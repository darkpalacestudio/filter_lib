#include "so_bpf.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& SO_BPF::calculate_coeffs(
    float Q, float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t const w
        = 2.0f * static_cast<float>(std::numbers::pi) * filter_frequency_hz / sampling_rate_hz;
    coef_t const b = 0.5f * ((1.0f - std::tan(w / (2.0f * Q))) / (1.0f + std::tan(w / (2.0f * Q))));
    coef_t const g = (0.5f + b) * std::cos(w);

    m_coeffs.a0 = 0.5f - b;
    m_coeffs.a1 = 0.0f;
    m_coeffs.a2 = -(0.5f - b);
    m_coeffs.b1 = -2.0f * g;
    m_coeffs.b2 = 2.0f * b;
    return (std::ref(m_coeffs));
}
