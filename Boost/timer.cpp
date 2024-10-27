#include "debug.h"

#include <boost/date_time/gregorian/formatters.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/timer.hpp>
#include <cstdio>
#include <format>
#include <iostream>

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

    // Basic time
    printf(ANSI_FMT("Test time lib \n", ANSI_BLUE));
    boost::posix_time::time_duration td1{boost::posix_time::minutes(5) + boost::posix_time::seconds(3)};
    boost::posix_time::time_duration td2 = boost::posix_time::duration_from_string("1:10:30:1000");

    std::cout << std::format(
                     "Time duration {} and duration {}", boost::posix_time::to_simple_string(td1),
                     boost::posix_time::to_simple_string(td2)
                 )
              << std::endl;

    boost::posix_time::ptime time_point{boost::gregorian::date(2024, 05, 10), boost::posix_time::hours(5)};
    std::cout << std::format("Time point simple string: {} \n", boost::posix_time::to_simple_string(time_point));

    return 0;
}