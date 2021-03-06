/* -*- c++ -*- ----------------------------------------------------------
 *
 *                    ***       Karamelo       ***
 *               Parallel Material Point Method Simulator
 * 
 * Copyright (2019) Alban de Vaucorbeil, alban.devaucorbeil@monash.edu
 * Materials Science and Engineering, Monash University
 * Clayton VIC 3800, Australia

 * This software is distributed under the GNU General Public License.
 *
 * ----------------------------------------------------------------------- */

#ifndef MPM_UPDATE_H
#define MPM_UPDATE_H

#include "pointers.h"
#include <vector>
/*! Stores everything related to time steps as well as the Scheme and Method classes.
 */
class Update : protected Pointers {
 public:
  double run_duration;                ///< Stop simulation if elapsed simulation time exceeds this.
  double elapsed_time_in_run;	      ///< Elapsed simulation time for a single run;
  double dt;                          ///< Timestep
  double dt_factor;                   ///< Timestep factor
  bool dt_constant;                   ///< is dt constant?
  bigint ntimestep;                   ///< current step
  int nsteps;                         ///< Number of steps to run
  double atime;                       ///< Simulation time at atime_step
  double maxtime;                     ///< Maximum simulation time (infinite if -1)
  bigint atimestep;                   ///< Last timestep atime was updated
  bigint firststep,laststep;          ///< 1st & last step of this run
  bigint beginstep,endstep;           ///< 1st and last step of multiple runs
  int first_update;                   ///< 0 before initial update, 1 after

  class Scheme *scheme;               ///< Pointer to the type of Scheme used
  string scheme_style;                ///< Name of the scheme style

  class Method *method;               ///< Pointer to the type of Method used
  string method_type;                 ///< Name of the method type
  string method_shape_function;       ///< Type of shape function used

  Update(class MPM *);
  ~Update();
  void set_dt_factor(vector<string>); ///< Sets the factor to be applied to the CFL timestep
  void set_dt(vector<string>);        ///< Sets the timestep
  void create_scheme(vector<string>); ///< Creates a scheme: USL, or MUSL.
  void create_method(vector<string>); ///< Creates a method: tlmpm, ulmpm, tlcpdi, ...
  void update_time();                 ///< Update elapsed time
  int update_timestep();              ///< Update timestep
protected:
  
};


#endif
