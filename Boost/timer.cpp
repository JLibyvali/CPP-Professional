#include "debug.h"

#include <boost/date_time/gregorian/formatters.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/gregorian/greg_duration.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/gregorian/parsers.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/special_defs.hpp>
#include <boost/timer.hpp>
#include <cstdio>
#include <iostream>
#include <semaphore>

int main()
{

    // Basic timer
    boost::timer tm;

    printf(ANSI_FMT("Test boost timer\n", ANSI_BLUE));
    printf("Max time span: %f hours\n", tm.elapsed_max() / 3600);
    printf("Min span: %f hours\n", tm.elapsed_max() / 3600);
    printf("now time elapsed: %f secs \n", tm.elapsed());

    
    // basic date
    printf(ANSI_FMT("Test boost date \n", ANSI_BLUE));
    boost::gregorian::date dt  = boost::gregorian::from_simple_string("2024-10-26");
    boost::gregorian::date dt2 = boost::gregorian::date_from_iso_string("20241126");

    std::cout << "Infinity date " << boost::gregorian::date{boost::date_time::pos_infin} << "\tYear: " << dt.year()
              << "\nMonth: " << dt.month() << "\nDays: " << dt.day() << std::endl;
    std::cout << "Date string: " << boost::gregorian::to_simple_string(dt)
              << "\nDate numeric: " << boost::gregorian::to_iso_extended_string(dt) << std::endl;

    boost::gregorian::date_duration duration{(dt2 - dt)};
    std::cout << "Durations Days:  " << duration.days() << " days" << std::endl;

    boost::gregorian::date_period dp{dt, boost::gregorian::days(22)};
    std::cout << "Date period length: " << dp.length() << " Last dat: " << dp.last() << std::endl;


    //Basic time
         

    return 0;
}