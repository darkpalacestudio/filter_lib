#include "biquad_modified.hpp"

Biquad::coef_t BiquadModified::process(coef_t sample)
{
    coef_t const xn = sample;
    coef_t const ynn = m_coeffs.a0 * xn + m_coeffs.a1 * m_xnz1 + m_coeffs.a2 * m_xnz2
        - m_coeffs.b1 * m_ynz1 - m_coeffs.b2 * m_xnz2;
    coef_t const yn = m_coeffs.d0 * xn + m_coeffs.c0 * ynn;

    m_xnz2 = m_xnz1;
    m_xnz1 = xn;
    m_ynz2 = m_ynz1;
    m_ynz1 = yn;

    return (yn);
}
