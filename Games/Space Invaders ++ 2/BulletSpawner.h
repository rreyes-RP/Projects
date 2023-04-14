#include <SFML/Graphics.hpp>

class BulletSpawner {
public:
	virtual void spawnBullet(Vector2f spawnLocation, bool forPlayer) = 0;
};