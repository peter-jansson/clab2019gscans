#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>

#include "clab2019gscans.hpp"

// Parse standard input as one of the files in the data archive and build
// an energy spectrum of all counts.
// Print the spectrum as an array in JSON format on standard output.
int main()
{
	std::ios_base::sync_with_stdio(false);

	// channel => count
	std::map< uint32_t, uint64_t > spectrum;

	// Parse standard input and add all events to the spectrum.
	for( auto&& mBatch : clab2019gscans::parse_from_stream( std::cin ) )
	{
		for( auto&& b : mBatch.batches )
		{
			for( auto&& evt : b.events )
			{
				spectrum[ evt.channel ]++;
			}
		}
	}

	// Print the spectrum as a JSON array of counts.
	std::cout << '[';
	for( auto maxCh(spectrum.rbegin()->first), ch(0U); ch <= maxCh ; ++ch )
	{
		if( 0 != ch ) std::cout << ',';
		std::cout << spectrum[ch]; // 0 in case ch is non-existent
	}
	std::cout << ']';

	return EXIT_SUCCESS;
}
