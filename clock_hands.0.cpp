/*

A standard circular wall clock has three hands (hours, minutes, seconds).
When do all three hands line up? Write a program to answer this question.
Your program should print the times of day (hh:mm:ss) when the 3 hands line up.

Assumptions:
    1. There are 60 evenly spaced ticks on the clock face.
    2. On each second:
        - The second hand rotates by one tick
        - The minute hand rotates by a fraction of a tick
        - The hour hand rotates by an even smaller fraction of tick
    3. Hands moves discretely and instantaneously.
       For example, the second hand will never be between two ticks.
    4. Hands are "lined up" when they are all within a full tick of each other.

 */

#include <iostream>
#include <math.h>       /* remainder */

using namespace std;
bool is_within_half(double sec_ang, double min_ang, double hrs_ang);

// To execute C++, please define "int main()"
int main() {
  const double sec_per_rev = 60.0;
  const double min_per_rev = 3600.0;
  const double hrs_per_rev = 43200.0;

  std::cout << fmod(5.2, 3.0) << std::endl; // 2.2
  std::cout << 5.2/3.0 << std::endl; // ??

  for (double i_sec=0.0; i_sec<(hrs_per_rev*2.0); ++i_sec) {
    double sec_rev = fmod(i_sec / sec_per_rev, sec_per_rev);
    double min_rev = fmod(i_sec, min_per_rev);
    double hrs_rev = fmod(i_sec, hrs_per_rev);
    if (is_within_half(sec_rev, min_rev, hrs_rev)) {
      std::cout << i_sec/hrs_per_rev << ":" << i_sec/min_per_rev << ":" << i_sec/sec_per_rev << std::endl;
    }
  }

  return 0;
}

bool is_within_half(double sec_ang, double min_ang, double hrs_ang)
{
  const double half_ticks = 1.0/120.0;
  bool sec_min = std::abs(sec_ang - min_ang) <= half_ticks;
  bool sec_hrs = std::abs(sec_ang - hrs_ang) <= half_ticks;
  bool min_hrs = std::abs(min_ang - hrs_ang) <= half_ticks;
  return sec_min && sec_hrs && min_hrs;
}


/*

A standard circular wall clock has three hands (hours, minutes, seconds).
When do all three hands line up? Write a program to answer this question.
Your program should print the times of day (hh:mm:ss) when the 3 hands line up.

Assumptions:
    1. There are 60 evenly spaced ticks on the clock face.
    2. On each second:
        - The second hand rotates by one tick
        - The minute hand rotates by a fraction of a tick
        - The hour hand rotates by an even smaller fraction of tick
    3. Hands moves discretely and instantaneously.
       For example, the second hand will never be between two ticks.
    4. Hands are "lined up" when they are all within a half tick of each other.

 */

/*
**** print times hh::mm::ss when hands line up
- seconds hand = 60 discrete ticks
- minutes hand = 3600 ticks
- hours hand = 12 * 3600 ticks = 7200 + 36000 = 43200 ticks

- first place == midnight = 0 seconds, 0 minutes, 0 hours
    - 61/60 , 61/3600, 61/43200
*/
