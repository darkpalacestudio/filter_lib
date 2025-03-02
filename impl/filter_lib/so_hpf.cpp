#include "so_hpf.hpp"
#include <cmath>
#include <numbers>

Biquad::CoefficientsType& SO_HPF::calculate_coeffs(
    double const Q, double const filter_frequency_hz, double const sampling_rate_hz)
{
    CoefT const w = 2.0f * std::numbers::pi_v<double> * filter_frequency_hz / sampling_rate_hz;
    CoefT const d = 1.0f / Q;
    CoefT const b = 0.5f * (1.0f - (d / 2) * std::sin(w)) / (1.0f + (d / 2.0f) * std::sin(w));
    CoefT const g = (0.5f + b) * std::cos(w);

    m_coeffs.a0 = (0.5f + b + g) / 2.0f;
    m_coeffs.a1 = -(0.5f + b + g);
    m_coeffs.a2 = m_coeffs.a0;
    m_coeffs.b1 = -2.0f * g;
    m_coeffs.b2 = 2.0f * b;

    return (std::ref(m_coeffs));
}
