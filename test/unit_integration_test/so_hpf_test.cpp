#include "test_helpers.hpp"
#include <catch2/catch_test_macros.hpp>
#include <filter_lib/so_hpf.hpp>
#include <Approvals.h>

TEST_CASE("SO HPF does not affect frequency significantly above cutoff")
{
    SO_HPF filter;
    auto const filter_frequency = 10.0f;
    auto const sampling_rate_hz = 44100.0f;
    filter.calculate_coeffs(1.0f, filter_frequency, sampling_rate_hz);

    auto const input = test_helpers::createInputWithSine(5000.0f, 44100.0f);

    std::vector<float> output;
    output.resize(input.size(), 0.0f);

    for (auto i = 0u; i != input.size(); ++i) {
        output[i] = filter.process(input[i]);
    }

    constexpr float epsilon { 0.004f };
    for (auto i = 0u; i != input.size(); ++i) {
        REQUIRE(output[i] - input[i] < epsilon);
    }

    ApprovalTests::Approvals::verifyAll(output);
}

TEST_CASE("SO HPF attenuates frequency below cutoff")
{
    SO_HPF filter;
    auto const filter_frequency = 5000.0f;
    auto const sampling_rate_hz = 44100.0f;
    filter.calculate_coeffs(1.0f, filter_frequency, sampling_rate_hz);

    auto const input = test_helpers::createInputWithSine(10.0f, 44100.0f);

    std::vector<float> output;
    output.resize(input.size(), 0.0f);

    for (auto i = 0u; i != input.size(); ++i) {
        output[i] = filter.process(input[i]);
    }

    constexpr float epsilon { 0.002f };
    for (auto i = 0u; i != input.size(); ++i) {
        REQUIRE(output[i] < epsilon);
    }

    ApprovalTests::Approvals::verifyAll(output);
}
