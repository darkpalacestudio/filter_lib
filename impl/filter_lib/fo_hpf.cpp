#include "fo_hpf.hpp"
#include <cmath>
#include <numbers>

Biquad::CoefficientsType& FO_HPF::calculate_coeffs(double const filter_frequency_hz, double const sampling_rate_hz)
{
    if (filter_frequency_hz == m_filter_frequency_hz && sampling_rate_hz == m_fs) {
        return std::ref(m_coeffs);
    }

    CoefT const th = 2.0 * std::numbers::pi_v<double> * filter_frequency_hz / sampling_rate_hz;
    CoefT const g = std::cos(th) / (1.0 + std::sin(th));

    m_coeffs.a0 = (1.0 + g) / 2.0;
    m_coeffs.a1 = -((1.0 + g) / 2.0);
    m_coeffs.a2 = 0.0;
    m_coeffs.b1 = -g;
    m_coeffs.b2 = 0.0;

    m_filter_frequency_hz = filter_frequency_hz;
    m_fs = sampling_rate_hz;

    return (std::ref(m_coeffs));
}
