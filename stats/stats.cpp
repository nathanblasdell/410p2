/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/stats.h"
#include "../includes/PCB.h"
#include <iostream>
#include <vector>

Stats::Stats(std::vector<PCB> &finished_vector):vec(&finished_vector), av_wait_time(0), av_turnaround_time(0), av_response_time(0){

}
	//loops thru vec, prints 1 line for each process using the following format
	//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
	//if there are 10 processes in vector, should print 10 lines
PCB cur;
void Stats::showAllProcessInfo(){
	for (int i = 0; i < vec->size(); i++) {
		cur = vec->at(i);
		std::cout << "Process " << i << "Required CPU time:" << cur.required_cpu_time << " arrived:" << cur.arrival_time << " started:" << cur.start_time + " finished:" << cur.finish_time << std::endl;
	}
}

	//after a process is placed in the ready_q, how long does
	//it take before its placed on the processor?
	//response_time per process = start_time - arrival_time
	//this funtion returns the average over all processes
float Stats::get_av_response_time(){
	float total = 0;
	for (int i = 0; i < vec->size(); i++) {
		cur = vec->at(i);
		total += (cur.start_time - cur.arrival_time);
	}
	return (total / vec->size());
}

	//after a process is placed in the ready_q, how long does
	//it take to complete?
	//turnaround time per process = finish_time - arrival_time
	//this funtion returns the average over all processes
	float Stats::get_av_turnaround_time() {
		float total = 0;
		for (int i = 0; i < vec->size(); i++) {
			cur = vec->at(i);
			total += (cur.finish_time - cur.arrival_time);
		}
		return (total / vec->size());
	}

	//after a process is placed in the ready_q, how much time does it
	//spend waiting for processor time?
	//wait time per process = finish_time - arrival_time-required_CPU_time
	//this funtion returns the average over all processes
	float Stats::get_av_wait_time() {
		float total = 0;
		for (int i = 0; i < vec->size(); i++) {
			cur = vec->at(i);
			total += (cur.finish_time - cur.arrival_time - cur.required_cpu_time);
		}
		return (total / vec->size());
	}
