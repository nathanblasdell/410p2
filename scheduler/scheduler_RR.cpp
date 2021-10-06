/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_RR.h"
//override base class behaviour if necessary, otherwise call it
bool  Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	if((p.required_cpu_time-p.remaining_cpu_time) % time_slice ==0){
		return true;
	}
	if (p.remaining_cpu_time <= 0) {
		return true;
	}
	return false;
}
void Scheduler_RR::sort() {

}
