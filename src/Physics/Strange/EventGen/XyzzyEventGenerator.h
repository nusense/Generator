//____________________________________________________________________________
/*!

\class    genie::XyzzyEventGenerator

\brief    Generates values for the kinematic variables describing Xyzzy neutrino
          interaction events.
          Is a concrete implementation of the EventRecordVisitorI interface.

\author   rhatcher@fnal.gov

\created  2020-02-19

\cpright  Copyright (c) 2003-2020, The GENIE Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
*/
//____________________________________________________________________________

#ifndef _XYZZY_EVENT_GENERATOR_H_
#define _XYZZY_EVENT_GENERATOR_H_

//#include "Physics/NuclearState/NuclearModelI.h"
#include "Physics/Common/KineGeneratorWithCache.h"
//#include "Physics/QuasiElastic/XSection/XyzzyUtils.h"
#include "Framework/Utils/Range1.h"
#include "Framework/Conventions/Controls.h"

namespace genie {

class XyzzyEventGenerator: public KineGeneratorWithCache {

public :
  XyzzyEventGenerator();
  XyzzyEventGenerator(string config);
 ~XyzzyEventGenerator();

  // implement the EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

  // overload the Algorithm::Configure() methods to load private data
  // members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

  mutable double fEb; // Binding energy

  void   LoadConfig     (void);
  double ComputeMaxXSec(const Interaction* in) const;

  void AddTargetNucleusRemnant (GHepRecord * evrec) const; ///< add a recoiled nucleus remnant

  //rwh // const NuclearModelI *  fNuclModel;   ///< nuclear model

  mutable double fMinAngleEM;

  /// Enum that indicates which approach should be used to handle the binding
  /// energy of the struck nucleon
  //rwh // XyzzyEvGen_BindingMode_t fHitNucleonBindingMode;

  /// The number of nucleons to sample from the nuclear model when choosing a maximum
  /// momentum to use in ComputeMaxXSec()
  int fMaxXSecNucleonThrows;

}; // class definition

} // genie namespace

#endif // _XYZZY_EVENT_GENERATOR_H_
