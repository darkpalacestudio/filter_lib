#include "so_linkwitz_riley_lpf.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& SO_LINKWITZ_RILEY_LPF::calculate_coeffs(
    float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t const th = static_cast<float>(std::numbers::pi) * filter_frequency_hz / sampling_rate_hz;
    coef_t const Wc = static_cast<float>(std::numbers::pi) * filter_frequency_hz;
    coef_t const k = Wc / std::tan(th);
    coef_t const d = std::pow(k, 2.0f) + std::pow(Wc, 2.0f) + 2.0f * k * Wc;

    m_coeffs.a0 = std::pow(Wc, 2.0f) / d;
    m_coeffs.a1 = 2.0f * std::pow(Wc, 2.0f) / d;
    m_coeffs.a2 = m_coeffs.a0;
    m_coeffs.b1 = (-2.0f * std::pow(k, 2.0f) + 2.0f * std::pow(Wc, 2.0f)) / d;
    m_coeffs.b2 = (-2.0f * k * Wc + std::pow(k, 2.0f) + std::pow(Wc, 2.0f)) / d;
    return (std::ref(m_coeffs));
}
