/**
 * First order all-pass filter
 * Dimitris Tassopoulos 2016
 *
 * filter_frequency_hz, corner frequency
 */
#pragma once

class Biquad {
public:
    using coef_t = double;

    struct tp_coeffs {
        coef_t a0 { 0 };
        coef_t a1 { 0 };
        coef_t a2 { 0 };
        coef_t b1 { 0 };
        coef_t b2 { 0 };
        coef_t c0 { 0 };
        coef_t d0 { 0 };
    };

    Biquad();
    virtual ~Biquad() = default;
    virtual coef_t process(coef_t sample);

    void setOffset(coef_t offset);
    [[nodiscard]] coef_t getOffset() const;

    void reset();
    void resetHard();

protected:
    coef_t m_xnz1 { 0 };
    coef_t m_xnz2 { 0 };
    coef_t m_ynz1 { 0 };
    coef_t m_ynz2 { 0 };
    coef_t m_offset { 0 };

    tp_coeffs m_coeffs;
};
