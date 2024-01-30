/**
 * First order all-pass filter
 * Dimitris Tassopoulos 2016
 *
 * filter_frequency_hz, corner frequency
 */
#pragma once

class Biquad {
public:
    using coef_t = float;

    struct tp_coeffs {
        coef_t a0 { 0.0f };
        coef_t a1 { 0.0f };
        coef_t a2 { 0.0f };
        coef_t b1 { 0.0f };
        coef_t b2 { 0.0f };
        coef_t c0 { 0.0f };
        coef_t d0 { 0.0f };
    };

    Biquad();
    virtual ~Biquad() = default;
    virtual coef_t process(coef_t sample);

    void set_offset(coef_t offset);
    [[nodiscard]] coef_t get_offset() const;

protected:
    coef_t m_xnz1 { 0.0f };
    coef_t m_xnz2 { 0.0f };
    coef_t m_ynz1 { 0.0f };
    coef_t m_ynz2 { 0.0f };
    coef_t m_offset { 0.0f };

    tp_coeffs m_coeffs;
};
