#include <iostream>
#include "Spisok.h"
#include <gtest/gtest.h>

using namespace std;

void Spisok_Init(Spisok& spisok) {
	spisok.AddNode(1);
	spisok.AddNode(2);
	spisok.AddNode(3);
	spisok.AddNode(4);
	spisok.AddArc(1, 2);
	spisok.AddArc(1, 3);
	spisok.AddArc(2, 3);
	spisok.AddArc(2, 4);
	spisok.AddArc(3, 4);
}

TEST(SpisokTest, empty_TEST) {
	Spisok spisok1;
	EXPECT_EQ(spisok1.empty(), true);
	Spisok spisok2;
	Spisok_Init(spisok2);
	EXPECT_EQ(spisok2.empty(), false);
}

TEST(SpisokTest, clear_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	EXPECT_EQ(spisok.CountNodes(), 4);
	spisok.clear();
	EXPECT_EQ(spisok.CountNodes(), 0);
}

TEST(SpisokTest, CheckNode_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	EXPECT_EQ(spisok.CheckNode(1), true);
	EXPECT_EQ(spisok.CheckNode(2), true);
	EXPECT_EQ(spisok.CheckNode(3), true);
	EXPECT_EQ(spisok.CheckNode(4), true);
	EXPECT_EQ(spisok.CheckNode(5), false);
}
TEST(SpisokTest, CheckArc_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	EXPECT_EQ(spisok.CheckArc(1,2), true);
	EXPECT_EQ(spisok.CheckArc(1,3), true);
	EXPECT_EQ(spisok.CheckArc(2,3), true);
	EXPECT_EQ(spisok.CheckArc(2,4), true);
	EXPECT_EQ(spisok.CheckArc(3,4), true);
	EXPECT_EQ(spisok.CheckArc(1,1), false);
}

TEST(SpisokTest, CountNode_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	EXPECT_EQ(spisok.CountNodes(), 4);
	spisok.clear();
	EXPECT_EQ(spisok.CountNodes(), 0);
}

TEST(SpisokTest, CountArcs_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	EXPECT_EQ(spisok.CountArcs(), 5);
	spisok.clear();
	EXPECT_EQ(spisok.CountArcs(), 0);
}

TEST(SpisokTest, NodeDegree_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	EXPECT_EQ(spisok.NodeDegree(1), 2);
	EXPECT_EQ(spisok.NodeDegree(2), 3);
	EXPECT_EQ(spisok.NodeDegree(3), 3);
	EXPECT_EQ(spisok.NodeDegree(4), 2);
	EXPECT_EQ(spisok.NodeDegree(5), 0);
}

TEST(SpisokTest, AddNode_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	EXPECT_EQ(spisok.CountNodes(), 4);
	spisok.AddNode(1);
	EXPECT_EQ(spisok.CountNodes(), 4);
	spisok.AddNode(5);
	EXPECT_EQ(spisok.CountNodes(), 5);
}

TEST(SpisokTest, AddArc_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	EXPECT_EQ(spisok.CountArcs(), 5);
	spisok.AddArc(1, 2);
	EXPECT_EQ(spisok.CountArcs(), 5);
	spisok.AddArc(1, 5);
	EXPECT_EQ(spisok.CountArcs(), 5);
	spisok.AddArc(5, 1);
	EXPECT_EQ(spisok.CountArcs(), 5);
	spisok.AddArc(1, 4);
	EXPECT_EQ(spisok.CountArcs(), 6);
}

TEST(SpisokTest, DeleteNode_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	spisok.DeleteNode(5);
	EXPECT_EQ(spisok.CountNodes(), 4);
	spisok.DeleteNode(3);
	EXPECT_EQ(spisok.CountNodes(), 3);
	EXPECT_EQ(spisok.CountArcs(), 2);
	spisok.DeleteNode(1);
	EXPECT_EQ(spisok.CountNodes(), 2);
	EXPECT_EQ(spisok.CountArcs(), 1);
}

TEST(SpisokTest, DeleteArc_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	spisok.DeleteArc(1, 5);
	EXPECT_EQ(spisok.CountArcs(), 5);
	spisok.DeleteArc(1, 2);
	EXPECT_EQ(spisok.CountArcs(), 4);
}

TEST(SpisokTest, NodeIterator_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	int a[4];
	int i = 0;
	for (NodeIterator it = spisok.beginN(); it != spisok.endN(); ++it, i++) {
		a[i] = *it;
	}
	EXPECT_EQ(a[0],1);
	EXPECT_EQ(a[1], 2);
	EXPECT_EQ(a[2], 3);
	EXPECT_EQ(a[3], 4);
}

TEST(SpisokTest, ArcIterator_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	int a[10];
	int i = 0;
	for (ArcIterator it = spisok.beginA(); it != spisok.endA(); ++it, i++) {
		a[i] = *it;
	}
	EXPECT_EQ(a[0], 2);
	EXPECT_EQ(a[1], 3);
	EXPECT_EQ(a[2], 1);
	EXPECT_EQ(a[3], 3);
	EXPECT_EQ(a[4], 4);
	EXPECT_EQ(a[5], 1);
	EXPECT_EQ(a[6], 2);
	EXPECT_EQ(a[7], 4);
	EXPECT_EQ(a[8], 2);
	EXPECT_EQ(a[9], 3);
}

TEST(SpisokTest, IncidentArcIterator_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	int a[2];
	int i = 0;
	for (IncidentArcIterator it = spisok.beginI(spisok.GetHead()); it != spisok.endI(spisok.GetHead()); ++it, i++) {
		a[i] = *it;
	}
	EXPECT_EQ(a[0], 2);
	EXPECT_EQ(a[1], 3);
}

TEST(SpisokTest, AdjacentNodeIterator_TEST) {
	Spisok spisok;
	Spisok_Init(spisok);
	int a[2];
	int i = 0;
	for (AdjacentNodeIterator it = spisok.beginAdj(spisok.GetHead()); it != spisok.endAdj(spisok.GetHead()); ++it, i++) {
		a[i] = *it;
	}
	EXPECT_EQ(a[0], 2);
	EXPECT_EQ(a[1], 3);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}