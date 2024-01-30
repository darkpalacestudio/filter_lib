#include "so_parametric_cq_cut.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs SO_PARAMETRIC_CQ_CUT::calculate_coeffs(
    float gain_db, float Q, float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t const K = static_cast<float>(std::numbers::pi) * filter_frequency_hz / sampling_rate_hz;
    coef_t const V0 = std::pow(10.0f, gain_db / 20.0f);
    coef_t const d0 = 1.0f + K / Q + std::pow(K, 2.0f);
    coef_t const e = 1.0f + K / (V0 * Q) + std::pow(K, 2.0f);
    coef_t const b = 2.0f * (std::pow(K, 2.0f) - 1.0f);
    coef_t const d = 1.0f - K / Q + std::pow(K, 2.0f);
    coef_t const h = 1.0f - K / (V0 * Q) + std::pow(K, 2.0f);
    m_coeffs.a0 = d0 / e;
    m_coeffs.a1 = b / e;
    m_coeffs.a2 = d / e;
    m_coeffs.b1 = b / e;
    m_coeffs.b2 = h / e;
    m_coeffs.c0 = 1.0;
    m_coeffs.d0 = 0.0;
    return (m_coeffs);
}
