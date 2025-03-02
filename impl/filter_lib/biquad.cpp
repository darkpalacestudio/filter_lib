#include "biquad.hpp"

std::array<Biquad::CoefT, 7> Biquad::CoefficientsType::toArray() const
{
    return std::array { a0, a1, a2, b1, b2, c0, d0 };
}

void Biquad::CoefficientsType::fromArray(std::array<CoefT, 7> const& array)
{
    a0 = array[0];
    a1 = array[1];
    a2 = array[2];
    b1 = array[3];
    b2 = array[4];
    c0 = array[5];
    d0 = array[6];
}

Biquad::Biquad()
    : m_xnz1 { 0 }
    , m_xnz2 { 0 }
    , m_ynz1 { 0 }
    , m_ynz2 { 0 }
    , m_offset { 0 }
    , m_coeffs { 0 }
{
}

Biquad::CoefT Biquad::process(CoefT const sample)
{
    CoefT const xn = sample;
    CoefT const yn = m_coeffs.a0 * xn + m_coeffs.a1 * m_xnz1 + m_coeffs.a2 * m_xnz2
        - m_coeffs.b1 * m_ynz1 - m_coeffs.b2 * m_ynz2;
    m_xnz2 = m_xnz1;
    m_xnz1 = xn;
    m_ynz2 = m_ynz1;
    m_ynz1 = yn;
    return yn + m_offset;
}

void Biquad::setOffset(CoefT const offset) { m_offset = offset; }

Biquad::CoefT Biquad::getOffset() const { return (m_offset); }

void Biquad::setCoefficients(CoefficientsType const& newCoefficients)
{
    m_coeffs = newCoefficients;
}

Biquad::CoefficientsType const& Biquad::getCoefficients() const { return m_coeffs; }

Biquad::CoefficientsType& Biquad::getCoefficients() { return m_coeffs; }

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
