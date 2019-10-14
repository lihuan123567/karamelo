/* -*- c++ -*- ----------------------------------------------------------*/

#ifndef MPM_OUTPUT_H
#define MPM_OUTPUT_H

#include "pointers.h"
#include <vector>

class Output : protected Pointers {
public:
  bigint next;                 // next timestep for any kind of output

  
  bigint next_log;             // next timestep for log output
  int every_log;               // freq for log output
  class Log *log;

  bigint next_dump_any;        // next timestep for any Dump
  vector<int> every_dump;      // write freq for each Dump, 0 if var
  vector<bigint> next_dump;    // next timestep to do each Dump
  vector<bigint> last_dump;    // last timestep each snapshot was output
  int ndumps;                  // number of defined Dumps, should always be equal to dumps.size()
  vector<class Dump *> dumps;  // list of defined Dumps

  bigint next_plot_any;        // next timestep for any Plot
  vector<int> every_plot;      // write freq for each Plot, 0 if var
  vector<bigint> next_plot;    // next timestep for plot output
  vector<bigint> last_plot;    // last timestep each snapshot was output
  int nplots;                  // number of defined Plots, should always be equal to plots.size()
  vector<class Plot *> plots;  // list of defined Plots
  bool save_plot;              // true to save plot in file
  string ofile_plot;           // filename to save the plot to

  Output(class MPM *);
  ~Output();

  void setup();
  void write(bigint);                  // output for current timestep
  void show_plot();                    // show plot

  void set_log(vector<string>);        // set log output frequency

  void add_dump(vector<string>);       // add a Dump to Dump list
  int find_dump(string);               // find a Dump in Dump list
  void modify_dump(vector<string>);    // modify a Dump
  void delete_dump(string);            // delete a Dump from Dump list

  void add_plot(vector<string>);       // add a Plot to Plot list
  int find_plot(string);               // find a Plot in Plot list
  void modify_plot(vector<string>);    // modify a Plot
  void delete_plot(string);            // delete a Plot from Plot list
};

#endif
