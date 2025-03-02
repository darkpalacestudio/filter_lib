#include "biquad.hpp"

Biquad::Biquad()
    : m_xnz1 { 0 }
    , m_xnz2 { 0 }
    , m_ynz1 { 0 }
    , m_ynz2 { 0 }
    , m_offset { 0 }
    , m_coeffs { 0 }
{
}

Biquad::coef_t Biquad::process(coef_t sample)
{
    coef_t const xn = sample;
    coef_t const yn = m_coeffs.a0 * xn + m_coeffs.a1 * m_xnz1 + m_coeffs.a2 * m_xnz2
        - m_coeffs.b1 * m_ynz1 - m_coeffs.b2 * m_ynz2;
    m_xnz2 = m_xnz1;
    m_xnz1 = xn;
    m_ynz2 = m_ynz1;
    m_ynz1 = yn;
    return yn + m_offset;
}

void Biquad::setOffset(coef_t offset) { m_offset = offset; }

Biquad::coef_t Biquad::getOffset() const { return (m_offset); }

void Biquad::reset()
{
    m_xnz1 *= 0.9;
    m_xnz2 *= 0.9;
    m_ynz1 *= 0.9;
    m_ynz2 *= 0.9;
}

void Biquad::resetHard()
{
    m_xnz1 = 0;
    m_xnz2 = 0;
    m_ynz1 = 0;
    m_ynz2 = 0;
}
