#include "fo_apf.hpp"
#include <cmath>
#include <numbers>

Biquad::tp_coeffs& FO_APF::calculate_coeffs(float filter_frequency_hz, float sampling_rate_hz)
{
    coef_t const a
        = (std::tan(std::numbers::pi_v<float> * filter_frequency_hz / sampling_rate_hz)
              - 1.0f)
        / (std::tan(std::numbers::pi_v<float> * filter_frequency_hz / sampling_rate_hz)
            + 1.0f);

    m_coeffs.a0 = a;
    m_coeffs.a1 = 1.0f;
    m_coeffs.a2 = 0.0f;
    m_coeffs.b1 = a;
    m_coeffs.b2 = 0.0f;

    return (std::ref(m_coeffs));
}
