#include "libraries.h"
#include <gtest/gtest.h>

TEST(Sound_EffectTest, Get_Sound_TEST) {
	Sound_Effect sound_effect(1,"Lalala");
	EXPECT_EQ(sound_effect.Get_Sound(), "Lalala");
}
TEST(Sound_EffectTest, Get_Sound_Effect_Number_TEST) {
	Sound_Effect sound_effect(1, "Lalala");
	EXPECT_EQ(sound_effect.Get_Sound_Effect_Number(), 1);
}
TEST(Sound_EffectTest, Sound_Constructor_TEST) {
	EXPECT_THROW(Sound_Effect sound(-10, "Lalala"), invalid_argument);
}

TEST(LevelTest,Get_Level_Number_TEST) {
	Level level(1);
	EXPECT_EQ(level.Get_Level_Number(), 1);
}
TEST(LevelTest, Get_Level_Difficulty_TEST) {
	Level level(1);
	EXPECT_EQ(level.Get_Level_Difficulty(), "");
	level.Set_Level_Difficulty("Hard");
	EXPECT_EQ(level.Get_Level_Difficulty(), "Hard");
}
TEST(LevelTest, Level_Constructor_TEST) {
	EXPECT_THROW(Level level(-10), invalid_argument);
}

TEST(WorkerTest, Worker_Constructor_TEST) {
	EXPECT_THROW(Worker worker("Pasha", -1000), invalid_argument);
}
TEST(WorkerTest, Get_Worker_Name_TEST) {
	Worker worker("Pasha", 100000);
	EXPECT_EQ(worker.Get_Worker_Name(), "Pasha");
}
TEST(WorkerTest, Get_Worker_Salary_TEST) {
	Worker worker("Pasha", 100000);
	EXPECT_EQ(worker.Get_Worker_Salary(), 100000);
	worker.Set_Worker_Salary(150000);
	EXPECT_EQ(worker.Get_Worker_Salary(), 150000);
	EXPECT_THROW(worker.Set_Worker_Salary(-100), invalid_argument);
}
TEST(WorkerTest, Get_Worker_Budget_TEST) {
	Worker worker("Pasha", 100000);
	EXPECT_EQ(worker.Get_Worker_Budget(), 0);
	worker.Take_Salary(100000);
	EXPECT_EQ(worker.Get_Worker_Budget(), 100000);
	EXPECT_THROW(worker.Take_Salary(-100), invalid_argument);
}

TEST(Game_DevelopmentTest, Get_Game_list_TEST) {
	Game_Development game_development;
	Game game1("TicTacToe", "Puzzle");
	Game game2("Sapper", "Puzzle");
	EXPECT_EQ(game_development.Get_Game_list().size(), 0);
	game_development.Add_Game(game1);
	game_development.Add_Game(game2);
	EXPECT_EQ(game_development.Get_Game_list().size(), 2);
	game_development.Delete_Game("TicTacToe");
	EXPECT_THROW(game_development.Delete_Game("Detroit"), invalid_argument);
	EXPECT_EQ(game_development.Get_Game_list().size(), 1);
}
TEST(Game_DevelopmentTest, Get_Budget_TEST) {
	Game_Development game_development;
	EXPECT_EQ(game_development.Get_Budget(), 0);
	game_development.Set_Budget(1000000);
	EXPECT_EQ(game_development.Get_Budget(), 1000000);
}
TEST(Game_DevelopmentTest, Pay_Worker_TEST) {
	Game_Development game_development;
	game_development.Set_Budget(1000000);
	Worker worker("Pasha", 100000);
	game_development.Pay_Worker(worker);
	EXPECT_EQ(worker.Get_Worker_Budget(), 100000);
	EXPECT_EQ(game_development.Get_Budget(), 900000);
	game_development.Set_Budget(90000);
	EXPECT_THROW(game_development.Pay_Worker(worker), invalid_argument);
}
TEST(Game_DevelopmentTest, Realise_Game_TEST) {
	Game_Development game_development;
	Game game("TicTacToe", "Puzzle");
	game_development.Add_Game(game);
	testing::internal::CaptureStdout();
	game_development.Release_Game(game.Get_Game_Name());
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "TicTacToe is releasing";
	EXPECT_EQ(output, expectedOutput);
}
TEST(Game_DevelopmentTest, Take_Sponce_TEST) {
	Game_Development game_development;
	game_development.Take_Sponce(100000);
	EXPECT_EQ(game_development.Get_Budget(), 100000);
	EXPECT_THROW(game_development.Take_Sponce(-10), invalid_argument);
}

TEST(GameTest, Get_Game_Name_TEST) {
	Game game("TicTacToe", "Puzzle");
	EXPECT_EQ(game.Get_Game_Name(), "TicTacToe");
}
TEST(GameTest, Get_Game_Ganre_TEST) {
	Game game("TicTacToe", "Puzzle");
	EXPECT_EQ(game.Get_Game_Ganre(), "Puzzle");
}
TEST(GameTest, Get_Level_list_TEST) {
	Game game("TicTacToe", "Puzzle");
	Level level1(1);
	Level level2(2);
	EXPECT_EQ(game.Get_Level_list().size(), 0);
	game.Add_Level(level1);
	game.Add_Level(level2);
	EXPECT_EQ(game.Get_Level_list().size(), 2);
}
TEST(GameTest, Get_Sound_Effect_list_TEST) {
	Game game("TicTacToe", "Puzzle");
	Sound_Effect sound_effect1(1,"Lalala");
	Sound_Effect sound_effect2(2, "Pupupu");
	EXPECT_EQ(game.Get_Sound_Effect_list().size(), 0);
	game.Add_Sound_Effect(sound_effect1);
	game.Add_Sound_Effect(sound_effect2);
	EXPECT_EQ(game.Get_Sound_Effect_list().size(), 2);
}
TEST(GameTest, Get_Developer_list_TEST) {
	Game game("TicTacToe", "Puzzle");
	Developer developer1("Pasha", 100000);
	Developer developer2("Sasha",100000);
	EXPECT_EQ(game.Get_Developer_list().size(), 0);
	game.Add_Developer(developer1);
	game.Add_Developer(developer2);
	EXPECT_EQ(game.Get_Developer_list().size(), 2);
}
TEST(GameTest, Get_Designer_list_TEST) {
	Game game("TicTacToe", "Puzzle");
	Designer designer1("Pasha", 100000);
	Designer designer2("Sasha", 100000);
	EXPECT_EQ(game.Get_Designer_list().size(), 0);
	game.Add_Designer(designer1);
	game.Add_Designer(designer2);
	EXPECT_EQ(game.Get_Designer_list().size(), 2);
}
TEST(GameTest, Get_Tester_list_TEST) {
	Game game("TicTacToe", "Puzzle");
	Tester tester1("Pasha", 100000);
	Tester tester2("Sasha", 100000);
	EXPECT_EQ(game.Get_Tester_list().size(), 0);
	game.Add_Tester(tester1);
	game.Add_Tester(tester2);
	EXPECT_EQ(game.Get_Tester_list().size(), 2);
}

TEST(DeveloperTest, Develop_TEST) {
	Developer developer("Pasha", 100000);
	testing::internal::CaptureStdout();
	developer.Develop();
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "Pasha start develop something\n";
	EXPECT_EQ(output, expectedOutput);
}
TEST(Interface_DeveloperTest, Develop_TEST) {
	Interface_Developer developer("Pasha", 100000);
	testing::internal::CaptureStdout();
	developer.Develop();
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "Pasha start develop game interface\n";
	EXPECT_EQ(output, expectedOutput);
}
TEST(Level_DeveloperTest, Develop_TEST) {
	Level_Developer developer("Pasha", 100000);
	testing::internal::CaptureStdout();
	developer.Develop();
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "Pasha start develop some game level\n";
	EXPECT_EQ(output, expectedOutput);
}

TEST(DesignerTest, Design_TEST) {
	Designer designer("Pasha", 100000);
	testing::internal::CaptureStdout();
	designer.Design();
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "Pasha start disign something\n";
	EXPECT_EQ(output, expectedOutput);
}
TEST(Level_DesignerTest, Design_TEST) {
	Level_Designer designer("Pasha", 100000);
	testing::internal::CaptureStdout();
	designer.Design();
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "Pasha start design some game level\n";
	EXPECT_EQ(output, expectedOutput);
}
TEST(Sound_Effect_DesignerTest, Design_TEST) {
	Sound_Effect_Designer designer("Pasha", 100000);
	testing::internal::CaptureStdout();
	designer.Design();
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "Pasha start design some game sound effect\n";
	EXPECT_EQ(output, expectedOutput);
}

TEST(TesterTest, Test_TEST) {
	Tester tester("Pasha", 100000);
	testing::internal::CaptureStdout();
	tester.Test();
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "Pasha start test something\n";
	EXPECT_EQ(output, expectedOutput);
}
TEST(Level_TesterTest, Test_TEST) {
	Level_Tester tester("Pasha", 100000);
	testing::internal::CaptureStdout();
	tester.Test();
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "Pasha start test some game level\n";
	EXPECT_EQ(output, expectedOutput);
}
TEST(Interface_TesterTest, Test_TEST) {
	Interface_Tester tester("Pasha", 100000);
	testing::internal::CaptureStdout();
	tester.Test();
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "Pasha start test game interface\n";
	EXPECT_EQ(output, expectedOutput);
}

TEST(SponcorTest, Sponcor_Constructor_TEST) {
	Sponcor sponcor(1000000);
	EXPECT_EQ(sponcor.Get_Budget(), 1000000);
	EXPECT_THROW(Sponcor sponcor(-1), invalid_argument);
}
TEST(SponcorTest, Get_Budget_TEST) {
	Sponcor sponcor(1000000);
	EXPECT_EQ(sponcor.Get_Budget(), 1000000);
	sponcor.Set_Budget(20000);
	EXPECT_EQ(sponcor.Get_Budget(), 20000);
}
TEST(SponcorTest, Sponce_TEST) {
	Sponcor sponcor(1000000);
	Game_Development game_development;
	sponcor.Sponce(game_development,600000);
	EXPECT_EQ(sponcor.Get_Budget(), 400000);
	EXPECT_EQ(game_development.Get_Budget(), 600000);
	EXPECT_THROW(sponcor.Sponce(game_development, 600000), invalid_argument);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}