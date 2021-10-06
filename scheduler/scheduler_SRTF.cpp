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
#include "../includes/scheduler_SRTF.h"
#include <vector>
#include <algorithm>
//override base class behaviour if necessary, otherwise call it
bool  Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	if(ready_q->front().remaining_cpu_time<0 || ready_q->front().remaining_cpu_time<=p.remaining_cpu_time){
		return true;
	}
	if (p.remaining_cpu_time <= 0) {
		return true;
	}
	return false;
}
struct SRTF
{
    bool operator()( const PCB& lx, const PCB& rx ) const {
        return lx.remaining_cpu_time > rx.remaining_cpu_time;
    }
};
void Scheduler_SRTF::sort() {
	std::priority_queue<PCB, std::vector<PCB>, SRTF> sorted_queue;

	while(!ready_q->empty()){
		sorted_queue.push(ready_q->front());
		ready_q->pop();
	}
	while(!sorted_queue.empty()){
		ready_q->push(sorted_queue.top());
		sorted_queue.pop();
	}
//  PRIORITY QUEUE INSTEAD
//	std::vector<PCB> temp;
//	while(!ready_q->empty())
//	{
//		PCB next = ready_q->front();
//		ready_q->pop();
//		temp.push_back(next);
//	}
//	std::sort(temp.begin(),temp.end(), [](const PCB& lhs, const PCB& rhs)
//			{
//			    return lhs.remaining_cpu_time > rhs.remaining_cpu_time;
//			});
//	for(int i=0;i<temp.size();i++)
//	{
//		ready_q->push(temp.back());
//	}
}
