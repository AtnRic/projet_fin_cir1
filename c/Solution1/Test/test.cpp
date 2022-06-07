#include "pch.h"
#include "../algo_labyrinthe/Structures.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(recherche_loc_tp, recherche_loc_tp1) {
	Teleporteurs_Paire* test_return;
	test_return = (Teleporteurs_Paire*)malloc(sizeof(Teleporteurs_Paire));
	int nb_pairs = 1;
	char* maze = "aaaaaaaaaaaaaaaaaaaaaaaa";
	int size = 25;
	test_return = recherche_loc_tp(nb_pairs, maze, size);
	EXPECT_TRUE(test_return == NULL)
		<< "Where test_return value: " << *test_return
		<< " not equal : " << NULL
		<< ".";
}

TEST(recherche_loc_tp, recherche_loc_tp2) {
	Teleporteurs_Paire* test_return;
	test_return = (Teleporteurs_Paire*)malloc(sizeof(Teleporteurs_Paire));
	int nb_pairs = 1;
	char* maze = "lmaaaaaaaaaaaaaaaaaaaaaa";
	int size = 25;
	test_return = recherche_loc_tp(nb_pairs, maze, size);
	EXPECT_TRUE((test_return->entree == 1 && test_return->sortie == 2) || (test_return->sortie == 1 && test_return->entree == 2))
		<< "Where test_return entree value: " << test_return->entree << " and test_return sortie value: " << test_return->sortie
		<< "are not equal neither 1 and 2" << " or 2 and 1.";
}

