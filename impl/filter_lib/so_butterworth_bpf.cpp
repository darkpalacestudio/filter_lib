#include "so_butterworth_bpf.hpp"
#include <cmath>
#include <numbers>

Biquad::CoefficientsType& SO_BUTTERWORTH_BPF::calculate_coeffs(
    double const bw, double const filter_frequency_hz, double const sampling_rate_hz)
{
    CoefT const c = 1.0f
        / (std::tan(std::numbers::pi_v<float> * filter_frequency_hz * bw / sampling_rate_hz));
    CoefT const d = 2.0f
        * std::cos(2.0f * std::numbers::pi_v<float> * filter_frequency_hz / sampling_rate_hz);

    m_coeffs.a0 = 1.0f / (1.0f + c);
    m_coeffs.a1 = 0.0f;
    m_coeffs.a2 = -m_coeffs.a0;
    m_coeffs.b1 = -m_coeffs.a0 * (c * d);
    m_coeffs.b2 = m_coeffs.a0 * (c - 1.0f);

    return (std::ref(m_coeffs));
}
