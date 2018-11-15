#include <iostream>

#include "Process.h"
#include "Random.h"
#include "Threshold.h"
#include "State.h"

using namespace domotique;

int main()
{
	actor::phenomenon::Random p = actor::phenomenon::Random(0.00001, -10, 10);
	actor::phenomenon::Random& phen = p;
	actor::controller::Threshold c = actor::controller::Threshold(0.9, 5, phen);
	actor::controller::Threshold& cont = c;
	actor::State s = actor::State(phen, cont);
	actor::State& state = s;

	process::Process proc = process::Process(phen, state, cont);

	for(int i = 0; i < 100; i++)
	{
		proc.CalculateAll();
		std::cout << i << "\t"
				<< proc.Values()[process::ActorType::State] << "\t"
				<< proc.Values()[process::ActorType::Phenomenon] << "\t"
				<< proc.Values()[process::ActorType::Controller]
				<< std::endl;
	}

	return 0;
}
