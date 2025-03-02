#include "so_apf.hpp"
#include <algorithm>
#include <cmath>
#include <numbers>

Biquad::CoefficientsType& SO_APF::calculate_coeffs(
    double Q, double filter_frequency_hz, double const sampling_rate_hz)
{
    // sanitize values
    Q = std::clamp(Q, 0.1, 10000.0);
    filter_frequency_hz = std::clamp(filter_frequency_hz, 1.0, sampling_rate_hz);

    // calculate helper variables
    CoefT const a = (std::tan(std::numbers::pi_v<double> * Q / sampling_rate_hz) - 1.0)
        / (std::tan(std::numbers::pi_v<double> * Q / sampling_rate_hz) + 1.0);
    CoefT const b
        = -std::cos(2 * std::numbers::pi_v<double> * filter_frequency_hz / sampling_rate_hz);

    // calculate coefficients
    m_coeffs.a0 = -a;
    m_coeffs.a1 = b * (1.0 - a);
    m_coeffs.a2 = 1.0;
    m_coeffs.b1 = m_coeffs.a1;
    m_coeffs.b2 = m_coeffs.a0;

    // clean past samples
    reset();

    return (std::ref(m_coeffs));
}
