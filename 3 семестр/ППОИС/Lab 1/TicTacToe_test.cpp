#include <iostream>
#include <sstream>
#include <vector>
#include "TicTacToe.h"
#include <gtest/gtest.h>


TEST(TicTacToeTest, TestValidMove) {
    TicTacToe game(3);
    EXPECT_TRUE(game.IsValidMove({ 0, 0 }));
    *game[{0, 0}] = 'X';
    EXPECT_FALSE(game.IsValidMove({ 0, 0 }));
    EXPECT_FALSE(game.IsValidMove({ 4, 3 }));
}

TEST(TicTacToeTest, TestOperator) {
    TicTacToe game(3);
    char* cell = game[{-1, 2}];
    EXPECT_EQ(cell, nullptr);
}

TEST(TicTacToeTest, TestCheckWinnerVertical) {
    TicTacToe game(3);
    *game[{0, 0}] = 'O';
    *game[{0, 1}] = 'O';
    *game[{0, 2}] = 'O';
    EXPECT_TRUE(game.CheckWinner());
}

TEST(TicTacToeTest, TestCheckWinnerHorizontal) {
    TicTacToe game(3);
    *game[{0, 0}] = 'X';
    *game[{1, 0}] = 'X';
    *game[{2, 0}] = 'X';
    EXPECT_TRUE(game.CheckWinner());
}

TEST(TicTacToeTest, TestCheckWinnerDiagonal) {
    TicTacToe game1(3);
    *game1[{0, 0}] = 'X';
    *game1[{1, 1}] = 'X';
    *game1[{2, 2}] = 'X';
    EXPECT_TRUE(game1.CheckWinner());

    TicTacToe game2(3);
    *game2[{0, 2}] = 'O';
    *game2[{1, 1}] = 'O';
    *game2[{2, 0}] = 'O';
    EXPECT_TRUE(game2.CheckWinner());
}

TEST(TicTacToeTest, TestPlayerSwitch) {
    TicTacToe game(3);
    EXPECT_EQ(game.GetCurrentPlayer(), 'X');
    game.PlayerSwitch();
    EXPECT_EQ(game.GetCurrentPlayer(), 'O');
    game.PlayerSwitch();
    EXPECT_EQ(game.GetCurrentPlayer(), 'X');
}
TEST(TicTacToeTest, TestDisplayBoard) {
    TicTacToe game(3);

    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    game.DisplayBoard();

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput =
        "-------\n"
        "| | | |\n"
        "-------\n"
        "| | | |\n"
        "-------\n"
        "| | | |\n"
        "-------\n";

    EXPECT_EQ(output.str(), expectedOutput);

    *game[{0, 0}] = 'X';
    *game[{1, 1}] = 'O';
    *game[{2, 2}] = 'X';

    output.str("");
    output.clear();

    oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

    game.DisplayBoard();

    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutputAfterMoves =
        "-------\n"
        "|X| | |\n"
        "-------\n"
        "| |O| |\n"
        "-------\n"
        "| | |X|\n"
        "-------\n";

    EXPECT_EQ(output.str(), expectedOutputAfterMoves);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}