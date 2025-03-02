#include "so_bpf.hpp"
#include <cmath>
#include <numbers>

Biquad::CoefficientsType& SO_BPF::calculate_coeffs(
    double const Q, double const filter_frequency_hz, double const sampling_rate_hz)
{
    CoefT const w
        = 2.0f * std::numbers::pi_v<float> * filter_frequency_hz / sampling_rate_hz;
    CoefT const b = 0.5f * ((1.0f - std::tan(w / (2.0f * Q))) / (1.0f + std::tan(w / (2.0f * Q))));
    CoefT const g = (0.5f + b) * std::cos(w);

    m_coeffs.a0 = 0.5f - b;
    m_coeffs.a1 = 0.0f;
    m_coeffs.a2 = -(0.5f - b);
    m_coeffs.b1 = -2.0f * g;
    m_coeffs.b2 = 2.0f * b;
    return (std::ref(m_coeffs));
}
