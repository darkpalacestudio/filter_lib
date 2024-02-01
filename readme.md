# filter_lib

Audio biquad filter library that is based on [DSP-Cpp-filters](https://github.com/dimtass/DSP-Cpp-filters).

As the original repository does not seem to be maintained, I created this fork. It contains the following upgrades
compared to the original repo:

- Upgrade to cpp20
- Add some tests
- Add CI for testing to build on win, linux and mac.
- Fix for SO_APF [Link to issue](https://github.com/dimtass/DSP-Cpp-filters/issues/5)

