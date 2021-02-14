#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <utility>

#include "clab2019gscans.hpp"

// Parse standard input as one of the files in the data archive and build
// a 2D (real time, energy) spectrum of all counts with 1 s time resolution.
// Print the spectrum as a 2D array in JSON format [[time,energy,count],...]
// on standard output. Does not print zero counts.
int main()
{
	using namespace std;

	ios_base::sync_with_stdio(false);

	uint32_t max_realtime(0U), max_channel(0U);

	// (real time, channel) => count
	map< pair<uint32_t,uint32_t>, uint64_t > spectrum;

	// Parse standard input and add all events to the spectrum.
	for( auto&& mBatch : clab2019gscans::parse_from_stream( cin ) )
	{
		for( auto&& b : mBatch.batches )
		{
			for( auto&& evt : b.events )
			{
				uint32_t rt(llround(evt.realtime_us*1.0E-6));
				spectrum[ {rt,evt.channel} ]++;
				max_realtime = max( rt, max_realtime );
				max_channel = max(evt.channel,max_channel);
			}
		}
	}

	// Print the spectrum as a JSON array of arrays.
	cout << '[';
	bool have_printed_first(false);
	for( const auto& [key, value] : spectrum )
	{
		if( have_printed_first )
		{
			cout << ',';
		}
		cout << '[' << key.first << ',' << key.second
			<< ',' << value << ']';
		have_printed_first = true;
	}
	cout << ']';

	return EXIT_SUCCESS;
}
