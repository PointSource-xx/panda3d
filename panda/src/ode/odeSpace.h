// Filename: odeSpace.h
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

#ifndef ODESPACE_H
#define ODESPACE_H

#include "pandabase.h"
#include "typedObject.h"
#include "luse.h"

#include "ode/ode.h"

class OdeGeom;
class OdeTriMeshGeom;

////////////////////////////////////////////////////////////////////
//       Class : OdeSpace
// Description : 
////////////////////////////////////////////////////////////////////
class EXPCL_PANDAODE OdeSpace : public TypedObject {
  friend class OdeGeom;

protected:
  OdeSpace(dSpaceID id);
  
PUBLISHED:
  virtual ~OdeSpace();
  void destroy();

  INLINE void set_cleanup(int mode);
  INLINE int get_cleanup() const;
  INLINE int query(const OdeGeom& geom) const;
  INLINE int query(const OdeSpace& space) const;
  INLINE int get_num_geoms() const;
  // INLINE void get_aabb() const;  
  INLINE int is_space();
  INLINE int get_class() const;
  INLINE void set_category_bits(unsigned long bits);
  INLINE void set_collide_bits(unsigned long bits);
  INLINE void enable();
  INLINE void disable();
  INLINE int is_enabled();

  void add(OdeGeom& geom);
  void add(OdeSpace& space);
  void remove(OdeGeom& geom);
  void remove(OdeSpace& space);
  void clean();
  void get_geom(int i, OdeGeom &geom);

  INLINE OdeSpace get_space() const;

  virtual void write(ostream &out = cout, unsigned int indent=0) const;

public: 
  INLINE dSpaceID get_id() const;

protected:
  dSpaceID _id;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    TypedObject::init_type();
    register_type(_type_handle, "OdeSpace",
		  TypedObject::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "odeSpace.I"

#endif

