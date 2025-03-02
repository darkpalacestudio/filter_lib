#pragma once
#include "biquad.hpp"

class BiquadModified : public Biquad {
public:
    CoefT process(CoefT sample) override;
};
