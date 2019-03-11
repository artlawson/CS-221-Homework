// This program takes returns an estimate of what pi is
#include <cmath>
#include <iostream>

double gridpie(unsigned npoints)
	{
		double totalgrid = npoints * npoints;
		unsigned x = 0;
		unsigned y = 0;
		double total = 0;
		while (x <= npoints)
			{
				y=0;
				while (y <= npoints)
				{

					double z = std::hypot(x, y);
					if (z < npoints) 
					{
						total+=1;

					}
				y+=1;}
			x+=1;}

		double output = 4 * (total/totalgrid);
		return output;
	}
int main()
{
	std::cout<<gridpie(10) << std::endl;
	std::cout<<gridpie(100) << std::endl;
	std::cout<<gridpie(1000) << std::endl;
	std::cout<<gridpie(10000) << std::endl;

}

