#include "fo_lpf.hpp"
#include <cmath>
#include <numbers>

Biquad::CoefficientsType& FO_LPF::calculate_coeffs(
    double const filter_frequency_hz, double const sampling_rate_hz)
{
    CoefT const th = 2.0f * std::numbers::pi_v<float> * filter_frequency_hz / sampling_rate_hz;
    CoefT const g = std::cos(th) / (1.0f + std::sin(th));

    m_coeffs.a0 = (1.0f - g) / 2.0f;
    m_coeffs.a1 = (1.0f - g) / 2.0f;
    m_coeffs.a2 = 0.0f;
    m_coeffs.b1 = -g;
    m_coeffs.b2 = 0.0f;

    return (std::ref(m_coeffs));
}
