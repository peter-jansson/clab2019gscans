#include <iostream>

#include "clab2019gscans.hpp"

// Parse standard input as one of the files in the data archive.
int main()
{
	std::ios_base::sync_with_stdio(false);

	const auto metabatches( clab2019gscans::parse_from_stream( std::cin ) );

	// Now do something with all this data... :-)

	return EXIT_SUCCESS;
}
