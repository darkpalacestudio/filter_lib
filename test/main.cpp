#define APPROVALS_CATCH2_V3
#include "ApprovalTests/ApprovalTests.hpp"

// This puts "received" and "approved" files in approval_tests/ sub-directory,
// keeping the test source directory tidy:
auto directoryDisposer = ApprovalTests::Approvals::useApprovalsSubdirectory("approval_files");
