// Filename: odeMass.cxx
// Created by:  joswilso (27Dec06)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001 - 2004, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://etc.cmu.edu/panda3d/docs/license/ .
//
// To contact the maintainers of this program write to
// panda3d-general@lists.sourceforge.net .
//
////////////////////////////////////////////////////////////////////

#include "config_ode.h"
#include "odeMass.h"

TypeHandle OdeMass::_type_handle;

OdeMass::
OdeMass() : 
  _mass() {
}

OdeMass::
OdeMass(const OdeMass &copy) : 
  _mass() {
  _mass.setParameters(copy._mass.mass, 
		      copy._mass.c[0], copy._mass.c[1], copy._mass.c[2],
		      copy._mass.I[0], copy._mass.I[5], copy._mass.I[10],
		      copy._mass.I[1], copy._mass.I[2], copy._mass.I[4]);
}

OdeMass::
~OdeMass() {
}

dMass* OdeMass::
get_mass_ptr() {
  return &_mass;
}

void OdeMass::
operator = (const OdeMass &copy) {
  _mass.setParameters(copy._mass.mass, 
		      copy._mass.c[0], copy._mass.c[1], copy._mass.c[2],
		      copy._mass.I[0], copy._mass.I[5], copy._mass.I[10],
		      copy._mass.I[1], copy._mass.I[2], copy._mass.I[4]);
		      
}


void OdeMass::
write(ostream &out, unsigned int indent) const {
  #ifndef NDEBUG //[
  out.width(indent); 
  out << get_type() \
      << "(mag = " << get_magnitude() \
      << ", center = " << get_center() \
      << ", inertia = " << get_inertia() \
      << ")";
  #endif //] NDEBUG
}
