#include <cstdio>
#include <iostream>

#define WWRITER 0

#if WWRITER
int main() {
	std::cout << "hello1!";
    while (true) {
        std::cout << "Latitude:13.3 Longitude:80.25";
    }
    return 0;
}
#else
int main() {
	std::cout << "hello2!";
    FILE* fp = popen("Debug/Writer", "r");
    if(fp == 0)  perror(0);
    else {
        const std::size_t LatitudeLength = 9;
        const std::size_t LongitudeLength = 10;
        char latitude_name[LatitudeLength+1];
        char longitude_name[LongitudeLength+1];
        double latitude;
        double longitude;
        while(fscanf(fp, "%9s%lf%10s%lf",
            latitude_name,
            &latitude,
            longitude_name,
            &longitude)  == 4)
        {
            std::cout << "Values: " << latitude << ", " << longitude << std::endl;
        }
        pclose(fp);
    }
    return 0;
}
#endif
