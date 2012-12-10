#!/bin/bash
# Beacon simulator
# Tony.Lee-at-Foundstone.com
# Input: URL and frequency to beacon (in seconds)
# Output: Beaconing web requests to a URL at a user-defined interval
# Requirements - curl or wget

##### Function Usage #####
# Prints usage statement
##########################
Usage()
{
echo "This program will beacon out to a website on a user-defined schedule to simulate malware.  (Use ctrl+c to stop the beaconing)
Email Tony.Lee-at-Foundstone.com for questions.

Usage: $0 <URL> <Frequency in seconds>
Example: $0 http://www.dot.tk/en/index.html?lang=en 60"
}

###### Core Program ######
# Parameter Detection
# Beaconing
##########################

# Detect the absence of command line parameters. If the user did not specify two, print usage statement
[[ $# -ne 2 ]] && { Usage; exit 0; }

while true
do
        echo -e "Getting the site $1\n";                # user notification output
        wget -O /dev/null $1;                           # wget the URL (to avoid files from building up output to /dev/null)
echo -e "\n\nSleeping for $2 seconds\n\n";      # user notification output
        sleep $2;                                       # Sleep
done

