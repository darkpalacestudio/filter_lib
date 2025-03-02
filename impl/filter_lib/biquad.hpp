/**
 * First order all-pass filter
 * Dimitris Tassopoulos 2016
 *
 * filter_frequency_hz, corner frequency
 */
#pragma once

class Biquad {
public:
    using CoefT = double;

    struct CoefficientsType {
        CoefT a0 { 0 };
        CoefT a1 { 0 };
        CoefT a2 { 0 };
        CoefT b1 { 0 };
        CoefT b2 { 0 };
        CoefT c0 { 0 };
        CoefT d0 { 0 };
    };

    Biquad();
    virtual ~Biquad() = default;
    virtual CoefT process(CoefT sample);

    void setOffset(CoefT offset);
    [[nodiscard]] CoefT getOffset() const;

    void reset();
    void resetHard();

protected:
    CoefT m_xnz1 { 0 };
    CoefT m_xnz2 { 0 };
    CoefT m_ynz1 { 0 };
    CoefT m_ynz2 { 0 };
    CoefT m_offset { 0 };

    CoefficientsType m_coeffs;
};
