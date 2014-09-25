#include "gameMaps.h"
#include <iostream>

GameMaps::GameMaps () {
	Type liberalArts ("LArts", "", "", 1.0);
	Type mcs ("MatCS", "Athlt", "LabSc", 2.0);
	Type humanities ("Humns", "SoSci", "Athlt", 2.0);
	Type athlete ("Athlt", "Humns", "MatCS", 2.0);
	Type socialSci ("SoSci", "LabSc", "Humns", 2.0);
	Type labSci ("LabSc", "MatCS", "SoSci", 2.0);

	EnemyUnit libArtsEnemy ("Normal", 1, liberalArts, 5, 10, 50, "black", Square());
	EnemyUnit mcsEnemy ("MCS Student", 1, mcs, 20, 50, 300, "blue", Square());
	EnemyUnit humanitiesEnemy ("Humanities Student", 1, humanities, 7, 30, 200, "gold", Square());
	EnemyUnit athleteEnemy ("Athletic Student", 1, athlete, 15, 200, 500, "firebrick", Square());
	EnemyUnit socialSciEnemy ("Social Science Student", 1, socialSci, 7, 25, 200, "sea green", Square());
	EnemyUnit labSciEnemy ("Lab Science Student", 1, labSci, 10, 100, 350, "turquoise", Square());

	Point pathStart(0,SCREEN_HEIGHT / 3);
	Path path1(pathStart, "eeennnnnnnneeeeeeesssssssssssssswwwwwssseeeeeeeeeeeeeennnneeeeeeeeee");
	Path path2(pathStart, "eennnnneeeesssssssssseeeennnnnnnnnneeeesssssssssseeeennnnnnnnnneeeesssssssssseeeennnnneee");

	static const EnemyUnit map1wave1array[] = {libArtsEnemy, libArtsEnemy, libArtsEnemy, libArtsEnemy, libArtsEnemy, libArtsEnemy};
	vector<EnemyUnit> map1wave1vector (map1wave1array, map1wave1array + sizeof(map1wave1array) / sizeof(map1wave1array[0]) );

	static const EnemyUnit map1wave2array[] = {libArtsEnemy, libArtsEnemy, humanitiesEnemy, libArtsEnemy, libArtsEnemy, humanitiesEnemy, libArtsEnemy, libArtsEnemy, humanitiesEnemy};
	vector<EnemyUnit> map1wave2vector (map1wave2array, map1wave2array + sizeof(map1wave2array) / sizeof(map1wave2array[0]) );

	static const EnemyUnit map1wave3array[] = {libArtsEnemy, libArtsEnemy, socialSciEnemy, libArtsEnemy, libArtsEnemy, libArtsEnemy, socialSciEnemy, humanitiesEnemy, libArtsEnemy, libArtsEnemy, socialSciEnemy, libArtsEnemy, libArtsEnemy, libArtsEnemy, socialSciEnemy, humanitiesEnemy};
	vector<EnemyUnit> map1wave3vector (map1wave3array, map1wave3array + sizeof(map1wave3array) / sizeof(map1wave3array[0]));

	Wave map1wave1 (map1wave1vector);
	Wave map1wave2 (map1wave2vector);
	Wave map1wave3 (map1wave3vector);

	vector<Wave> map1waves;
	map1waves.push_back(map1wave1);
	map1waves.push_back(map1wave2);
	map1waves.push_back(map1wave3);

	Map* map1  = new Map (path1, "forest green", "brown", MAP_HEIGHT, MAP_WIDTH, SQUARE_SIZE, map1waves);

	static const EnemyUnit map2wave1array[] = {humanitiesEnemy, libArtsEnemy, libArtsEnemy, libArtsEnemy, libArtsEnemy, libArtsEnemy, libArtsEnemy, libArtsEnemy};
	vector<EnemyUnit> map2wave1vector (map2wave1array, map2wave1array + sizeof(map2wave1array) / sizeof(map2wave1array[0]) );

	static const EnemyUnit map2wave2array[] = {humanitiesEnemy, humanitiesEnemy, humanitiesEnemy, humanitiesEnemy, humanitiesEnemy, humanitiesEnemy};
	vector<EnemyUnit> map2wave2vector (map2wave2array, map2wave2array + sizeof(map2wave2array) / sizeof(map2wave2array[0]) );

	static const EnemyUnit map2wave3array[] = {mcsEnemy, humanitiesEnemy, labSciEnemy, humanitiesEnemy, labSciEnemy, humanitiesEnemy, labSciEnemy, humanitiesEnemy};
	vector<EnemyUnit> map2wave3vector (map2wave3array, map2wave3array + sizeof(map2wave3array) / sizeof(map2wave3array[0]));

	static const EnemyUnit map2wave4array[] = {mcsEnemy, mcsEnemy, libArtsEnemy, libArtsEnemy, mcsEnemy, mcsEnemy, humanitiesEnemy, humanitiesEnemy, mcsEnemy, mcsEnemy, labSciEnemy, labSciEnemy};
	vector<EnemyUnit> map2wave4vector (map2wave4array, map2wave4array + sizeof(map2wave4array) / sizeof(map2wave4array[0]));

	Wave map2wave1 (map2wave1vector);
	Wave map2wave2 (map2wave2vector);
	Wave map2wave3 (map2wave3vector);
	Wave map2wave4 (map2wave4vector);

	vector<Wave> map2waves;
	map2waves.push_back(map2wave1);
	map2waves.push_back(map2wave2);
	map2waves.push_back(map2wave3);
	map2waves.push_back(map2wave4);


	Map* map2 = new Map (path2, "dark khaki	", "brown", MAP_HEIGHT, MAP_WIDTH, SQUARE_SIZE, map2waves);

	maps.push_back(map1);
	maps.push_back(map2);
}

vector<Map*> GameMaps::getMaps() const {
	return maps;
}

void GameMaps::removeMap() {
	for (int unsigned i = 1; i < maps.size(); i++) {
		maps[i-1] = maps[i];
	}
	maps.pop_back();
}
