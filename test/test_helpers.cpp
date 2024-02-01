#include "test_helpers.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <Approvals.h>
#include <cmath>
#include <cstddef>
#include <numbers>
#include <numeric>
#include <sstream>

#include <iostream>

std::string test_helpers::floatToStringWithXDecimalDigits(
    float const number, unsigned number_of_decimal_digits)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(static_cast<int>(number_of_decimal_digits)) << number;
    return stream.str();
}

std::vector<float> test_helpers::createInputWithSine(float frequency_hz, float sampling_rate_hz)
{
    std::vector<float> input;
    auto const number_of_samples = static_cast<std::size_t>(sampling_rate_hz);
    input.resize(number_of_samples, 0.0f);

    for (auto i = 0u; i != number_of_samples; ++i) {
        auto const t = static_cast<float>(i) / sampling_rate_hz;
        input[i] = std::sin(t * static_cast<float>(std::numbers::pi) * 2.0f * frequency_hz);
    }

    return input;
}

float test_helpers::integrate(std::vector<float> const& data, float sample_rate)
{
    auto const deltaT = 1.0f / sample_rate;
    return std::accumulate(
        data.cbegin(), data.cend(), 0.0f, [deltaT](float s, float x) { return s + x * deltaT; });
}

TEST_CASE("generate test data")
{
    for (auto const freq : { 1.0f, 5.0f, 50.0f }) {
        SECTION("sin f " + test_helpers::floatToStringWithXDecimalDigits(freq, 0))
        {
            auto const generated_waveform = test_helpers::createInputWithSine(freq, 44100.0f);
            ApprovalTests::Approvals::verifyAll(generated_waveform);
        }
    }
}

TEST_CASE("integrate sine over full cycle results in 0")
{
    auto const frequency = GENERATE(1.0f, 2.0f, 100.0f);
    auto const generated_waveform = test_helpers::createInputWithSine(frequency, 44100.0f);

    auto const integral = test_helpers::integrate(generated_waveform, 44100.0f);

    constexpr auto epsilon = 0.001f;
    REQUIRE(integral < epsilon);
}

TEST_CASE("integrate const from 0 to 1 results in const")
{
    auto const value = GENERATE(1.0f, 2.0f, 100.0f, 44100.0f);
    std::vector<float> generated_waveform;
    float sample_rate = GENERATE(1.0f, 2.0f, 100.0f, 200.0f);
    generated_waveform.resize(static_cast<std::size_t>(sample_rate), value);

    auto const integral = test_helpers::integrate(generated_waveform, sample_rate);

    constexpr auto epsilon = 0.001f;
    REQUIRE(std::abs(integral - value) < epsilon);
}
