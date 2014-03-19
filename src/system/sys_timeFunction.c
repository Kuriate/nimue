#include <stdio.h>
#include <time.h>

char get_evTime(void) {
	time_T timer;
	timer=asctime(&timer);
	
	return *timer;
}

char get_locTime(void) {
	time_T timer;
	timer = time(NULL);
	timer = asctime(localtimer(&timer));
	
	return *timer;
}

char get_wDay(int year, int mon, int mday, int sec, int min, int hour, int dst) {

	struct tm time_day;
	char days[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}

	time_day.tm_year=year;
	time_day.tm_mon=mon;
	time_day.tm_mday=mday;
	time_day.tm_sec=sec;
	time_day.tm_min=min;
	time_day.tm_hour=hour;
	time_day.tm_isdst=dst;

  if(mktime(&time_day)==-1)
   {
    printf("Error getting time.\n");
    exit(0);
   }

  return days[time_day.tm_wday];
}

char set_formatTime(int op) {
   time_t rawtime;
   struct tm *info;
   char buffer[80];
   
   time( &rawtime );

   info = localtime( &rawtime );

   strftime(buffer,80,"%x - %I:%M%p", info);
   printf("Formatted date & time : |%s|\n", buffer );
  
   return *;
}