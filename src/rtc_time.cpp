#include <rtc_time.h>

// ----------------------------------------------------------------------------
// Time Server and related setup
//
// %a Abbreviated weekday name
// %A Full weekday name
// %b Abbreviated month name
// %B Full month name
// %c Date and time representation for your locale
// %d Day of month as a decimal number (01-31)
// %H Hour in 24-hour format (00-23)
// %I Hour in 12-hour format (01-12)
// %j Day of year as decimal number (001-366)
// %m Month as decimal number (01-12)
// %M Minute as decimal number (00-59)
// %p Current locale’s A.M./P.M. indicator for 12-hour clock
// %S Second as decimal number (00-59)
// %U Week of year as decimal number,  Sunday as first day of week (00-51)
// %w Weekday as decimal number (0-6; Sunday is 0)
// %W Week of year as decimal number, Monday as first day of week (00-51)
// %x Date representation for current locale
// %X Time representation for current locale
// %y Year without century, as decimal number (00-99)
// %Y Year with century, as decimal number
// %z %Z Time-zone name or abbreviation, (no characters if time zone is unknown)
// %% Percent sign
//
// You can include text literals (such as spaces and colons) to make a neater display or for padding between adjoining columns.
// You can suppress the display of leading zeroes  by using the "#" character  (%#d, %#H, %#I, %#j, %#m, %#M, %#S, %#U, %#w, %#W, %#y, %#Y)
// ----------------------------------------------------------------------------

const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 10 * 60 * 60;
const int daylightOffset_sec = 0;

void initTime()
{
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

struct tm timeinfo;

tm *getTime()
{
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
  }
  Serial.println(&timeinfo, "%H");
  return &timeinfo;
}

void displayTimeStamp()
{
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }
}
