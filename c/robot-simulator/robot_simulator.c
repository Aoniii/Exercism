#include "robot_simulator.h"

static const robot_position_t move[] = {
	[DIRECTION_EAST] = {1, 0},
	[DIRECTION_WEST] = {-1, 0},
	[DIRECTION_NORTH] = {0, 1},
	[DIRECTION_SOUTH] = {0, -1},
};

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
	return ((robot_status_t){
		.direction = direction,
		.position = {x, y}
	});
}

void robot_move(robot_status_t *robot, const char *commands) {
	for (; *commands; commands++) {
		if (*commands == 'A') {
			robot->position.x += move[robot->direction].x;
			robot->position.y += move[robot->direction].y;
		} else if (*commands == 'R') {
			robot->direction++;
			if (robot->direction == DIRECTION_MAX)
				robot->direction = DIRECTION_NORTH;
		} else if (*commands == 'L') {
			if (robot->direction == DIRECTION_NORTH)
				robot->direction = DIRECTION_WEST;
			else
				robot->direction--;
		} else {
			return;
		}
	}
}
