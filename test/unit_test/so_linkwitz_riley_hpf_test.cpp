#include "tests_common.hpp"

// Text fixture for Class-Under-Test (CUT)
struct so_linkwitz_riley_hpf : public testing::Test {
    SO_LINKWITZ_RILEY_HPF* m_filter;
    Biquad::tp_coeffs m_coeffs;

    void SetUp()
    {
        m_filter = new SO_LINKWITZ_RILEY_HPF();
        m_coeffs = m_filter->calculate_coeffs(FC, SAMPLING_RATE);
    }

    void TearDown() { delete m_filter; }
};

TEST_F(so_linkwitz_riley_hpf, coeff_calculation)
{
    // Assert
    EXPECT_NEAR(m_coeffs.a0, 0.73667, 0.00001);
#ifdef DEBUG_OUTPUT
    debug_print(m_coeffs);
#endif
}

TEST_F(so_linkwitz_riley_hpf, process_0)
{
    // Act
    auto yn = m_filter->process(TEST_SAMPLE_0);
    // Assert
    EXPECT_DOUBLE_EQ(yn, 0);
#ifdef DEBUG_OUTPUT
    std::cout << "yn: " << yn << std::endl;
#endif
}

TEST_F(so_linkwitz_riley_hpf, process_1)
{
    // Act
    auto yn = m_filter->process(TEST_SAMPLE_1);
    // Assert
    EXPECT_NEAR(yn, 0.73667, 0.00001);
#ifdef DEBUG_OUTPUT
    std::cout << "yn: " << yn << std::endl;
#endif
}
