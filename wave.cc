#include "wave.h"

Wave::Wave () {

}

Wave::Wave (vector<EnemyUnit> enemies) {
	this->enemies = enemies;
}

EnemyUnit Wave::releaseEnemy() {
	EnemyUnit enemy = enemies[0];
	for (int unsigned i = 1; i < enemies.size(); i++) {
		enemies[i-1] = enemies[i];
	}
	enemies.pop_back();
	return enemy;
}

vector<EnemyUnit> Wave::getWave() {
	return enemies;
}

void Wave::setWave(vector<EnemyUnit> enemies) {
	this->enemies = enemies;
}




