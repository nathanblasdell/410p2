/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content
#include <queue>
#include "../includes/scheduler_SRTF.h"
//override base class behaviour if necessary, otherwise call it
bool  Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	if (preemptive) {
		if (time_slice == tick_count) {
			return true;
		}
	}
	else if (p.remaining_cpu_time == 0) {
		return true;
	}
	return false;
}
void Scheduler_SRTF::sort() {

}
