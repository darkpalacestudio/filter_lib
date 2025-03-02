#include "so_parametric_cq_cut.hpp"
#include <cmath>
#include <numbers>

Biquad::CoefficientsType SO_PARAMETRIC_CQ_CUT::calculate_coeffs(
    double const gain_db, double const Q, double const filter_frequency_hz, double const sampling_rate_hz)
{
    CoefT const K = 2.0f * std::numbers::pi_v<double> * filter_frequency_hz / sampling_rate_hz;
    CoefT const V0 = std::pow(10.0f, gain_db / 20.0f);
    CoefT const d0 = 1.0f + K / Q + std::pow(K, 2.0f);
    CoefT const e = 1.0f + K / (V0 * Q) + std::pow(K, 2.0f);
    CoefT const b = 2.0f * (std::pow(K, 2.0f) - 1.0f);
    CoefT const d = 1.0f - K / Q + std::pow(K, 2.0f);
    CoefT const h = 1.0f - K / (V0 * Q) + std::pow(K, 2.0f);
    m_coeffs.a0 = d0 / e;
    m_coeffs.a1 = b / e;
    m_coeffs.a2 = d / e;
    m_coeffs.b1 = b / e;
    m_coeffs.b2 = h / e;
    m_coeffs.c0 = 1.0f;
    m_coeffs.d0 = 0.0f;
    return (m_coeffs);
}
