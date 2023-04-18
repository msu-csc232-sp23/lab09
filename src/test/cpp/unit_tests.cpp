/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2023
 *
 * @file      google_test_runner.cpp
 * @authors   Jim Daehn <jdaehn@missouristate.edu>
 * @brief     Google Test implementation template.
 */

#include "csc232.h"
#include "gtest/gtest.h"

/**
 * @brief Namespace to encapsulate course specific macros, declarations and definitions.
 */
namespace csc232 {
    static int possiblePoints{0};
    static int earnedPoints{0};
    static const int MAX_CORRECTNESS_PTS{2};

    /**
     * @brief Base test fixture that sets up grading for this assignment.
     */
    class CSC232BaseTestFixture : public ::testing::Test {
    public:
        CSC232BaseTestFixture() : buffer{{}}, sbuf{nullptr} {
            // Intentionally empty
        }

    protected:
        void SetUp() override {
            ::testing::FLAGS_gtest_death_test_style = "threadsafe";
            // Redirect cout to our stringstream buffer or any other ostream
            sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            AdditionalSetup();

            possiblePoints += 1;
        }

        void TearDown() override {
            // When done redirect cout to its old self
            std::cout.rdbuf(sbuf);
            sbuf = nullptr;

            AdditionalTearDown();

            if (!HasFailure()) {
                earnedPoints += 1;
            }
        }

        virtual void AdditionalSetup() {
            /* template method for any customized additional setup */
        }

        virtual void AdditionalTearDown() {
            /* template method for any customized additional setup */
        }

        // Reusable objects for each unit test in this test fixture and any of its children
        std::stringstream buffer;
        std::streambuf *sbuf;
        /*
         * With the above in place, you can now have tests on output statements 
         * like this:
         * 
         * <some function call or executable that inserts info into output stream...>
         * const std::string expected{ "1/1/1902\n" }; // what you expect to have been inserted
         * const std::string actual{ buffer.str( ) };  // what was actually inserted
         * EXPECT_EQ( expected, actual );
         */
    };

    class Task1TestFixture : public CSC232BaseTestFixture {
    protected:
        // Reusable objects for each unit test in this test fixture
    };

    size_t ValidateTaskIsReady(const std::string &task) {
        // Read csc232.h file and verify TEST_TASKn is toggled to TRUE
        std::string taskString = "TEST_TASK" + task + " TRUE";
        const char *search_string = taskString.c_str();
        const char *filename = "csc232.h";
        std::ifstream input_stream{filename, std::ios::in};
        if (!input_stream) {
            std::cerr << "Unable to open csc232.h header file.\n";
            std::exit(EXIT_FAILURE);
        }

        // Read the entire file into memory
        std::string file_contents;
        std::string current_line;
        while (getline(input_stream, current_line)) {
            file_contents += current_line + '\n';
        }
        input_stream.close();
        return file_contents.find(search_string);
    }

    TEST_F(Task1TestFixture, TaskIsReadyForEvaluation) {
        size_t pos = ValidateTaskIsReady("1");
        EXPECT_GT(static_cast<int>(pos), 0);
        if (HasFailure()) {
            std::cerr
                    << "It appears you have not toggled the TEST_TASK1 macro. Please do so before executing this test suite.";
            std::exit(EXIT_FAILURE);
        }
    }

    TEST_F(Task1TestFixture, CopyConstructorCopiesArrayElements) {
        std::string data[] = {"lex & yacc", "sed & awk", "Javascript & AJAX"};
        auto booksListPtr = std::make_unique<ArrayList<std::string>>(data, 3);
        for (int i{0}; i < 3; ++i) {
            EXPECT_STREQ(data[i].c_str(), booksListPtr->getEntry(i + 1).c_str());
        }
    }

    TEST_F(Task1TestFixture, CopyConstructorCopiesNoMoreThanItCanStore) {
        std::string data[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        auto booksListPtr = std::make_unique<ArrayList<std::string>>(data, 10);
        for (int i{0}; i < 5; ++i) {
            EXPECT_STREQ(data[i].c_str(), booksListPtr->getEntry(i + 1).c_str());
        }

        for (int i{5}; i < 10; ++i) {
            EXPECT_THROW(booksListPtr->getEntry(i + 1), PrecondViolatedExcep);
        }
    }

    class Task2TestFixture : public CSC232BaseTestFixture {
        // Test replace method
    };

    TEST_F(Task2TestFixture, TaskIsReadyForEvaluation) {
        size_t pos = ValidateTaskIsReady("2");
        EXPECT_GT(static_cast<int>(pos), 0);
        if (HasFailure()) {
            std::cerr
                    << "It appears you have not toggled the TEST_TASK2 macro. Please do so before executing this test suite.";
            std::exit(EXIT_FAILURE);
        }
    }

    TEST_F(Task2TestFixture, ReplaceCanReplaceItem) {
        auto linkedListPtr = std::make_unique<LinkedList<std::string>>();
        linkedListPtr->insert(1, "CSC232");
        std::string replacement{"Data Structures"};
        EXPECT_NO_THROW(linkedListPtr->replace(1, replacement));
    }

    TEST_F(Task2TestFixture, ReplaceThrowsExceptionIfReplacementAtPosition0) {
        auto linkedListPtr = std::make_unique<LinkedList<std::string>>();
        linkedListPtr->insert(0, "CSC232");
        std::string replacement{"Data Structures"};
        EXPECT_THROW(linkedListPtr->replace(1, replacement), PrecondViolatedExcep);
    }

    TEST_F(Task2TestFixture, ReplaceThrowsExceptionIfReplacementAtPositionGreaterThanListLength) {
        auto linkedListPtr = std::make_unique<LinkedList<std::string>>();
        linkedListPtr->insert(1, "CSC232");
        std::string replacement{"Data Structures"};
        EXPECT_THROW(linkedListPtr->replace(2, replacement), PrecondViolatedExcep);
    }

    class Task3TestFixture : public CSC232BaseTestFixture {
        // Test copy constructor
    };

    TEST_F(Task3TestFixture, TaskIsReadyForEvaluation) {
        size_t pos = ValidateTaskIsReady("3");
        EXPECT_GT(static_cast<int>(pos), 0);
        if (HasFailure()) {
            std::cerr
                    << "It appears you have not toggled the TEST_TASK3 macro. Please do so before executing this test suite.";
            std::exit(EXIT_FAILURE);
        }
    }

    TEST_F(Task3TestFixture, CopyConstructorMakesDeepCopy) {
        LinkedList<std::string> srcList;
        srcList.insert(1, "Do CSC232 Lab 9");
        srcList.insert(2, "Install Ubuntu on my Laptop");

        LinkedList<std::string> destList{srcList};
        for (int i{1}; i <= 2; ++i) {
            EXPECT_STREQ(srcList.getEntry(i).c_str(), destList.getEntry(i).c_str());
            std::string item{srcList.getEntry(i)};
            for (auto &c: item) {
                c = static_cast<char>(std::tolower(c));
            }
            srcList.replace(i, item);
            EXPECT_STRNE(srcList.getEntry(i).c_str(), destList.getEntry(i).c_str());
        }
    }

} // end namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int result{RUN_ALL_TESTS()};
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n\n";
    std::cout << std::left << std::setw(21) << "Earned Points:"
              << std::right << std::setw(5) << static_cast<double>(csc232::earnedPoints) << std::endl;
    std::cout << std::left << std::setw(21) << "Possible Points:"
              << std::right << std::setw(5) << static_cast<double>(csc232::possiblePoints) << std::endl;
    double percentCorrect{static_cast<double>(csc232::earnedPoints) / csc232::possiblePoints};
    double correctnessPoints{csc232::possiblePoints != 0 ? percentCorrect * csc232::MAX_CORRECTNESS_PTS
                                                         : 0};
    std::cout << std::left << std::setw(20) << "\nPercent Correct:"
              << std::right << std::setw(5) << percentCorrect * 100 << "%" << std::endl;
    std::cout << std::left << std::setw(21) << "Correctness Points:"
              << std::right << std::setw(5) << correctnessPoints << "\n" << std::endl;
    return result;
}
