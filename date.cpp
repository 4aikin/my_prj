#include <string>
#include <iomanip>
#include <cstdlib>
#include "date.h"
#include "algorithm.h"#include "algorithm.h"#include "algorithm.h"


using namespace std;

Date ParseDate (istream& is) {
    char var;
    int year = 0, month = 0, day = 0;
    is >> year >> var >> month >> var >> day;
    return Date(year, month, day);
    }

ostream& operator << (ostream& os, const Date& date) {
    os << setfill('0') << setw(4) << date.year << "-"  << setw(2) << date.month << "-"
        << setw(2) << date.day;
     return os;
}

ostream& operator << (ostream& os, pair<Date, string> pr) {
    os << setfill('0') << setw(4) << pr.first.year << "-" << setw(2) << pr.first.month << "-"
        << setw(2) << pr.first.day << " " << pr.second;
    return os;
}

bool operator < (const Date& date1, const Date& date2) {
	if (date1.year < date2.year) {
		return true;
    }
    else if (date1.year > date2.year) {
        return false;
    }
	if (date1.month < date2.month) {
			return true;
    }
    else if (date1.month > date2.month) {
        return false;
    }
	if (date1.day < date2.day) {
			return true;
    }
    else {
        return false;
    }
}

bool operator > (const Date& date1, const Date& date2) {
    if (date1.year > date2.year) {
        return true;
    }
    else if (date1.year < date2.year) {
        return false;
    }
    if (date1.month > date2.month) {
        return true;
    }
    else if (date1.month < date2.month) {
        return false;
    }
    if (date1.day > date2.day) {
        return true;
    }
    else {
        return false;
    }
}

bool operator == (const Date& date1, const Date& date2) {
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
        return true;
    }
    return false;
}

bool operator != (const Date& date1, const Date& date2) {
    if (date1.year != date2.year || date1.month != date2.month || date1.day != date2.day) {
        return true;
    }
    return false;
}

bool operator <= (const Date& date1, const Date& date2) {
    if (date1 < date2 || date1 == date2) {
        return true;
    }
    return false;
}

bool operator >= (const Date& date1, const Date& date2) {
    if (date1 > date2 || date1 == date2) {
        return true;
    }
    return false;
}

bool operator != (const pair<Date, string>& pr1, const pair<Date, string>& pr2) {
    if (pr1.first.year != pr2.first.year || pr1.first.month != pr2.first.month || pr1.first.day != pr2.first.day
        || pr1.second != pr2.second) {
        return true;
    }
    return false;
}