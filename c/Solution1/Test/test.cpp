#include "pch.h"
#include "../algo_labyrinthe/Structures.h"

struct TestVariable : public ::testing::Test{
	int* nb_pairs;
	char* maze;
	int* size;

	virtual void SetUp() override {
		fprintf(stderr, "\nCommencement des tests : \n");
		nb_pairs = new int(1);
		maze = "aaaaaaaaaaaaaaaaaaaaaaaa";
		size = new int(25);

	}

	virtual void TearDown() override {
		fprintf(stderr, "\n Fin des tests.\n");
		delete nb_pairs;
		delete size;
	}
};
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(recherche_loc_tp_pas_de_tp, recherche_loc_tp1) {
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

TEST(recherche_loc_tp_un_seul_emplacement, recherche_loc_tp2) {
	Teleporteurs_Paire* test_return;
	test_return = (Teleporteurs_Paire*)malloc(sizeof(Teleporteurs_Paire));
	int nb_pairs = 1;
	char* maze = "lmaaaaaaaaaaaaaaaaaaaaaa";
	int size = 25;
	test_return = recherche_loc_tp(nb_pairs, maze, size);
	EXPECT_TRUE((test_return->entree == 1 && test_return->sortie == 2) || (test_return->sortie == 1 && test_return->entree == 2))
		<< "Where test_return entree value: " << test_return->entree 
		<< " and test_return sortie value: " << test_return->sortie
		<< "are not equal neither 1 and 2" << " or 2 and 1.";
}


TEST(recherche_loc_tp_plusieurs_emplacement, recherche_loc_tp3) {
	Teleporteurs_Paire* test_return;
	test_return = (Teleporteurs_Paire*)malloc(sizeof(Teleporteurs_Paire));
	int nb_pairs = 1;
	char* maze = "lmllllllllllllllllllllll";
	int size = 25;
	test_return = recherche_loc_tp(nb_pairs, maze, size);
	EXPECT_TRUE((test_return->entree == 1 && test_return->sortie == 2) || (test_return->sortie == 1 && test_return->entree == 2))
		<< "Where test_return entree value: " << test_return->entree
		<< " and test_return sortie value: " << test_return->sortie
		<< "are not equal neither 1 and 2" << " nor 2 and 1.";
}