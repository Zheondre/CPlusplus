//  Copyright 2015 Zheondre Calcano
#include <boost/regex.hpp>
#include <boost/date_time.hpp>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Services.hpp"

using namespace std; //NOLINT
using namespace boost; //NOLINT

void services::makeLsNull() {
  l1 = l2 = l3 = l4 = l5 = "";
}
string services::getL1() {
  return l1;
}
string services::getL2() {
  return l2;
}
string services::getL3() {
  return l3;
}
string services::getL4() {
  return l4;
}
string services::getL5() {
  return l5;
}
regex services::getRS() { return rs; }
string services::AFail() { return allfs; }
string services::getsr(int x) {
  if (x < 0)
    throw std::invalid_argument("Value is less than 0");
  if (x > sofV)
    throw std::invalid_argument("Value is greater than vector size");
  return sname[x];
}
string services::getfSM() { return fSM ; }
string services::getSta() { return startservice; }
string services::getGS() { return GoodStart; }
string services::getCompleteLN(int x) { return CompleteLN[x]; }
string services::getStartLN(int x) { return StartLN[x]; }
string services::getElapsedT(int x) { return ElapsedT[x]; }
int services::sz() { return sofV; }
void services::setNegvalues() {
  for (int i = 0; i < sofV; i++) {
    StartLN[i] = "-1";
    CompleteLN[i]= "-1";
    ElapsedT[i] = "-1";
  }
}
void services::ServiceStart(string line, int linenum) {
  int i;
  std::ostringstream so;
  for (i = 0; i < sofV; i++) {
    regex e(getSta() + getsr(i) + ".*");
    if (regex_match(line, e)) {  // Start service found
      so.str("");
      so << linenum;
      StartLN[i] = so.str();
    }
  }
}
void services::ServiceSuccess(string line, int linenum) {
  int i; smatch sm; std::ostringstream so;
  for (i = 0; i < sofV; i++) {
    regex e(getGS() + getsr(i) + ".*");
    if (regex_match(line, e)) {  // Success service found
      regex dig(rs);
      if (regex_search(line, sm, dig)) {
        so.str("");
        so << linenum;
        ElapsedT[i] = boost::lexical_cast<string>(sm[1]);
        CompleteLN[i] = so.str();
      }
    }
  }
}
void services::findOV(string line) {
  smatch sm; std::ostringstream so; string ltp;
  regex e(".*intouch-application-base-.*");
  if (regex_match(line, e)) {
    regex rge(".*: removing.*");
    if (regex_match(line, rge)) {
      regex dig("(?=-[0-9])(.*?)(?=\\.armv)");
      if (regex_search(line, sm, dig)) {
        ltp = boost::lexical_cast<string>(sm[0]);
        ltp.erase(0, 1);
        l2 = "\tOriginal version ==> " + ltp + "\n";
      }
    }
  }
}
void services::findNV(string line) {
  smatch sm; std::ostringstream so; string ltp;
  regex e(".*intouch-application-base-.*");
  if (regex_match(line, e)) {
    regex rge(".*: Processing.*");
    if (regex_match(line, rge)) {
      regex dig("(?=-[0-9])(.*?)(?=\\.armv)");
      if (regex_search(line, sm, dig)) {
        ltp = boost::lexical_cast<string>(sm[0]);
        ltp.erase(0, 1);
        l3 = "\tNew version ==> "+ltp +"\n";
      }
    }
  }
}
bool services::SoftloadS(string line, int ln, string fn) {
  smatch sm; std::ostringstream so; string ltp;
  regex e(startSoftload);
  if (regex_match(line, e)) {
    regex rge("(\\s*\\w{3}\\s*[0-9]{1,2})");
    regex rgd("([0-9]{2}):([0-9]{2}):([0-9]{2})");
    if (regex_search(line, sm, rge)) {
      so.str("");
      so << ln;
      ltp = "=== Softload ===\n";
      ltp += so.str() + "(" + fn + ") : " + boost::lexical_cast<string>(sm[0]);
      ltp += " ";
    }
    if (regex_search(line, sm, rgd)) {
      ltp += boost::lexical_cast<string>(sm[0]) + " Softload Start\n";
      start[0] = boost::lexical_cast<int>(sm[1]);
      start[1] = boost::lexical_cast<int>(sm[2]);
      start[2] = boost::lexical_cast<int>(sm[3]);
      l1 = ltp;
      return true;
    }
  }
  return false;
}
int services::SoftloadEnd(string line, int ln, string fn) {
  // if valid line drab date
  smatch sm; std::ostringstream so; string ltp;
  regex e(EndSoftload);
  if (regex_match(line, e)) {
    regex rge("(\\s*\\w{3}\\s*[0-9]{1,2})");
    regex rgd("([0-9]{2}):([0-9]{2}):([0-9]{2})");
    if (regex_search(line, sm, rge)) {
      so.str("");
      so << ln;
      ltp = so.str() + "(" + fn + ") : " + boost::lexical_cast<string>(sm[0]);
      ltp += " ";
    }
    if (regex_search(line, sm, rgd)) {
      ltp += boost::lexical_cast<string>(sm[0]) + " Softload Completed\n";
      end[0] = boost::lexical_cast<int>(sm[1]);
      end[1] = boost::lexical_cast<int>(sm[2]);
      end[2] = boost::lexical_cast<int>(sm[3]);
      l5 = ltp;
      GetEtime();
    }
  }
  return 1;
}
void services::GetEtime() {
  string temp;
  std::ostringstream so;
  boost::posix_time::time_duration st(start[0], start[1], start[2]);
  boost::posix_time::time_duration et(end[0], end[1], end[2]);
  et = et - st;
  so.str("");
  so << et.total_seconds();
  temp = "\tElapsed time (sec) ==> " + so.str() + "\n";
  l4 = temp;
}
string services::Sformat(string ufn) {
  string temp = "";
    for (int i = 0; i < sofV; i++) {
      if (getCompleteLN(i) != "-1") {
        temp +=  "\t" + getsr(i) + "\n\t\tStart: "
        + getStartLN(i) + "(" + ufn + ")\n";
        temp += "\t\tCompleted: " + getCompleteLN(i) + "(" + ufn + ")\n";
        temp += "\t\tElapsed Time: " + getElapsedT(i) + "\n";
      } else {
        if (getStartLN(i) == "-1") {
          temp += "\t" + getsr(i) + "\n\t\tStart: "
          + "Not started(" + ufn + ")\n";
          temp += "\t\tCompleted: Not completed("
          + ufn +")\n\t\tElapsed Time:\n";
        } else {
          temp += "\t" + getsr(i) + "\n\t\tStart: "
          + getStartLN(i) +"(" + ufn + ")\n";
          temp += "\t\tCompleted: Not completed("
          + ufn +")\n\t\tElapsed Time:\n";
        }
      }
    }
    return temp;
}
string services::LFS() {
  string temp, t2;
  temp = t2 = "";
  int ngvalf = 0;
  for (int i = 0; i < sofV; i++) {
    if (getCompleteLN(i) == "-1") {
      if (ngvalf== 0) {
        t2 += fSM;
        temp += getsr(i);
        ngvalf++;
        continue;
      }
      if (ngvalf == 1) {
        temp +=", "+ getsr(i);
      }
    }
  }
  t2 += temp;
  return t2;
}
