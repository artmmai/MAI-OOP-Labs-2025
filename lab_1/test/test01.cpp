#include <gtest/gtest.h>
#include "../include/replace.hpp"


TEST(ReplaceEveryNthTest, BasicReplacement){
    std::string testString = "Vader said: No, I am your father!";
    std::string expected = "Vader soid: No, I am your fother!";

    std::string result = ReplaceEveryNth(testString, 2, 'a', 'o');
    EXPECT_EQ(result, expected);
}

TEST(ReplaceEveryNth, NoReplacement){
    std::string testString = "papa i mama";
    std::string expected = "papa i mama";
    
    std::string result = ReplaceEveryNth(testString, 0, 'i', 'z');

    EXPECT_EQ(result, expected);
}

TEST(ReplaceEveryNth, EmptyString){
    std::string testString = "";
    std::string expected = "";

    std::string result = ReplaceEveryNth(testString, 3, 'z', 'o');

    EXPECT_EQ(result, expected);
}

TEST(ReplaceEveryNth, EverySecondReplacement){
    std::string testString = "bimbimbimbambambam";
    std::string expected = "zimzimzimzamzamzam";

    std::string result = ReplaceEveryNth(testString, 1, 'b', 'z');

    EXPECT_EQ(result, expected);

}

TEST(ReplaceEveryNth, ReplacePunctuationMarks){
    std::string testString = "Украл, выпил - в тюрьму. Украл, выпил - в тюрьму. Романтика...";
    std::string expected = "Украл, выпил - в тюрьму. Украл, выпил - в тюрьму. Романтика)..";

    std::string result = ReplaceEveryNth(testString, 3, '.', ')');
    EXPECT_EQ(result, expected);
}

TEST(ReplaceEveryNth, nIsLessThanZero){
    std::string testString = "I'll be back";
    std::string expected = "I'll be back";

    std::string result(ReplaceEveryNth(testString, -1, 'b', 'a'));
    EXPECT_EQ(result, expected);

}

TEST(ReplaceEveryNth, nBiggerThanCounter){
    std::string testString = "Saint-Petersburg";
    std::string expected = "Saint-Petersburg";

    std::string result = ReplaceEveryNth(testString, 52, 'i', 'k');
}

TEST(ReplaceEveryNth, SpaceReplacement){
    std::string testString = "Saint Petersburg";
    std::string expected = "Saint Petersburg";

    std::string result = ReplaceEveryNth(testString, 1, ' ', '-');
}

TEST(ReplaceEveryNth, QuestionMarkReplacement){
    std::string testString = "Are ya winning son,";
    std::string expected = "Are ya winning son?";

    std::string result = ReplaceEveryNth(testString, 1, ',', '?');
    EXPECT_EQ(result, expected);
}

TEST(ReplaceEveryNth, EveryOneReplacement){
    std::string testString = "oooooooooooooooooooooooooooooooooooooooooo";
    std::string expected = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    
    std::string result = ReplaceEveryNth(testString, 1, 'o', 'z');
    EXPECT_EQ(result, expected);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}