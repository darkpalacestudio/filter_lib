#include "so_parametric_cq_boost.hpp"
#include <cmath>
#include <numbers>

Biquad::CoefficientsType& SO_PARAMETRIC_CQ_BOOST::calculate_coeffs(
    double const gain_db, double const Q, double const filter_frequency_hz, double const sampling_rate_hz)
{
    CoefT const K = 2.0f * std::numbers::pi_v<double> * filter_frequency_hz / sampling_rate_hz;
    CoefT const V0 = std::pow(10.0f, gain_db / 20.0f);
    CoefT const d0 = 1.0f + K / Q + std::pow(K, 2.0f);
    CoefT const a = 1.0f + (V0 * K) / Q + std::pow(K, 2.0f);
    CoefT const b = 2.0f * (std::pow(K, 2.0f) - 1.0f);
    CoefT const g = 1.0f - (V0 * K) / Q + std::pow(K, 2.0f);
    CoefT const d = 1.0f - K / Q + std::pow(K, 2.0f);
    m_coeffs.a0 = a / d0;
    m_coeffs.a1 = b / d0;
    m_coeffs.a2 = g / d0;
    m_coeffs.b1 = b / d0;
    m_coeffs.b2 = d / d0;
    m_coeffs.c0 = 1.0f;
    m_coeffs.d0 = 0.0f;
    return (std::ref(m_coeffs));
}
