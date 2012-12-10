// Simple Beacon Simulator
// Input: URL and frequency to beacon (in seconds)
// Output: Beaconing web requests to a URL at a user-defined interval
// Requirements - curl or wget
// For questions ask Tony.Lee-at-Foundstone.com

#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;


int main(int argc, char *argv[])
{
        printf("This program will beacon out to a website on a user-defined schedule to simulate malware.  (Use ctrl+c to stop the beaconing)\n");
        printf("Email Tony.Lee-at-Foundstone.com for questions.\n\n");

        if ( argc != 3 )        // Detect command line arguments - 2 are needed for correct execution
        {
                printf( "Usage: %s <URL> <Frequency in seconds>\n", argv[0] );
                printf( "Example: %s http://www.dot.tk/en/index.html?lang=en 60\n", argv[0] );
                return 1;
        }

        unsigned int seconds = strtoul(argv[2],NULL,0); // sleep takes an unsigned int, must convert string input to unsigned long

        std::string command;                    // initialize command
        command = "wget -O /dev/null ";         // build the first part of the string
        command += argv[1];                     // add the URL

        const char * charcommand = command.c_str();     // convert string to char*

        while(1)
        {
                printf("\nGetting the site %s\n", argv[1]);             // user notification output
                system( charcommand );                                  // execute wget 
                printf("\n\nSleeping for %u seconds\n\n", seconds);     // user notification output
                sleep(seconds);                                         // sleep
        }

        return 0;
}

