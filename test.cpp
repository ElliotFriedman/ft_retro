#include <iostream>  
#include <chrono>     
#include <iostream> 
#include <chrono> 
#include <ctime> 

int main() 
{ 
	std::chrono::time_point<std::chrono::system_clock> start, end; 

	start = std::chrono::system_clock::now(); 
	end = std::chrono::system_clock::now(); 

	std::chrono::duration<double> elapsed_seconds;

	start = std::chrono::system_clock::now();	
	elapsed_seconds = end - start;
	int i = 0;
	while ( i < 48 )
	{
		end = std::chrono::system_clock::now();
		start = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		//this tells us how long till we refresh frames
		while (elapsed_seconds.count() < 0.0207f)
		{
			elapsed_seconds = end - start;
			end = std::chrono::system_clock::now();
		}
		i++;
		std::cout << std::to_string(i) + "\n";
	}

	return 0;
}
