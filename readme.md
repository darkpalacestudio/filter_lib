# C++20 Audio Filter Library [![Build Status](https://github.com/darkpalacestudio/filter_lib/actions/workflows/full_test_verification.yml/badge.svg)](https://github.com/Laguna1989/JamTemplateCpp/actions/workflows/unittests.yml)   ![GitHub repo size](https://img.shields.io/github/repo-size/darkpalacestudio/filter_lib)

Audio biquad filter library that is based on [DSP-Cpp-filters](https://github.com/dimtass/DSP-Cpp-filters).

As the original repository does not seem to be maintained, I created this fork. It contains the following upgrades
compared to the original repo:

- Upgrade to cpp20
    - This includes `constexpr`, `std::numbers` and other modern language features
- Implement consistent use of floating point types throughout the code
- Reformat all files via `clang-format`
- Add some unit integration tests (only for some filters)
- Add CI job for github actions
- Fix for SO_APF [Link to issue](https://github.com/dimtass/DSP-Cpp-filters/issues/5)

