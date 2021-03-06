#ifndef clab2019gscans_hpp
#define clab2019gscans_hpp

#include <cinttypes>
#include <cstdio>
#include <istream>
#include <stdexcept>
#include <string>
#include <vector>

namespace clab2019gscans
{

	struct event
	{
		uint64_t realtime_us;
		uint32_t channel;
		event(const std::string& line)
		{
			std::sscanf(line.c_str(),"%" PRIu64 ",%" PRIu32,&realtime_us,&channel);
		}
	};

	struct batch
	{
		uint64_t livetime_us;
		std::vector<event> events;
	};

	struct metabatch
	{
		std::vector<batch> batches;
	};

	std::vector<metabatch> parse_from_stream( std::istream& i )
	{
		std::vector<metabatch> metabatches;

		for( std::string line; std::getline( i, line ); )
		{
			if( line.find("#") != 0 ) // We have an event data line.
			{
				metabatches.back().batches.back().events.emplace_back( event( line ) );
			}
			else if( line.find("Batch begin") != std::string::npos ) // A new batch follows.
			{
				metabatches.back().batches.emplace_back( batch() );
				metabatches.back().batches.back().livetime_us = std::stoull( line.substr(27) );
			}
			else if( line.find("meta-batch follows") != std::string::npos ) // A new meta batch follows.
			{
				metabatches.emplace_back( metabatch() );
			}
		}

		return metabatches;
	}

}

#endif
