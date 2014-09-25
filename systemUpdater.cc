#include "systemUpdater.h"
#include "drawConstants.h"
#include <iostream>

SystemUpdater::SystemUpdater() {
	map = new Map ();
	player = new Player();
	inUpdate = false;
}

SystemUpdater::SystemUpdater(Map* map, Player* player, AttributeBox* playerStats) {
	this->map = map;
	this->player = player;
	this->playerStats = playerStats;
	inUpdate = false;
}

void SystemUpdater::removeEnemy(int position) {
	for (int unsigned i = position + 1; i < enemies.size(); i++) {
		enemies [i-1] = enemies[i];
	}
	enemies.pop_back();
}

bool SystemUpdater::isUpdating() {
	return inUpdate;
}

void SystemUpdater::update() {

	inUpdate = true;

	vector<Wave> allWaves = map->getWaves();
	if (allWaves.size() != 0) {
		Wave nextWave = allWaves[0];
		vector<vector<Square*> > locations = map->getPositions();
		vector<Point> path = map->getPathSquares();
		int pathLength = path.size();

		Square* startingSquare (locations[path[0].get_y()][path[0].get_x()]);

		vector<Tower> towers = player->getTowers();

		while ((nextWave.getWave().size()) != 0 || (enemies.size() != 0)) {

			for (int unsigned i = 0; i < enemies.size(); i++) {
				int position = enemies[i].getDistanceTraveled();
				int newPosition = position + 1;

				if (newPosition >= pathLength) {
					Square setUnoccupied = enemies[i].getSquare();
					locations[setUnoccupied.get_location().get_y() - MAP_OFFSET][setUnoccupied.get_location().get_x()]->set_occupied(false);
					setUnoccupied.draw(setUnoccupied.get_location(), SQUARE_SIZE * 0.8);

					removeEnemy(i);
					player->takeDamage();
					playerStats->updateQuantities();

					i--;
				} else {

					Square* newPlacement = locations[path[position].get_y()][path[position].get_x()];
					Square oldPlacement = enemies[i].getSquare();
					enemies[i].move(*newPlacement);
					locations[path[position].get_y()][path[position].get_x()]->set_occupied(true);
					locations[oldPlacement.get_location().get_y() - MAP_OFFSET][oldPlacement.get_location().get_x()]->set_occupied(false);

					oldPlacement.draw(oldPlacement.get_location(), SQUARE_SIZE * 0.8);
				}
			}

			if (player->getHealth() <= 0) {
				break;
			}

			if (nextWave.getWave().size() != 0) {
				EnemyUnit nextEnemy = nextWave.releaseEnemy();
				nextEnemy.move(*startingSquare);
				enemies.push_back(nextEnemy);
			}

			for (int unsigned i = 0; i < enemies.size(); i++) {
				for (int unsigned j = 0; j < towers.size(); j++) {
					if ((towers[j].getCanAttack()) && (towers[j].getDelayCount() >= towers[j].getAttackDelay()) && (!enemies[i].isDead()) && (towers[j].inRange(enemies[i].getSquare()))) {
						enemies[i].takeDamage(towers[j]);
						towers[j].setCanAttack(false);
						towers[j].setDelayCount(0);
					}
				}
			}

			for (int unsigned j = 0; j < towers.size(); j++) {
				towers[j].setCanAttack(true);
				towers[j].countDelay();
			}

			int unsigned i = 0;
			while (i < enemies.size()) {
				if (enemies[i].isDead()) {
					Square setUnoccupied = enemies[i].getSquare();
					locations[setUnoccupied.get_location().get_y() - MAP_OFFSET][setUnoccupied.get_location().get_x()]->set_occupied(false);
					setUnoccupied.draw(setUnoccupied.get_location(), SQUARE_SIZE * 0.8);

					removeEnemy(i);
					int goldReward = enemies[i].getGoldReward();
					player->addGold(goldReward);
					player->addScore(enemies[i].getScoreReward());
					playerStats->updateQuantities();

				} else {
					i++;
				}
			}


			usleep(62500);
		}

		map->removeWave();
	}
	inUpdate = false;
}
