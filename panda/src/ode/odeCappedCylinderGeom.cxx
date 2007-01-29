// Filename: odeCappedCylinderGeom.cxx
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
#include "odeCappedCylinderGeom.h"

TypeHandle OdeCappedCylinderGeom::_type_handle;

OdeCappedCylinderGeom::
OdeCappedCylinderGeom(dReal radius, dReal length) :
  OdeGeom(dCreateCapsule(0, radius, length)) {
}

OdeCappedCylinderGeom::
OdeCappedCylinderGeom(OdeSpace &space, dReal radius, dReal length) :
  OdeGeom(dCreateCapsule(space.get_id(), radius, length)) {
}

OdeCappedCylinderGeom::
~OdeCappedCylinderGeom() {
}
