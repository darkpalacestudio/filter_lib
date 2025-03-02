#include "so_linkwitz_riley_lpf.hpp"
#include <cmath>
#include <numbers>

Biquad::CoefficientsType& SO_LINKWITZ_RILEY_LPF::calculate_coeffs(
    double const filter_frequency_hz, double const sampling_rate_hz)
{
    CoefT const th = std::numbers::pi_v<double> * filter_frequency_hz / sampling_rate_hz;
    CoefT const Wc = std::numbers::pi_v<double> * filter_frequency_hz;
    CoefT const k = Wc / std::tan(th);
    CoefT const d = std::pow(k, 2.0f) + std::pow(Wc, 2.0f) + 2.0f * k * Wc;

    m_coeffs.a0 = std::pow(Wc, 2.0f) / d;
    m_coeffs.a1 = 2.0f * std::pow(Wc, 2.0f) / d;
    m_coeffs.a2 = m_coeffs.a0;
    m_coeffs.b1 = (-2.0f * std::pow(k, 2.0f) + 2.0f * std::pow(Wc, 2.0f)) / d;
    m_coeffs.b2 = (-2.0f * k * Wc + std::pow(k, 2.0f) + std::pow(Wc, 2.0f)) / d;
    return (std::ref(m_coeffs));
}
