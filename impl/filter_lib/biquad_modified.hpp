#pragma once
#include "biquad.hpp"

class BiquadModified : public Biquad {
public:
    coef_t process(coef_t sample) override;
};
