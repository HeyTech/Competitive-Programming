#ifndef DAY3_H
#define DAY3_H

#include <vector>
#include <string>
#include <iostream>

struct Ele_info{
  char direction = 0;
  int32_t distance = 0;
};

struct Point{
  int32_t x = 0;
  int32_t y = 0;
  int32_t distance = 0;

  friend std::ostream & operator << ( std::ostream &os, const Point &po){
    os << "x: " << po.x << " y: " << po.y;
    return os;
  }
};

struct Line {
  Line(Point p0_, Point p1_): p0{p0_}, p1{p1_} {}
  Point p0;
  Point p1;

  friend std::ostream & operator << ( std::ostream &os, const Line &line){
    os << "P0 : " << line.p0 << " P1 : " << line.p1;
    return os;
  }
};



class day3{
public:
  day3();
  void task1_and_2();
  void find_junctions();
  void check_junctions(Line l1, Line l2);
  void update_manhatan_distance_junction(int32_t& junc_x, int32_t& junc_y);
  void update_fewest_combined_steps(int32_t& junc_x, int32_t& junc_y, bool vertical_junction, Line l1, Line l2);

private:
  std::vector<std::string> wire1;
  std::vector<std::string> wire2;

  std::vector<Line> wire1_lines;
  std::vector<Line> wire2_lines;

  std::uint32_t fewest_combined_steps = 999999999;
  std::uint32_t manhatan_distance_junction = 999999999;
};

#endif // DAY3_H
