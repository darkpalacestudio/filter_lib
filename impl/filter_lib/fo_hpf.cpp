#include "fo_hpf.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& FO_HPF::calculate_coeffs(float filter_frequency_hz, float sampling_rate_hz)
{
    if (filter_frequency_hz == m_filter_frequency_hz && sampling_rate_hz == m_fs) {
        return std::ref(m_coeffs);
    }

    coef_t const th
        = 2.0f * static_cast<float>(std::numbers::pi) * filter_frequency_hz / sampling_rate_hz;
    coef_t const g = std::cos(th) / (1.0f + std::sin(th));

    m_coeffs.a0 = (1.0f + g) / 2.0f;
    m_coeffs.a1 = -((1.0f + g) / 2.0f);
    m_coeffs.a2 = 0.0f;
    m_coeffs.b1 = -g;
    m_coeffs.b2 = 0.0f;

    m_filter_frequency_hz = filter_frequency_hz;
    m_fs = sampling_rate_hz;

    return (std::ref(m_coeffs));
}
